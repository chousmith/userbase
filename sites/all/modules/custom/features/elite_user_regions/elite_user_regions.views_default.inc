<?php
/**
 * @file
 * elite_user_regions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elite_user_regions_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'users';
  $view->description = 'List of users general info? : Services';
  $view->tag = 'elite';
  $view->base_table = 'users';
  $view->human_name = 'Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created_date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'email';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_user_name_first']['id'] = 'field_user_name_first';
  $handler->display->display_options['fields']['field_user_name_first']['table'] = 'field_data_field_user_name_first';
  $handler->display->display_options['fields']['field_user_name_first']['field'] = 'field_user_name_first';
  $handler->display->display_options['fields']['field_user_name_first']['label'] = 'first_name';
  $handler->display->display_options['fields']['field_user_name_first']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name_first']['type'] = 'services';
  $handler->display->display_options['fields']['field_user_name_first']['settings'] = array(
    'skip_safe' => 0,
    'skip_empty_values' => 0,
  );
  /* Field: User: Role: */
  $handler->display->display_options['fields']['field_user_job_type']['id'] = 'field_user_job_type';
  $handler->display->display_options['fields']['field_user_job_type']['table'] = 'field_data_field_user_job_type';
  $handler->display->display_options['fields']['field_user_job_type']['field'] = 'field_user_job_type';
  $handler->display->display_options['fields']['field_user_job_type']['label'] = 'job_type';
  $handler->display->display_options['fields']['field_user_job_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_job_type']['type'] = 'services';
  $handler->display->display_options['fields']['field_user_job_type']['settings'] = array(
    'skip_safe' => 0,
    'skip_empty_values' => 0,
  );
  /* Field: User: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'users';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['label'] = 'language';
  $handler->display->display_options['fields']['language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['language']['link_to_user'] = FALSE;
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['label'] = 'last_access';
  $handler->display->display_options['fields']['access']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['access']['date_format'] = 'long';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['label'] = 'last_login';
  $handler->display->display_options['fields']['login']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['login']['date_format'] = 'long';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_user_name_last']['id'] = 'field_user_name_last';
  $handler->display->display_options['fields']['field_user_name_last']['table'] = 'field_data_field_user_name_last';
  $handler->display->display_options['fields']['field_user_name_last']['field'] = 'field_user_name_last';
  $handler->display->display_options['fields']['field_user_name_last']['label'] = 'last_name';
  $handler->display->display_options['fields']['field_user_name_last']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name_last']['type'] = 'services';
  $handler->display->display_options['fields']['field_user_name_last']['settings'] = array(
    'skip_safe' => 0,
    'skip_empty_values' => 0,
  );
  /* Field: User: Phone Number */
  $handler->display->display_options['fields']['field_user_phone']['id'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['table'] = 'field_data_field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['field'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['label'] = 'phone_number';
  $handler->display->display_options['fields']['field_user_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_phone']['type'] = 'services';
  $handler->display->display_options['fields']['field_user_phone']['settings'] = array(
    'skip_safe' => 0,
    'skip_empty_values' => 0,
  );
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = 'picture';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  /* Field: User: Store Name */
  $handler->display->display_options['fields']['field_user_location']['id'] = 'field_user_location';
  $handler->display->display_options['fields']['field_user_location']['table'] = 'field_data_field_user_location';
  $handler->display->display_options['fields']['field_user_location']['field'] = 'field_user_location';
  $handler->display->display_options['fields']['field_user_location']['label'] = 'store_name';
  $handler->display->display_options['fields']['field_user_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_location']['settings'] = array(
    'link' => 0,
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'uid';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['path'] = 'users';
  $translatables['users'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('created_date'),
    t('email'),
    t('first_name'),
    t('job_type'),
    t('language'),
    t('last_access'),
    t('last_login'),
    t('last_name'),
    t('phone_number'),
    t('picture'),
    t('store_name'),
    t('uid'),
    t('Services'),
  );
  $export['users'] = $view;

  $view = new view();
  $view->name = 'users_by_region';
  $view->description = 'Admin page to list all Users from a given Region';
  $view->tag = 'elite, admin';
  $view->base_table = 'users';
  $view->human_name = 'Users by Region';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Users by Region';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_storeid' => 'field_storeid',
    'field_store_area' => 'field_store_area',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_storeid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_store_area' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_store_employees_node']['id'] = 'reverse_field_store_employees_node';
  $handler->display->display_options['relationships']['reverse_field_store_employees_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_store_employees_node']['field'] = 'reverse_field_store_employees_node';
  $handler->display->display_options['relationships']['reverse_field_store_employees_node']['label'] = 'Store';
  $handler->display->display_options['relationships']['reverse_field_store_employees_node']['required'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Store ID */
  $handler->display->display_options['fields']['field_storeid']['id'] = 'field_storeid';
  $handler->display->display_options['fields']['field_storeid']['table'] = 'field_data_field_storeid';
  $handler->display->display_options['fields']['field_storeid']['field'] = 'field_storeid';
  $handler->display->display_options['fields']['field_storeid']['relationship'] = 'reverse_field_store_employees_node';
  $handler->display->display_options['fields']['field_storeid']['type'] = 'title_linked';
  $handler->display->display_options['fields']['field_storeid']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Content: Area */
  $handler->display->display_options['fields']['field_store_area']['id'] = 'field_store_area';
  $handler->display->display_options['fields']['field_store_area']['table'] = 'field_data_field_store_area';
  $handler->display->display_options['fields']['field_store_area']['field'] = 'field_store_area';
  $handler->display->display_options['fields']['field_store_area']['relationship'] = 'reverse_field_store_employees_node';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Region (field_region) */
  $handler->display->display_options['arguments']['field_region_value']['id'] = 'field_region_value';
  $handler->display->display_options['arguments']['field_region_value']['table'] = 'field_data_field_region';
  $handler->display->display_options['arguments']['field_region_value']['field'] = 'field_region_value';
  $handler->display->display_options['arguments']['field_region_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_region_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_region_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_region_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_region_value']['limit'] = '0';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/people/regions';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Regions';
  $handler->display->display_options['menu']['name'] = 'management';
  $translatables['users_by_region'] = array(
    t('Master'),
    t('Users by Region'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Store'),
    t('Username'),
    t('Store ID'),
    t('Area'),
    t('All'),
    t('Page'),
  );
  $export['users_by_region'] = $view;

  return $export;
}
