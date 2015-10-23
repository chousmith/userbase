<?php
/**
 * @file
 * Alpha's theme implementation to display a single Drupal page.
 */
?>
<?php if (isset($page['pre_top'])) : ?>
<?php print render($page['pre_top']); ?>
<?php endif; ?>
<div<?php print $attributes; ?>>
  <?php if (isset($page['header'])) : ?>
    <?php print render($page['header']); ?>
  <?php endif; ?>
  <?php if (isset($section_title)): ?>
  <div class="section-title container-12">
      <?php print $section_title ?>
  </div>
  <?php endif; ?>

  <?php if (isset($page['content'])) : ?>
    <?php print render($page['content']); ?>
  <?php endif; ?>

  <?php if (isset($page['footer'])) : ?>
    <?php print render($page['footer']); ?>
  <?php endif; ?>
</div>