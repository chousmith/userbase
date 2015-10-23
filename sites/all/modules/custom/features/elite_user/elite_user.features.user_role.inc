<?php
/**
 * @file
 * elite_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function elite_user_user_default_roles() {
  $roles = array();

  // Exported role: faculty.
  $roles['faculty'] = array(
    'name' => 'faculty',
    'weight' => 9,
  );

  // Exported role: student.
  $roles['student'] = array(
    'name' => 'student',
    'weight' => 4,
  );

  // Exported role: teacher.
  $roles['teacher'] = array(
    'name' => 'teacher',
    'weight' => 7,
  );

  // Exported role: under13.
  $roles['under13'] = array(
    'name' => 'under13',
    'weight' => 5,
  );

  // Exported role: verified.
  $roles['verified'] = array(
    'name' => 'verified',
    'weight' => 6,
  );

  return $roles;
}
