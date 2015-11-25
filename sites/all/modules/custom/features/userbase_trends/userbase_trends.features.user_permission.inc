<?php
/**
 * @file
 * userbase_trends.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function userbase_trends_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access Trends'.
  $permissions['access Trends'] = array(
    'name' => 'access Trends',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'elite_custom',
  );

  return $permissions;
}
