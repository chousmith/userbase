<?php $tag = $block->subject ? 'section' : 'div'; ?>
<<?php print $tag; ?><?php print $attributes; ?>>
  <div class="block-inner clearfix">
    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
    
    <div<?php print $content_attributes; ?>>
	  <?php if ($block->subject): ?>
      <h2><?php print t( check_plain( $block->subject ) ); ?></h2>
      <?php endif; ?>
      <?php print $content ?>
	  <div class="more-link"><a href="#"><?php print t('Coming Soon'); ?></a></div>
    </div>
  </div>
</<?php print $tag; ?>>