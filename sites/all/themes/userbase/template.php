<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */
 
function userbase_preprocess_views_view_responsive_grid(&$vars) {
	if ( isset( $vars['rows'] ) ) {
		$viewresults = $vars['view']->result;
		$count = 0;
		foreach ( $vars['rows'] as $i => $row ) {
			foreach ( $row as $j => $col ) {
				if ( isset( $viewresults[$count]->node_field_data_field_training_quiz_nid ) ) {
					if ( $viewresults[$count]->node_field_data_field_training_quiz_nid == 1 ) {
						// set in userbase_custom.module, userbase_custom_views_pre_render function
						$vars['rows'][$i][$j]['classes'] .= ' taken';
						$vars['rows'][$i][$j]['content'] = str_replace( 'views-field-field-base-points">', 'views-field-field-base-points"><span class="chk"></span>', $vars['rows'][$i][$j]['content'] );
					}
				}
				$count++;
			}
		}
		//watchdog('rowscheck', 'rows : <pre>'. print_r($vars['rows'],true) .'</pre><br />view results <pre>'. print_r($vars['view']->result,true) .'</pre>');
	}
}

// HOOL_preprocess_page
function userbase_preprocess_page( &$vars, $hook ) {
	if ( isset( $vars['node'] ) ) {
		$vars['theme_hook_suggestions'][] = 'page__'. str_replace('_', '--', $vars['node']->type);
		$vars['theme_hook_suggestions'][] = 'page__'. str_replace('_', '--', drupal_get_path_alias());
	}
	
	if ( !isset( $vars['page']['pre_top'] ) ) {
		$vars['page']['pre_top'] = array();
	}
}

function userbase_quiz_admin_summary($variables) {
  $quiz = $variables['quiz'];
  $questions = $variables['questions'];
  $score = $variables['score'];
  $summary = $variables['summary'];
  $rid = $variables['rid'];
  // To adjust the title uncomment and edit the line below:
  // drupal_set_title(check_plain($quiz->title));
  if (!$score['is_evaluated']) {
    drupal_set_message(t('This quiz has not been scored yet.'), 'warning');
  }
  // Display overall result.
  $output = '';
  $params = array('%num_correct' => $score['numeric_score'], '%question_count' => $score['possible_score']);
  $output .= '<div id="quiz_score_possible">' . t('This person got %num_correct of %question_count correct', $params) . '</div>' . "\n";
  //$output .= '<div id="quiz_score_percent">' . t('Total score: @score %', array('@score' => $score['percentage_score'])) . '</div>' . "\n";
	/*
  if (isset($summary['passfail'])) {
    $output .= '<div id="quiz_summary">' . check_markup($summary['passfail'], $quiz->body['und'][0]['format']) . '</div>' . "\n";
  }
  if (isset($summary['result'])) {
    $output .= '<div id="quiz_summary">' . check_markup($summary['result'], $quiz->body['und'][0]['format']) . '</div>' . "\n";
  }
	*/
  // Get the feedback for all questions.
  require_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'quiz') . '/quiz.pages.inc';
  $report_form = drupal_get_form('quiz_report_form', $questions, TRUE, TRUE, TRUE);
  $output .= drupal_render($report_form);
  return $output;
}

function userbase_quiz_take_summary($variables) {
  $quiz = $variables['quiz'];
  $questions = $variables['questions'];
  $score = $variables['score'];
  $summary = $variables['summary'];
  $rid =  $variables['rid'];
  // Set the title here so themers can adjust.
  drupal_set_title($quiz->title);

  // Display overall result.
  $output = '';
  if (!empty($score['possible_score'])) {
    if (!$score['is_evaluated']) {
      if (user_access('score taken quiz answer')) {
        $msg = t('Parts of this @quiz have not been evaluated yet. The score below is not final. <a class="self-score" href="!result_url">Click here</a> to give scores on your own.', array('@quiz' => QUIZ_NAME, '!result_url' => url('node/' . $quiz->nid . '/results/' . $rid)));
      }
      else {
        $msg = t('Parts of this @quiz have not been evaluated yet. The score below is not final.', array('@quiz' => QUIZ_NAME));
      }
      drupal_set_message($msg, 'warning');
    }
    $output .= '<div id="quiz_score_possible">' . t('You got %num_correct of %question_count questions correct', array('%num_correct' => $score['numeric_score'], '%question_count' => $score['possible_score'])) . '</div>' . "\n";
    //$output .= '<div id="quiz_score_percent">' . t('Your score: %score %', array('%score' => $score['percentage_score'])) . '</div>' . "\n";
  }
	/*
  if (isset($summary['passfail'])) {
    $output .= '<div id="quiz_summary">' . $summary['passfail'] . '</div>' . "\n";
  }
  if (isset($summary['result'])) {
    $output .= '<div id="quiz_summary">' . $summary['result'] . '</div>' . "\n";
  }
	*/
  // Get the feedback for all questions. These are included here to provide maximum flexibility for themers
  if ($quiz->display_feedback) {
    $form = drupal_get_form('quiz_report_form', $questions);
    $output .= drupal_render($form);
  }
  return $output;
}
/*
 * hook template_preprocess_field
 */
function userbase_preprocess_field(&$vars) {
	// here is one way to change it from "50 points" to "<strong>50</strong> points"...
	if ( $vars['element']['#field_name'] == 'field_base_points' ) {
    switch ( $vars['element']['#bundle'] ) {
      case 'article':
        if ( function_exists( 'userbase_custom_check_taken_content' ) ) {
          $nid = $vars['element']['#object']->nid;
          $taken = userbase_custom_check_taken_content( $vars['element']['#bundle'], $nid );
          //watchdog('fbpck', 'userbase_custom_check_taken_content( '. $vars['element']['#bundle'] .' , '. $nid .' ) = '. $taken .'<br /><br /><pre>'. print_r($vars['element'],true) .'</pre>' );
          if ( $taken === 1 ) {
            $vars['items'][0]['#markup'] = '<strong class="complete">'. t('Complete') .'</strong>';
            //watchdog('fbpck', '<pre>'. print_r($vars['element'], true) .'</pre>' );
          }
        }
        break;
      case 'training':
        if ( function_exists( 'userbase_custom_check_taken_content' ) ) {
          if ( isset( $vars['element']['#object']->field_training_quiz['und'][0]['target_id'] ) ) {
            $nid = $vars['element']['#object']->field_training_quiz['und'][0]['target_id'];
            
            $taken = userbase_custom_check_taken_content( $vars['element']['#bundle'], $nid );
            //watchdog('fbpck', 'userbase_custom_check_taken_content( '. $vars['element']['#bundle'] .' , '. $nid .' ) = '. $taken .'<br /><br /><pre>'. print_r($vars['element'],true) .'</pre>' );
            if ( $taken === 1 ) {
              $vars['items'][0]['#markup'] = '<strong class="complete">'. t('Complete') .'</strong>';
              //watchdog('fbpck', '<pre>'. print_r($vars['element'], true) .'</pre>' );
            } else {
              if ( function_exists( 'userbase_custom_check_required' ) ) {
                if ( userbase_custom_check_required( $vars['element']['#object'] ) ) {
                  $vars['items'][0]['#markup'] .= '<span class="required"></span>';
                }
              }
            }
          }
        }
        break;
      case 'poll':
        foreach ( $vars['items'] as $k => $v ) {
          $vars['items'][$k] = '<strong>'. $vars['element']['#items'][$k]['value'] .'</strong> '. t('points');
        }
        break;
    }
  }
}
/*
 * hook_html_head_alter
 * remove "X-Generator" header, via https://www.drupal.org/node/982034#comment-3758880
 */
function userbase_html_head_alter(&$head_elements) {
  unset($head_elements['system_meta_generator']);
}

/*
 * theme_quiz_get_user_results from quiz module quiz.pages.inc
 */
function userbase_quiz_get_user_results($variables) {
  global $language;
  $results = $variables['results'];
  $rows = array();
  
  // load user # from the URL /user/#/myresults to check required permissions..
  $uid = (int)arg(1);
  $account = user_load( $uid );
  watchdog('eqgur', $uid .' <pre>'. print_r($account,true) .'</pre> <pre>'. print_r($variables,true) .'</pre>');
  
  while (list($key, $result) = each($results)) {
    $interval = _quiz_format_duration($result['time_end'] - $result['time_start']);
    $passed = $result['score'] >= $result['pass_rate'];
    $grade = $passed ? t('Passed') : t('Failed');
    $passed_class = $passed ? 'quiz-passed' : 'quiz-failed';
    if (!is_numeric($result['score'])) {
      $score = t('In progress');
    }
    elseif (!$result['is_evaluated']) {
      $score = t('Not evaluated');
    }
    else {
      if (!empty($result['pass_rate']) && is_numeric($result['score'])) {
        $pre_score = '<span class = "' . $passed_class . '">';
        $post_score = ' %<br><em>' . $grade . '</em></span>';
      }
      else {
        $post_score = ' %';
      }
      $score = $pre_score . $result['score'] . $post_score;
    }
	// instead of linking to the Quiz and Quiz title, link to the Training for the Quiz?
	$quiz_title = l($result['title'], 'node/' . $result['nid']);
  $required = false;
	if ( function_exists( 'userbase_custom_quiz_training' ) ) {
		$tnode = userbase_custom_quiz_training( $result['nid'] );
    if ( $tnode ) {
      if ( $tnode->nid > 0 ) {
        $tnodetitle = $tnode->title;
        // check req
        $required = userbase_custom_check_required( $tnode, $uid, $account );
        // link to Training with title in correct language even?
        if ( $tnode->language != $language->language ) {
          $tlang = new stdClass();
          $tlang->language = $tnode->language;
          $quiz_title = l( $tnodetitle, 'node/' . $tnode->nid, array('prefix' => $tnode->language .'/', 'language' => $tlang ) );
        } else {
          $quiz_title = l( $tnodetitle, 'node/' . $tnode->nid ); //, array( 'language' => $tlang ) );
        }
      }
    }
  }
  
    $rows[] = array(
      'title'       => $quiz_title,
      'required'       => $required  ? t('Yes') : t('No'),
      'time_start'  => format_date($result['time_start'], 'short'),
      'time_end'    => ($result['time_end'] > 0) ? format_date($result['time_end'], 'short') : t('In Progress'),
      'duration'    => ($result['time_end'] > 0) ? $interval : '',
      'score'       => $score,
      //'evaluated'   => $result['is_evaluated'] ? t('Yes') : t('No'),
      'op'          => l(t('View answers'), 'user/quiz/' . $result['result_id'] . '/userresults'),
    );

  }

  if (empty($rows)) {
    return t('No @quiz results found.', array('@quiz' => QUIZ_NAME));
  }

  $header = array(
    t('Trainings'),
    t('Required'),
    t('Started'),
    t('Finished'),
    t('Duration'),
    t('Score'),
    //t('Evaluated'),
    t('Operation'),
  );

  $per_page = 10;
  // Initialise the pager
  $current_page = pager_default_initialize(count($rows), $per_page);
  // Split your list into page sized chunks
  $chunks = array_chunk($rows, $per_page, TRUE);
  // Show the appropriate items from the list
  $output = theme('table', array('header' => $header, 'rows' => $chunks[$current_page]));
  // Show the pager
  $output .= theme('pager', array('quantity',count($rows)));
  //$output .= '<p><em>' . t('@quizzes that are not evaluated may have a different score and grade once evaluated.', array('@quizzes' => QUIZ_NAME)) . '</em></p>';
  
  $counts = userbase_custom_user_training_count( $uid, false, true );
  
  //$comp_markup = '<div style="display:none"><pre>'. print_r($counts,true) .'</pre></div>';
  $comp_markup .= '<div class="user-completecount"><div class="completed-required"><h5>'. t('Required Completed') .'</h5>';
  $comp_markup .= '<span class="count">'. $counts['required']['complete'] .'</span>' .' / ';
  //$comp_markup .= '<progress value="'. $counts['required']['complete'] .'" max="'. $counts['required']['total'] .'"></progress>';
  $comp_markup .= '<span class="count">'. $counts['required']['total'] .'</span></div>';
  $comp_markup .= '<div class="completed-total"><h5>'. t('Total Completed') .'</h5>';
  $comp_markup .= '<span class="count">'. $counts['complete'] .'</span>' .' / ';
  //$comp_markup .= '<progress value="'. $counts['complete'] .'" max="'. $counts['total'] .'"></progress>';
  $comp_markup .= '<span class="count">'. $counts['total'] .'</span></div></div>';
  
  $output .= $comp_markup;
  
  return $output;
}
/*
 * theme_menu_local_task
 * to catch & remove user profile VIEW tab?
 */
function userbase_menu_local_task($variables) {
  $link = $variables['element']['#link'];
  //watchdog('q catch', 'userbase_menu_local_task : <pre>'. print_r($link,true) .'</pre>');
  $link_text = $link['title'];

  // catch to remove user profile VIEW tab?
  if ( $link['path'] == 'user/%/view' ) {
    return;
  }
  
  if (!empty($variables['element']['#active'])) {
    // Add text to indicate active tab for non-visual users.
    $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));
  }

  return '<li' . (!empty($variables['element']['#active']) ? ' class="active"' : '') . '>' . l($link_text, $link['href'], $link['localized_options']) . "</li>\n";
}

/**
 * template_preprocess_forum_submitted
 */
function elite_preprocess_forum_submitted(&$variables) {
  $userimg = '<span class="userimg">';
  if ( isset($variables['topic']->uid) ) {
    if ( function_exists('elite_custom_user_image') ) {
      $usr = user_load($variables['topic']->uid);
      $userimg .= elite_custom_user_image($usr,'micro');
    }
    // and change usernamehtml link
    // NOT to messages via here, for now at least
    //$usernamehtml = l( $variables['topic']->name, 'messages/new/'. $variables['topic']->uid );
    $usernamehtml = l( $variables['topic']->name, 'user/'. $variables['topic']->uid );
  } else {
    // dunno, this was default..
    $usernamehtml = theme('username', array('account' => $variables['topic']));
  }
  $userimg .= '</span>';
  
  // and then set variables for use in the templates
  $variables['author'] = isset($variables['topic']->uid) ? ( $userimg . $usernamehtml ) : '';
  $variables['time'] = isset($variables['topic']->created) ? format_interval(REQUEST_TIME - $variables['topic']->created) : '';
}
/**
 * hook theme_link to redirect /user/# links to /messages/new/# instead, no mo
 *
function userbase_link($variables) {
  // in 1 case, if we are linking to /user/# like /user/1531 , replace with /messages/new/1531 ..
  $url = check_plain( url( $variables['path'], $variables['options'] ) );
  if ( substr( $variables['path'] , 0, 5 ) === 'user/' ) {
    $slashes = explode( '/', $url );
    if ( count( $slashes ) === 3 ) {
      // check its an int..
      $suf = substr( $variables['path'], 5 );
      if ( is_numeric( $suf ) ) {
        $url = '/messages/new/' . $suf;
        //$uid = $suf;
      }
    }
  }
  return '<a href="' . $url . '"' . drupal_attributes($variables['options']['attributes']) . '>' . ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text'])) . '</a>';
}

/**
 * template_preprocess_user_profile
 */
function userbase_preprocess_user_profile(&$variables) {
  //$account = $variables['elements']['#account'];
  //watchdog('pre pro', '<pre>'. print_r($variables['user_profile'],true) .'</pre>');
  
  // clean User Points display a little
  if ( isset( $variables['user_profile']['userpoints'] ) ) {
    if ( isset( $variables['user_profile']['userpoints']['title'] ) ) {
      // overwrite the headline..
      $variables['user_profile']['userpoints']['title']['#markup'] = '<h3>'. t('Total Points') .'</h3>';
    }
    if ( isset( $variables['user_profile']['userpoints']['list'] ) ) {
      if ( isset( $variables['user_profile']['userpoints']['list']['#items'] ) ) {
        if ( isset( $variables['user_profile']['userpoints']['list']['#items'][0] ) ) {
          // remove category name..
          $colon = strpos( $variables['user_profile']['userpoints']['list']['#items'][0], ': ' );
          if ( $colon !== false ) {
            $variables['user_profile']['userpoints']['list']['#items'][0] = '<strong>'. substr( $variables['user_profile']['userpoints']['list']['#items'][0], $colon + 2 ) .'</strong> '. t('points');
          }
        }
      }
    }
  }
  
  // send this user a private message
  if ( isset( $variables['user_profile']['privatemsg_send_new_message'] ) ) {
    if ( isset( $variables['user_profile']['privatemsg_send_new_message']['#title'] ) ) {
      $variables['user_profile']['privatemsg_send_new_message']['#title'] = t('Send a Message');
    }
  }
}

/**
 * theme_quiz_progress
 *
 * @param $question_number
 *  The position of the current question in the sessions' array.
 * @param $num_of_question
 *  The number of questions for this quiz as returned by quiz_get_number_of_questions().
 * @return
 *  Themed html.
 *
 */
function userbase_quiz_progress($variables) {
  $question_number = $variables['question_number'];
  $num_of_question = $variables['num_questions'];
  // TODO Number of parameters in this theme funcion does not match number of parameters found in hook_theme.
  // Determine the percentage finished (not used, but left here for other implementations).
  //$progress = ($question_number*100)/$num_of_question;

  // Get the current question # by adding one.
  $current_question = $question_number + 1;

  if ($variables['allow_jumping']) {
    $current_question = theme('quiz_jumper', array('current' => $current_question, 'num_questions' => $num_of_question));
  }

  $output  = '';
  $output .= '<div id="quiz_progress">';
  if ( function_exists( 'userbase_custom_quiz_training' ) ) {
    $qnid = arg(1);
    //$output .= 'qnid '. $qnid .' ';
    $training = userbase_custom_quiz_training( $qnid );
    if ( $training ) {
      if ( $training->nid ) {
        //$output .= '<span style="display:none"><pre>'. print_r($training,true) .'</pre></span>';
        $output .= $training->title .' - ';
      }
    }
  }
  $output .= t('Question <span id="quiz-question-number">!x</span> of <span id="quiz-num-questions">@y</span>', array('!x' => $current_question, '@y' => $num_of_question));
  $output .= '</div>' . "\n";
  // Add div to be used by jQuery countdown
  if ($variables['time_limit']) {
    $output .= '<div class="countdown"></div>';
  }
  return $output;
}

// HOOK_preprocess_html
function userbase_preprocess_html(&$variables) {
  // Montserrat
  drupal_add_css('http://fonts.googleapis.com/css?family=Montserrat:400,700', array('type' => 'external'));
}

/**
 * hook_css_alter because somehow userbase name messes with alpha & omega order
 */
function userbase_css_alter( &$css ) {
  $orderfix = array(
    'sites/all/themes/omega/alpha/css/alpha-reset.css',
    'sites/all/themes/omega/omega/css/formalize.css',
    'sites/all/themes/omega/omega/css/omega-menu.css',
    'sites/all/themes/omega/omega/css/omega-forms.css',
    'sites/all/themes/userbase/css/grid/userbase/narrow/userbase-narrow-12.css',
    'sites/all/themes/userbase/css/grid/userbase/normal/userbase-normal-12.css',
    'sites/all/themes/userbase/css/grid/userbase/wide/userbase-wide-12.css',
    'sites/all/themes/userbase/css/global.css',
    'sites/all/themes/userbase/css/narrow.css',
    'sites/all/themes/userbase/css/normal.css',
    'sites/all/themes/userbase/css/wide.css',
    'sites/all/themes/userbase/whitelabel/jacuzzi/css/jacuzzi.css'
  );
  $reord = array();
  foreach ( $orderfix as $i => $gkey ) {
    $reord[$gkey] = $css[$gkey];
    unset($css[$gkey]);
    
    $reord[$gkey]['weight'] = $i - 2;
    $reord[$gkey]['every_page'] = 1;
  }
  
  $css = array_merge( $reord, $css );
  //watchdog('cssd', '<pre>'. print_r($css,true) .'</pre>');
}