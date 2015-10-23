<?php
/**
 * @file
 * elite_store.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function elite_store_user_default_roles() {
  $roles = array();

  // Exported role: manager.
  $roles['manager'] = array(
    'name' => 'manager',
    'weight' => 4,
  );

  // Exported role: validated.
  $roles['validated'] = array(
    'name' => 'validated',
    'weight' => 3,
  );

  return $roles;
}
