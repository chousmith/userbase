<?php
/**
 * @file
 * userbase_users.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function userbase_users_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function userbase_users_image_default_styles() {
  $styles = array();

  // Exported image style: micro.
  $styles['micro'] = array(
    'label' => 'micro',
    'effects' => array(
      6 => array(
        'name' => 'imagecrop_reuse',
        'data' => array(
          'imagecrop_style' => 'rounduser',
        ),
        'weight' => 1,
      ),
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 34,
          'height' => 34,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      8 => NULL,
      9 => NULL,
      10 => NULL,
    ),
  );

  // Exported image style: rounduser.
  $styles['rounduser'] = array(
    'label' => 'rounduser',
    'effects' => array(
      1 => array(
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 140,
          'height' => 140,
          'xoffset' => 'center',
          'yoffset' => 'center',
          'resizable' => 1,
          'downscaling' => 1,
          'aspect_ratio' => 'CROP',
          'disable_if_no_data' => 1,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 140,
          'height' => 140,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      3 => NULL,
      4 => NULL,
      5 => NULL,
    ),
  );

  return $styles;
}
