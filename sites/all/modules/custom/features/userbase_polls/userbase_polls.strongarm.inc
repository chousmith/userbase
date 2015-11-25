<?php
/**
 * @file
 * userbase_polls.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function userbase_polls_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_poll_pattern';
  $strongarm->value = 'polls/[node:title]';
  $export['pathauto_node_poll_pattern'] = $strongarm;

  return $export;
}
