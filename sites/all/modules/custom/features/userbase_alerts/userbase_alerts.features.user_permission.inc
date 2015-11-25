<?php
/**
 * @file
 * userbase_alerts.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function userbase_alerts_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access Home section'.
  $permissions['access Home section'] = array(
    'name' => 'access Home section',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'elite_custom',
  );

  return $permissions;
}
