<?php
/**
 * @file
 * userbase_polls.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function userbase_polls_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'vote on polls'.
  $permissions['vote on polls'] = array(
    'name' => 'vote on polls',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'poll',
  );

  return $permissions;
}
