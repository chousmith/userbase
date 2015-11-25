<?php
/**
 * @file
 * userbase_tools.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function userbase_tools_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function userbase_tools_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function userbase_tools_image_default_styles() {
  $styles = array();

  // Exported image style: 260x172.
  $styles['260x172'] = array(
    'label' => '260x172',
    'effects' => array(
      27 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 260,
          'height' => 172,
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
function userbase_tools_node_info() {
  $items = array(
    'tool' => array(
      'name' => t('Tool'),
      'base' => 'node_content',
      'description' => t('<em>Tools</em> can be applications that should be promoted, PDFs, Videos, Off-site links, or basic details for helping users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
