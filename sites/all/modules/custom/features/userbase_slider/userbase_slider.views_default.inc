<?php
/**
 * @file
 * userbase_slider.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function userbase_slider_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'home_slides';
  $view->description = 'Homepage top slides : Block';
  $view->tag = 'UserBase';
  $view->base_table = 'node';
  $view->human_name = 'Home Slides';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access Home section';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'nid' => 0,
    'field_image' => 0,
    'field_image_tablet_landscape' => 0,
    'field_image_tablet_portrait' => 0,
    'field_image_mobile' => 0,
    'title' => 0,
    'field_subheader' => 0,
    'field_slide_button' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['hide_on_single_slide'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 'title',
    'nid' => 0,
    'field_image' => 0,
    'field_image_tablet_landscape' => 0,
    'field_image_tablet_portrait' => 0,
    'field_image_mobile' => 0,
    'field_subheader' => 0,
    'field_slide_button' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['advanced_options'] = '{"containerResize":"0","fit":"1","height":"auto","width":"auto","slideResize":"0"}';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['label'] = 'slider queue';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['queues'] = array(
    'home_slider' => 'home_slider',
    'alerts' => 0,
    'featured_trainings' => 0,
    'trends' => 0,
    'whats_hot' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Subheader */
  $handler->display->display_options['fields']['field_subheader']['id'] = 'field_subheader';
  $handler->display->display_options['fields']['field_subheader']['table'] = 'field_data_field_subheader';
  $handler->display->display_options['fields']['field_subheader']['field'] = 'field_subheader';
  $handler->display->display_options['fields']['field_subheader']['label'] = '';
  $handler->display->display_options['fields']['field_subheader']['element_label_colon'] = FALSE;
  /* Field: Content: Slide Button */
  $handler->display->display_options['fields']['field_slide_button']['id'] = 'field_slide_button';
  $handler->display->display_options['fields']['field_slide_button']['table'] = 'field_data_field_slide_button';
  $handler->display->display_options['fields']['field_slide_button']['field'] = 'field_slide_button';
  $handler->display->display_options['fields']['field_slide_button']['label'] = '';
  $handler->display->display_options['fields']['field_slide_button']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slide_button']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_slide_button']['settings'] = array(
    'skip_safe' => 0,
    'skip_empty_values' => 0,
  );
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Tablet Landscape */
  $handler->display->display_options['fields']['field_image_tablet_landscape']['id'] = 'field_image_tablet_landscape';
  $handler->display->display_options['fields']['field_image_tablet_landscape']['table'] = 'field_data_field_image_tablet_landscape';
  $handler->display->display_options['fields']['field_image_tablet_landscape']['field'] = 'field_image_tablet_landscape';
  $handler->display->display_options['fields']['field_image_tablet_landscape']['label'] = '';
  $handler->display->display_options['fields']['field_image_tablet_landscape']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_tablet_landscape']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_tablet_landscape']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_tablet_landscape']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Tablet Portrait */
  $handler->display->display_options['fields']['field_image_tablet_portrait']['id'] = 'field_image_tablet_portrait';
  $handler->display->display_options['fields']['field_image_tablet_portrait']['table'] = 'field_data_field_image_tablet_portrait';
  $handler->display->display_options['fields']['field_image_tablet_portrait']['field'] = 'field_image_tablet_portrait';
  $handler->display->display_options['fields']['field_image_tablet_portrait']['label'] = '';
  $handler->display->display_options['fields']['field_image_tablet_portrait']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_tablet_portrait']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_tablet_portrait']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_tablet_portrait']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Mobile sized */
  $handler->display->display_options['fields']['field_image_mobile']['id'] = 'field_image_mobile';
  $handler->display->display_options['fields']['field_image_mobile']['table'] = 'field_data_field_image_mobile';
  $handler->display->display_options['fields']['field_image_mobile']['field'] = 'field_image_mobile';
  $handler->display->display_options['fields']['field_image_mobile']['label'] = '';
  $handler->display->display_options['fields']['field_image_mobile']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_mobile']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_mobile']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_mobile']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Region (field_region) */
  $handler->display->display_options['filters']['field_region_value']['id'] = 'field_region_value';
  $handler->display->display_options['filters']['field_region_value']['table'] = 'field_data_field_region';
  $handler->display->display_options['filters']['field_region_value']['field'] = 'field_region_value';
  $handler->display->display_options['filters']['field_region_value']['value'] = array(
    'us' => 'us',
  );
  $handler->display->display_options['filters']['field_region_value']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'promo_slide' => 'promo_slide',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['in_queue']['value'] = '1';
  $handler->display->display_options['filters']['in_queue']['group'] = 2;

  /* Display: Home Slides */
  $handler = $view->new_display('block', 'Home Slides', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Tablet Landscape */
  $handler->display->display_options['fields']['field_image_tablet_landscape']['id'] = 'field_image_tablet_landscape';
  $handler->display->display_options['fields']['field_image_tablet_landscape']['table'] = 'field_data_field_image_tablet_landscape';
  $handler->display->display_options['fields']['field_image_tablet_landscape']['field'] = 'field_image_tablet_landscape';
  $handler->display->display_options['fields']['field_image_tablet_landscape']['label'] = '';
  $handler->display->display_options['fields']['field_image_tablet_landscape']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_tablet_landscape']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_tablet_landscape']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_tablet_landscape']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Tablet Portrait */
  $handler->display->display_options['fields']['field_image_tablet_portrait']['id'] = 'field_image_tablet_portrait';
  $handler->display->display_options['fields']['field_image_tablet_portrait']['table'] = 'field_data_field_image_tablet_portrait';
  $handler->display->display_options['fields']['field_image_tablet_portrait']['field'] = 'field_image_tablet_portrait';
  $handler->display->display_options['fields']['field_image_tablet_portrait']['label'] = '';
  $handler->display->display_options['fields']['field_image_tablet_portrait']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_tablet_portrait']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_tablet_portrait']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_tablet_portrait']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Mobile sized */
  $handler->display->display_options['fields']['field_image_mobile']['id'] = 'field_image_mobile';
  $handler->display->display_options['fields']['field_image_mobile']['table'] = 'field_data_field_image_mobile';
  $handler->display->display_options['fields']['field_image_mobile']['field'] = 'field_image_mobile';
  $handler->display->display_options['fields']['field_image_mobile']['label'] = '';
  $handler->display->display_options['fields']['field_image_mobile']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_mobile']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_mobile']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_mobile']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Subheader */
  $handler->display->display_options['fields']['field_subheader']['id'] = 'field_subheader';
  $handler->display->display_options['fields']['field_subheader']['table'] = 'field_data_field_subheader';
  $handler->display->display_options['fields']['field_subheader']['field'] = 'field_subheader';
  $handler->display->display_options['fields']['field_subheader']['label'] = '';
  $handler->display->display_options['fields']['field_subheader']['element_label_colon'] = FALSE;
  /* Field: Content: Slide Button */
  $handler->display->display_options['fields']['field_slide_button']['id'] = 'field_slide_button';
  $handler->display->display_options['fields']['field_slide_button']['table'] = 'field_data_field_slide_button';
  $handler->display->display_options['fields']['field_slide_button']['field'] = 'field_slide_button';
  $handler->display->display_options['fields']['field_slide_button']['label'] = '';
  $handler->display->display_options['fields']['field_slide_button']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slide_button']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_slide_button']['settings'] = array(
    'skip_safe' => 0,
    'skip_empty_values' => 0,
  );
  $export['home_slides'] = $view;

  return $export;
}
