<?php
/**
 * @file
 * userbase_extras.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function userbase_extras_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-training-field_related_content'.
  $field_instances['node-training-field_related_content'] = array(
    'bundle' => 'training',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_related_content',
    'label' => 'Related Content',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 14,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Related Content');

  return $field_instances;
}
