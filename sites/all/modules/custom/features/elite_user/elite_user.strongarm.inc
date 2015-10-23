<?php
/**
 * @file
 * elite_user.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function elite_user_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'session_expire_age';
  $strongarm->value = '172800';
  $export['session_expire_age'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'session_expire_interval';
  $strongarm->value = '86400';
  $export['session_expire_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'session_expire_mode';
  $strongarm->value = '1';
  $export['session_expire_mode'] = $strongarm;

  return $export;
}
