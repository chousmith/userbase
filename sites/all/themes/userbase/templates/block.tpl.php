<?php $tag = $block->subject ? 'section' : 'div'; ?>
<<?php print $tag; ?><?php print $attributes; ?>>
  <div class="block-inner clearfix">
    <?php print render($title_prefix); ?>
    <?php if ($block->subject): ?>
      <h2<?php print $title_attributes; ?>><?php print t( check_plain( $block->subject ) ); ?></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    
    <div<?php print $content_attributes; ?>>
      <?php
	  switch( $block->bid ) {
		case 'block-4':
			print '<h1>'. t('Log In') .'</h1>';
			break;
		case 'block-5':
			print '<div id="forget-password-link">'. t( 'Forgot your <a href="@user-password">password</a>?', array( '@user-password' => '/user/password' ) ) .'</div>';
			break;
		case 'block-6':
			print '<h1>'. t('Request Password') .'</h1>';
			break;
		case 'block-7':
			print '<h1>'. t('Register') .'</h1>';
			break;
		default:
			print $content;
			break;
	  }
	  //watchdog('block check', '<pre>'. print_r($block,true) .'</pre>');
	  ?>
    </div>
  </div>
</<?php print $tag; ?>>