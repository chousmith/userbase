<?php
/**
 * @file
 * elite_general.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function elite_general_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'about';
  $context->description = '';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about' => 'about',
        'about/*' => 'about/*',
        'contact' => 'contact',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-about-section-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-about-section-menu',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
    'theme' => array(
      'title' => 'Policies',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('section');
  $export['about'] = $context;

  return $export;
}
