<?php
/**
 * @file
 * elite_trainings.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function elite_trainings_taxonomy_default_vocabularies() {
  return array(
    'training_group' => array(
      'name' => 'Training Group',
      'machine_name' => 'training_group',
      'description' => 'group Trainings into 4G Cert / 3G Cert / general / whatever',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'type' => array(
      'name' => 'Type',
      'machine_name' => 'type',
      'description' => 'Tags for content containing media types',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
