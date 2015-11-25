<?php
/**
 * @file
 * userbase_extras.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function userbase_extras_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function userbase_extras_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function userbase_extras_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favorites".
  $flags['favorites'] = array(
    'entity_type' => 'node',
    'title' => 'Favorites',
    'global' => 0,
    'types' => array(
      0 => 'article',
      1 => 'training',
    ),
    'flag_short' => 'Favorite',
    'flag_long' => '',
    'flag_message' => 'The [node:type] has been added to your Favorites',
    'unflag_short' => 'Unfavorite',
    'unflag_long' => '',
    'unflag_message' => 'The [node:type] has been removed from your Favorites',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 1,
    'api_version' => 3,
    'module' => 'userbase_extras',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
