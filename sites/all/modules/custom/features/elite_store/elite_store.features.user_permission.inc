<?php
/**
 * @file
 * elite_store.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function elite_store_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create store content'.
  $permissions['create store content'] = array(
    'name' => 'create store content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own store content'.
  $permissions['edit own store content'] = array(
    'name' => 'edit own store content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
