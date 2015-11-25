<?php
/**
 * @file
 * userbase_trainings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function userbase_trainings_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access Trainings'.
  $permissions['access Trainings'] = array(
    'name' => 'access Trainings',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'userbase_custom',
  );

  return $permissions;
}
