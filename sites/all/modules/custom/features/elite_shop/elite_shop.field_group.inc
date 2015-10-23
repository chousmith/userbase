<?php
/**
 * @file
 * elite_shop.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function elite_shop_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_column|node|reward|default';
  $field_group->group_name = 'group_content_column';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'reward';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Column',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_reward_product',
      2 => 'title_field',
      3 => 'product:commerce_price',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content Column',
      'instance_settings' => array(
        'classes' => 'group-content field-group-div grid-4',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_content_column|node|reward|default'] = $field_group;

  return $export;
}
