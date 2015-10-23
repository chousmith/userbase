<?php
/**
 * @file
 * elite_store.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function elite_store_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function elite_store_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function elite_store_node_info() {
  $items = array(
    'store' => array(
      'name' => t('Store'),
      'base' => 'node_content',
      'description' => t('use this for adding a store that has managers and employees.'),
      'has_title' => '1',
      'title_label' => t('Store Name'),
      'help' => '',
    ),
  );
  return $items;
}
