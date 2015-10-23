<?php

/**
 * Note :
 *
 * We have overloaded this field-image template
 * to handle displaying Videos in place of Images too
 * for Nodes that may have Video options on them
 * like Trainings and Trends / News..
 */

$vid = $vmp4 = $vwebm = '';
$showvid = '';
$vid_dir = '/sites/default/files/videos/';
$vid_suffix = '';
// update $vid_dir path if track_da_files
if ( function_exists( 'track_da_files_tracking' ) ) {
  $vid_dir = '/system/tdf/videos/';
  $vid_suffix = '/?file=1&type=node&id='. $element['#object']->nid;
}

if ( in_array($element['#object']->type, array('article','training','tool') ) ) {
	if ( is_array( $element['#object']->field_video_url ) ) {
  //watchdog('vid1', '<pre>'. print_r($element['#object']->field_video_url, true) .'</pre>');
		if ( isset( $element['#object']->field_video_url['und'] ) ) {
			if ( $element['#object']->field_video_url['und'][0]['url'] != '' ) {
				$vid = $element['#object']->field_video_url['und'][0]['url'];
				// it was only vimeo for starters..
				$vat = strpos($vid,'vimeo.com/');
				if ( $vat > 0 ) {
					$vid = substr($vid, $vat+10);
					$showvid = 'vimeo';
				} else {
          // but now lets check for yt too?
          // maybe like "https://youtu.be/Ar2yDlFrL7E?list=PLJMYVcY1wDqp6sJ2WYHOy8eFEvrhNFlz0"
          $vat = strpos($vid,'youtu.be/');
          if ( $vat > 0 ) {
            $vid = str_replace( 'youtu.be', 'www.youtube.com/embed', $vid );
            $showvid = 'youtube';
          } else {
            // also check for something more crazy like https://www.youtube.com/watch?v=Ar2yDlFrL7E&feature=youtu.be&list=PLJMYVcY1wDqp6sJ2WYHOy8eFEvrhNFlz0
            $vat = strpos( $vid, 'youtube.com/watch' );
            if ( $vat > 0 ) {
              // need to convert to like https://www.youtube.com/embed/Ar2yDlFrL7E?list=PLJMYVcY1wDqp6sJ2WYHOy8eFEvrhNFlz0
              // change the first watch to embed/
              $vid = str_replace( 'watch', 'embed/', $vid );
              if ( isset( $element['#object']->field_video_url['und'][0]['query']['v'] ) ) {
                $vid .= $element['#object']->field_video_url['und'][0]['query']['v'];
                if ( isset( $element['#object']->field_video_url['und'][0]['query']['list'] ) ) {
                  $vid .= '?list='. $element['#object']->field_video_url['und'][0]['query']['list'];
                }
              }
              $showvid = 'youtube';
            }
          }
				}
			}
		}
	}
	$basepath = defined('ELITELOCAL') ? ELITELOCAL : '';
	if ( is_array( $element['#object']->field_video_file ) ) {
		if ( isset( $element['#object']->field_video_file['und'] ) ) {
			$vmp4 = $basepath . $vid_dir . $element['#object']->field_video_file['und'][0]['filename'] . $vid_suffix;
		}
	}
	if ( is_array( $element['#object']->field_video_webm ) ) {
		if ( isset( $element['#object']->field_video_webm['und'] ) ) {
			$vwebm = $basepath . $vid_dir . $element['#object']->field_video_webm['und'][0]['filename'] . $vid_suffix;
		}
	}
	if ( ( $vmp4 != '' ) || ( $vwebm != '' ) ) {
		$vid = ''; // use html5 instead
		$showvid = 'html5';
		drupal_add_js('//cdn.sublimevideo.net/js/brxysbmu.js', 'external');
	}
	
	if ( $element['#object']->type == 'tool' ) {
		// field_image can be MULTIPLE images, so grab the 1st one as the top left image, and the rest (or video) in gallery form..
		$firstimage = array_shift( $items );
		$firstattr = array_shift( $item_attributes );
		print '<div class="field-item tool-mainimg" '. $firstattr .'>'. render($firstimage) .'</div>';
	}
}
if ( $showvid !== '' ) {
	if ( $vid != '' ) {
		// falling back to VIMEO, but still check for local debugging :
		if ( defined('ELITELOCAL') ) {
			// lets just print the video html5 stuff here
			if ( is_array( $element['#object']->field_video_file ) ) {
				if ( isset( $element['#object']->field_video_file['und'] ) ) {
					$vmp4 = $basepath . $vid_dir . $element['#object']->field_video_file['und'][0]['filename'] . $vid_suffix;
				}
			}
		}
		if ( $vmp4 != '' ) {
			?>
	<video id="qvideo" controls width="800" height="450" poster="<?php echo $basepath .'/sites/default/files/'. ( $element['#object']->type == 'training' ? 'trainings/' : 'field/image/' ) . $element['#object']->field_image['und'][0]['filename'] ?>">
		<source src="<?php echo $vmp4 ?>" type="video/mp4" />
		Your device does not support HTML5 video.
	</video>
	<?php
		} else {
      switch ( $showvid ) {
        case 'vimeo':
          echo '<iframe id="qvideo" src="//player.vimeo.com/video/'. $vid .'?title=0&amp;byline=0&amp;portrait=0&amp;color=ffffff" width="100%" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>';
          break;
        case 'youtube':
          echo '<iframe width="560" height="315" src="'. $vid .'" frameborder="0" allowfullscreen class="youtubeplayer"></iframe>';
          break;
      }
		}
	} else {
		?>
	<video class="sublime" id="qvideo" controls width="800" height="450" poster="<?php echo $basepath .'/sites/default/files/'. ( $element['#object']->type == 'training' ? 'trainings/' : 'field/image/' ) . $element['#object']->field_image['und'][0]['filename'] ?>" data-uid="q-video-<?php echo $element['#object']->nid ?>" data-autoresize="fit" preload="none">
		<?php
			if ( $vmp4 != '' ) echo '<source src="'. $vmp4 .'" type="video/mp4" />' ."\n";
			if ( $vwebm != '' ) echo '<source src="'. $vwebm .'" type="video/webm" />' ."\n";
		?>
		Your device does not support HTML5 video.
	</video>
		<?php
	}
} else { ?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>&nbsp;</div>
  <?php endif; ?>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></div>
    <?php endforeach; ?>
  </div>
</div>
<?php } ?>