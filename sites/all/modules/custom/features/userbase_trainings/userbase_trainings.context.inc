<?php
/**
 * @file
 * userbase_trainings.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function userbase_trainings_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'trainings_menu_active';
  $context->description = '';
  $context->tag = 'section';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'training' => 'training',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        1 => 1,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:trainings',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('section');
  $export['trainings_menu_active'] = $context;

  return $export;
}
