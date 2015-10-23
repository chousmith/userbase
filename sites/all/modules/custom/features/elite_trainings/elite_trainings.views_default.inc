<?php
/**
 * @file
 * elite_trainings.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elite_trainings_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'quiz_training_blocks';
  $view->description = 'Helper block to share info between Trainings & Quizes screens : Blocks';
  $view->tag = 'elite';
  $view->base_table = 'node';
  $view->human_name = 'Quiz Training blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['relationship'] = 'reverse_field_training_quiz_node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_training_quiz_node']['id'] = 'reverse_field_training_quiz_node';
  $handler->display->display_options['relationships']['reverse_field_training_quiz_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_training_quiz_node']['field'] = 'reverse_field_training_quiz_node';
  $handler->display->display_options['relationships']['reverse_field_training_quiz_node']['label'] = 'Training referencing quiz';
  $handler->display->display_options['relationships']['reverse_field_training_quiz_node']['required'] = TRUE;
  /* Field: Content: HTML5 Training URL */
  $handler->display->display_options['fields']['field_wslash_training']['id'] = 'field_wslash_training';
  $handler->display->display_options['fields']['field_wslash_training']['table'] = 'field_data_field_wslash_training';
  $handler->display->display_options['fields']['field_wslash_training']['field'] = 'field_wslash_training';
  $handler->display->display_options['fields']['field_wslash_training']['relationship'] = 'reverse_field_training_quiz_node';
  $handler->display->display_options['fields']['field_wslash_training']['label'] = '';
  $handler->display->display_options['fields']['field_wslash_training']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wslash_training']['element_wrapper_class'] = 'field-name-field-wslash-training';
  $handler->display->display_options['fields']['field_wslash_training']['click_sort_column'] = 'url';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quiz' => 'quiz',
  );

  /* Display: Training Top Block */
  $handler = $view->new_display('block', 'Training Top Block', 'block');

  /* Display: Training Wslash Block */
  $handler = $view->new_display('block', 'Training Wslash Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['quiz_training_blocks'] = array(
    t('Master'),
    t('<none>'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Training referencing quiz'),
    t('All'),
    t('Training Top Block'),
    t('Training Wslash Block'),
  );
  $export['quiz_training_blocks'] = $view;

  $view = new view();
  $view->name = 'trainings';
  $view->description = 'Trainings homepage block + landing page : Block + Page';
  $view->tag = 'elite';
  $view->base_table = 'node';
  $view->human_name = 'Trainings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Featured Trainings';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access Trainings';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'responsive_grid';
  $handler->display->display_options['style_options']['column_classes'] = 'views-column grid-3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Flags: favorites */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'favorite';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'favorites';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['queues'] = array(
    'featured_trainings' => 'featured_trainings',
    'featured_trainings_uk' => 'featured_trainings_uk',
    'home_slider' => 0,
    'home_slider_uk' => 0,
    'shop_slides' => 0,
    'trainings_slides' => 0,
    'trends' => 0,
    'whats_hot' => 0,
    'whats_hot_uk' => 0,
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_training_quiz_target_id']['id'] = 'field_training_quiz_target_id';
  $handler->display->display_options['relationships']['field_training_quiz_target_id']['table'] = 'field_data_field_training_quiz';
  $handler->display->display_options['relationships']['field_training_quiz_target_id']['field'] = 'field_training_quiz_target_id';
  $handler->display->display_options['relationships']['field_training_quiz_target_id']['label'] = 'quiz';
  $handler->display->display_options['relationships']['field_training_quiz_target_id']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Background Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '260x146',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Rate this */
  $handler->display->display_options['fields']['field_rating']['id'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['table'] = 'field_data_field_rating';
  $handler->display->display_options['fields']['field_rating']['field'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['label'] = '';
  $handler->display->display_options['fields']['field_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rating']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_rating']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'sites/all/modules/contrib/fivestar/widgets/outline/outline.css',
    ),
    'expose' => 1,
    'style' => 'average',
    'text' => 'none',
  );
  /* Field: Content: Base Points */
  $handler->display->display_options['fields']['field_base_points']['id'] = 'field_base_points';
  $handler->display->display_options['fields']['field_base_points']['table'] = 'field_data_field_base_points';
  $handler->display->display_options['fields']['field_base_points']['field'] = 'field_base_points';
  $handler->display->display_options['fields']['field_base_points']['label'] = '';
  $handler->display->display_options['fields']['field_base_points']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_base_points']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Media Types */
  $handler->display->display_options['fields']['field_media_types']['id'] = 'field_media_types';
  $handler->display->display_options['fields']['field_media_types']['table'] = 'field_data_field_media_types';
  $handler->display->display_options['fields']['field_media_types']['field'] = 'field_media_types';
  $handler->display->display_options['fields']['field_media_types']['label'] = '';
  $handler->display->display_options['fields']['field_media_types']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'field_training_quiz_target_id';
  $handler->display->display_options['fields']['nid_1']['label'] = 'taken';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Sort criterion: Nodequeue: Position in nodequeue and other parameter */
  $handler->display->display_options['sorts']['position_and_other']['id'] = 'position_and_other';
  $handler->display->display_options['sorts']['position_and_other']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position_and_other']['field'] = 'position_and_other';
  $handler->display->display_options['sorts']['position_and_other']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position_and_other']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'training' => 'training',
  );
  /* Filter criterion: Content: Region (field_region) */
  $handler->display->display_options['filters']['field_region_value']['id'] = 'field_region_value';
  $handler->display->display_options['filters']['field_region_value']['table'] = 'field_data_field_region';
  $handler->display->display_options['filters']['field_region_value']['field'] = 'field_region_value';
  $handler->display->display_options['filters']['field_region_value']['value'] = array(
    'us' => 'us',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    21 => '21',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'training_group';

  /* Display: Block : Featured */
  $handler = $view->new_display('block', 'Block : Featured', 'block');
  $handler->display->display_options['display_description'] = 'Featured Trainings block, shown on the homepage';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'responsive_grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['column_classes'] = 'views-column grid-3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'polls:block';

  /* Display: Page : Trainings */
  $handler = $view->new_display('page', 'Page : Trainings', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Trainings';
  $handler->display->display_options['display_description'] = 'Trainings landing page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h1 id="page-title">Trainings</h1>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['path'] = 'trainings';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Trainings';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['trainings'] = array(
    t('Master'),
    t('Featured Trainings'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('favorite'),
    t('queue'),
    t('quiz'),
    t('taken'),
    t('Block : Featured'),
    t('Featured Trainings block, shown on the homepage'),
    t('Page : Trainings'),
    t('Trainings'),
    t('Trainings landing page'),
    t('<h1 id="page-title">Trainings</h1>'),
  );
  $export['trainings'] = $view;

  $view = new view();
  $view->name = 'trainings_quiz_service';
  $view->description = 'View of all the questions associated with a Training quiz : services';
  $view->tag = 'elite';
  $view->base_table = 'quiz_node_properties';
  $view->human_name = 'Trainings Quiz Service';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Questions by Quiz';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access quiz';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Quiz Questions: Quiz Node VID */
  $handler->display->display_options['relationships']['parent_vid']['id'] = 'parent_vid';
  $handler->display->display_options['relationships']['parent_vid']['table'] = 'quiz_node_relationship';
  $handler->display->display_options['relationships']['parent_vid']['field'] = 'parent_vid';
  $handler->display->display_options['relationships']['parent_vid']['label'] = 'node';
  $handler->display->display_options['relationships']['parent_vid']['required'] = TRUE;
  /* Relationship: Quiz Questions: Question Node VID */
  $handler->display->display_options['relationships']['child_vid']['id'] = 'child_vid';
  $handler->display->display_options['relationships']['child_vid']['table'] = 'quiz_node_relationship';
  $handler->display->display_options['relationships']['child_vid']['field'] = 'child_vid';
  $handler->display->display_options['relationships']['child_vid']['label'] = 'question node revision';
  /* Field: Quiz Questions: Question Node ID */
  $handler->display->display_options['fields']['child_nid']['id'] = 'child_nid';
  $handler->display->display_options['fields']['child_nid']['table'] = 'quiz_node_relationship';
  $handler->display->display_options['fields']['child_nid']['field'] = 'child_nid';
  $handler->display->display_options['fields']['child_nid']['label'] = 'question_id';
  $handler->display->display_options['fields']['child_nid']['separator'] = '';
  /* Field: Content (historical data): Body */
  $handler->display->display_options['fields']['body-revision_id']['id'] = 'body-revision_id';
  $handler->display->display_options['fields']['body-revision_id']['table'] = 'field_revision_body';
  $handler->display->display_options['fields']['body-revision_id']['field'] = 'body-revision_id';
  $handler->display->display_options['fields']['body-revision_id']['relationship'] = 'child_vid';
  $handler->display->display_options['fields']['body-revision_id']['label'] = 'question_title';
  $handler->display->display_options['fields']['body-revision_id']['type'] = 'text_plain';
  /* Field: Quiz Multichoice Answers: Answer */
  $handler->display->display_options['fields']['answer']['id'] = 'answer';
  $handler->display->display_options['fields']['answer']['table'] = 'quiz_multichoice_answers';
  $handler->display->display_options['fields']['answer']['field'] = 'answer';
  $handler->display->display_options['fields']['answer']['label'] = 'answer';
  /* Field: Quiz Multichoice Answers: Answer ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'quiz_multichoice_answers';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'answer_id';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Contextual filter: Quiz: Quiz Node NID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'quiz_node_properties';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Questions';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'if ( isset( $_GET[\'args\'] ) ) {
$args = $_GET[\'args\'];
if ( isset( $args[0] ) ) return $args[0];
}';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'quiz' => 'quiz',
  );

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['path'] = 'questions_quiz';
  $translatables['trainings_quiz_service'] = array(
    t('Master'),
    t('Questions by Quiz'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('node'),
    t('question node revision'),
    t('question_id'),
    t('.'),
    t('question_title'),
    t('answer'),
    t('answer_id'),
    t('All'),
    t('Questions'),
    t('Services'),
  );
  $export['trainings_quiz_service'] = $view;

  return $export;
}
