<?php
/**
 * @file
 * club_id.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function club_id_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function club_id_node_info() {
  $items = array(
    'club_id' => array(
      'name' => t('Club ID'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Club ID'),
      'help' => t('Please provide the Date of Visit, School, District, and subsequent "Club ID" code like "VID091415"'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
