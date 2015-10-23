<?php
/**
 * @file
 * elite_user_regions.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function elite_user_regions_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_region'
  $field_instances['user-user-field_region'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_region',
    'label' => 'Region',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Region');

  return $field_instances;
}
