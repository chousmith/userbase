<?php
/**
 * @file
 * elite_sliders.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function elite_sliders_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imagesizes|node|promo_slide|form';
  $field_group->group_name = 'group_imagesizes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promo_slide';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Other Image Sizes',
    'weight' => '4',
    'children' => array(
      0 => 'field_image_tablet_landscape',
      1 => 'field_image_tablet_portrait',
      2 => 'field_image_mobile',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Other Image Sizes',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-imagesizes field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_imagesizes|node|promo_slide|form'] = $field_group;

  return $export;
}
