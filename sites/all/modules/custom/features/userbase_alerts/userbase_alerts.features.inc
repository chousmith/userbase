<?php
/**
 * @file
 * userbase_alerts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function userbase_alerts_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function userbase_alerts_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function userbase_alerts_node_info() {
  $items = array(
    'alert' => array(
      'name' => t('Alert'),
      'base' => 'node_content',
      'description' => t('Alerts can show up on a spot on the Home page. And then?'),
      'has_title' => '1',
      'title_label' => t('Alert'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
