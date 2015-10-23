<?php
/**
 * @file
 * elite_tools.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function elite_tools_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tooltop|node|tool|default';
  $field_group->group_name = 'group_tooltop';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tool Top',
    'weight' => '0',
    'children' => array(
      0 => 'field_rating',
      1 => 'field_external_link',
      2 => 'field_company',
      3 => 'title_field',
      4 => 'flag_favorites',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Tool Top',
      'instance_settings' => array(
        'classes' => 'group-tooltop field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'node_tool_full_group_tooltop',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_tooltop|node|tool|default'] = $field_group;

  return $export;
}
