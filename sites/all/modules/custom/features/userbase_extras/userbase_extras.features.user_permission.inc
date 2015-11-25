<?php
/**
 * @file
 * userbase_extras.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function userbase_extras_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access My Favorites'.
  $permissions['access My Favorites'] = array(
    'name' => 'access My Favorites',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'elite_custom',
  );

  return $permissions;
}
