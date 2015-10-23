<?php
/**
 * @file
 * elite_content.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function elite_content_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'favorites';
  $context->description = '';
  $context->tag = 'section';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'favorites' => 'favorites',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'page-trends',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('section');
  $export['favorites'] = $context;

  return $export;
}
