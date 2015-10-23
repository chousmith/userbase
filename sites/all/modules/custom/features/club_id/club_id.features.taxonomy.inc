<?php
/**
 * @file
 * club_id.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function club_id_taxonomy_default_vocabularies() {
  return array(
    'districts' => array(
      'name' => 'School Districts',
      'machine_name' => 'districts',
      'description' => 'School Districts as separate Taxonomy terms for Autocomplete',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'schools' => array(
      'name' => 'Schools',
      'machine_name' => 'schools',
      'description' => 'Schools as Taxonomy terms for Autocomplete',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
