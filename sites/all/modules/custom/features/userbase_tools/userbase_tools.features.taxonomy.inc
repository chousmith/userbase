<?php
/**
 * @file
 * userbase_tools.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function userbase_tools_taxonomy_default_vocabularies() {
  return array(
    'resource_category' => array(
      'name' => 'Resource Category',
      'machine_name' => 'resource_category',
      'description' => 'Tools / Downloads / Resources can be for 1 category or another',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
