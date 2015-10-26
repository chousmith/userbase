<?php
/**
 * @file
 * elite_user.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function elite_user_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_first|user|user|default';
  $field_group->group_name = 'group_column_first';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Column First',
    'weight' => '0',
    'children' => array(
      0 => 'field_user_shipping',
      1 => 'field_user_job_type',
      2 => 'field_user_area',
      3 => 'group_name_first_last',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-column-first field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_column_first|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_second|user|user|default';
  $field_group->group_name = 'group_column_second';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Column Second',
    'weight' => '2',
    'children' => array(
      0 => 'privatemsg_send_new_message',
      1 => 'userpoints',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-column-second field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_column_second|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_name_first_last|user|user|default';
  $field_group->group_name = 'group_name_first_last';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_column_first';
  $field_group->data = array(
    'label' => 'Name:',
    'weight' => '1',
    'children' => array(
      0 => 'field_user_name_first',
      1 => 'field_user_name_last',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Name:',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_name_first_last|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal|user|user|default';
  $field_group->group_name = 'group_personal';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Info',
    'weight' => '3',
    'children' => array(
      0 => 'field_love_sony',
      1 => 'field_expertise',
      2 => 'field_interests_hobbies',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Personal Info',
      'instance_settings' => array(
        'classes' => 'group-personal',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $export['group_personal|user|user|default'] = $field_group;

  return $export;
}
