<?php
/**
 * @file
 * userbase_trends.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function userbase_trends_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'trends_menu_active';
  $context->description = '';
  $context->tag = 'section';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:trends',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('section');
  $export['trends_menu_active'] = $context;

  return $export;
}
