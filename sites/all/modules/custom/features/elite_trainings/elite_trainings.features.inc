<?php
/**
 * @file
 * elite_trainings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function elite_trainings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function elite_trainings_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function elite_trainings_image_default_styles() {
  $styles = array();

  // Exported image style: 310x174.
  $styles['310x174'] = array(
    'label' => '310x174',
    'effects' => array(
      31 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 310,
          'height' => 174,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 604x339.
  $styles['604x339'] = array(
    'label' => '604x339',
    'effects' => array(
      30 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 604,
          'height' => 339,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function elite_trainings_node_info() {
  $items = array(
    'training' => array(
      'name' => t('Training'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('NOTE : Due to the integration of a "Quiz" at the end of each Training, it may be helpful to create the Quiz piece of content first, and then create the Training which ties to it.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
