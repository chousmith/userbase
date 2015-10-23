<?php
/**
 * Implements hook_permission() to define some new permissions
 */
function elite_custom_views_data_alter(&$data) {
  /*
  // This example adds an example field to the Users table.
  //watchdog('wha', '<pre>'. print_r($data['users'],true) .'</pre>');
  // old initial Logins Total handler
  $data['users']['login_total'] = array(
    'title' => t('Logins this month'),
    'help' => t('Number of login_tracker logins for the user, since the 1st of the month'),
    'field' => array(
      'handler' => 'elite_custom_views_handler_field_login_total',
    ),
  );
  */
  // user Training last taken?!
  $data['users']['training_lasttaken'] = array(
    'title' => t('Training Last Taken'),
    'help' => t('The last time the user Completed the given Training'),
    'field' => array(
      'handler' => 'elite_custom_views_handler_field_training_lasttaken',
    ),
  );
  // user Trainings Total..
  $data['users']['trainings_tot'] = array(
    'title' => t('Trainings Total'),
    'help' => t('Number of Total Trainings available to the user'),
    'field' => array(
      'handler' => 'elite_custom_views_handler_field_trainings_tot',
      //'click sortable' => 1,
    ),
    /*
    'sort' => array(
      'handler' => 'views_handler_sort_numeric'
    ),
    */
  );
  // user Trainings Completed..
  $data['users']['trainings_completed'] = array(
    'title' => t('Trainings Completed'),
    'help' => t('Number of Total Trainings completed by the user'),
    'field' => array(
      'handler' => 'elite_custom_views_handler_field_trainings_completed',
    ),
  );
  // user Required Total..
  $data['users']['required_total'] = array(
    'title' => t('Required Total'),
    'help' => t('Number of total Required Trainings available to the user'),
    'field' => array(
      'handler' => 'elite_custom_views_handler_field_required_total',
    ),
  );
  // user Required Completed..
  $data['users']['required_completed'] = array(
    'title' => t('Required Completed'),
    'help' => t('Number of total Required Trainings completed by the user'),
    'field' => array(
      'handler' => 'elite_custom_views_handler_field_required_completed',
    ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function elite_custom_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'elite_custom') . '/views',
    ),
    'handlers' => array(
      'elite_custom_views_handler_field_login_total' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'elite_custom_views_handler_field_training_lasttaken' => array(
        'parent' => 'views_handler_field',
      ),
      'elite_custom_views_handler_field_trainings_tot' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'elite_custom_views_handler_field_trainings_completed' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'elite_custom_views_handler_field_required_total' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'elite_custom_views_handler_field_required_completed' => array(
        'parent' => 'views_handler_field_numeric',
      ),
    ),
  );
}