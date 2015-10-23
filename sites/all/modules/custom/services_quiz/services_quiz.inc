<?php

/**
 * @file
 * Services integration for the quiz module.
 */

function services_quiz_data($data) {
  $content_id = $data['content_id'];
  $quiz = node_load($content_id);
  
  return _services_quiz_data($quiz);
}

function _services_quiz_data($quiz, $reset = FALSE) {
  if($reset) {
    $quiz = node_load($quiz->nid, $quiz->vid, TRUE);
  }
  
  return $quiz;
}

function services_quiz_eval_question($data) {
  //watchdog('sqeq 1', 'data : <pre>'. print_r($data,true) .'</pre>');
  global $user;
  $quiz_id = $data['quiz_id'];
  $question_id = $data['question_id'];
  $answer = array('answer' => $data['answer']);

  $quiz = node_load($quiz_id);
  $question = node_load($question_id);
  if (!isset($_SESSION['quiz_' . $quiz_id])) {
    _quiz_take_quiz_init($quiz);
	//watchdog('sqeq', 'quiz INIT : <pre>'. print_r($_SESSION['quiz_' . $quiz_id],true) .'</pre>');
  } else {
	//watchdog('sqeq', 'quiz already started : <pre>'. print_r($_SESSION['quiz_' . $quiz_id],true) .'</pre>');
  }
  $result_id = $_SESSION['quiz_' . $quiz_id]['result_id'];
	
	$quiz_all_questions = quiz_build_question_list($quiz);
	// the way the quiz module handles it with $_POSTs and sessions is willy wonk right now, so..
	/*
	if ( count( $_SESSION['quiz_' . $quiz_id]['quiz_questions'] ) + count( $_SESSION['quiz_' . $quiz_id]['previous_quiz_questions'] ) != count( $quiz_all_questions ) ) {
		// something went wrong??  re-init?
		$_SESSION['quiz_' . $quiz_id]['quiz_questions'] = $quiz_all_questions;
		
	}
	*/
	$i = -1;
	$question_array = false;
	foreach ( $quiz_all_questions as $k => $q ) {
		if ( $q['nid'] == $question_id ) {
			$i = $k;
			$question_array = $q;
		}
	}
	
	//watchdog('sqeq 12', 'result_id '. $result_id .' : question_id '. $question_id .' : all questions <pre>'. print_r($quiz_all_questions, true) .'</pre><br /><br />so question_array = <pre>'. print_r($question_array,true) .'</pre>');
	
	$result = new stdClass();
	if ( $question_array === false ) {
		$result->is_correct = 0;
		$result->is_valid = t('You must provide an answer');
	} else {
		$question_array['rid'] = $result_id;
		$former_question = node_load($question_array['nid'], $question_array['vid']);
		$types = _quiz_get_question_types();
    $module = $types[$former_question->type]['module'];
		
		$result = module_invoke($module, 'evaluate_question', $former_question, $result_id, $answer);
		
		//watchdog('sqeq 13', 'result: <pre>'. print_r($result,true) .'</pre><br /><br />question: <pre>'. print_r($question,true) .'</pre><br /><br />question_array: <pre>'. print_r($question_array,true) .'</pre>');
		
		if ( $result->is_valid === TRUE ) {
			quiz_store_question_result($quiz, $result, array('set_msg' => TRUE, 'question_data' => $question_array));
		}
	}
	/*
	
	$_SESSION['quiz_' . $quiz_id]['quiz_questions'][0]['rid'] = $result_id;
  $_SESSION['quiz_' . $quiz_id]['previous_quiz_questions'][] = $_SESSION['quiz_' . $quiz_id]['quiz_questions'][0];
	
  $question_array = array_shift($_SESSION['quiz_' . $quiz_id]['quiz_questions']);
	
	//$former_question_array = $question_array;
	//$former_question = node_load($former_question_array['nid'], $former_question_array['vid']);
	
	watchdog('sqeq 2', 'result_id '. $result_id .'? data : <pre>'. print_r($data,true) .'</pre><br /><br />question: <pre>'. print_r($question,true) .'</pre><br /><br />question_array: <pre>'. print_r($question_array,true) .'</pre><br /><br />user: <pre>'. print_r($user,true) .'</pre>');
	
	//$types = _quiz_get_question_types();
	//$module = $types[$former_question->type]['module'];
	
	//watchdog('sqeq 25', 'module '. $module .' =?= quiz_question');
	
  $result = module_invoke('quiz_question', 'evaluate_question', $question, $result_id);
	
	watchdog('sqeq 3', 'result : <pre>'. print_r($result,true) .'</pre><br /><br />question : <pre>'. print_r($question,true) .'</pre><br /><br />result_id : <pre>'. print_r($result_id,true) .'</pre><br /><br />answer : <pre>'. print_r($answer,true) .'</pre>');
	if ( $result->is_valid === TRUE ) {
  	quiz_store_question_result($quiz, $result, array('set_msg' => TRUE, 'question_data' => $question_array));
	}
	watchdog('sqeq 4', 'quiz : <pre>'. print_r($quiz,true) .'</pre><br /><br />result : <pre>'. print_r($result,true) .'</pre><br /><br />question_data : <pre>'. print_r($question_array,true) .'</pre>');
	
	
	if ($quiz->repeat_until_correct && $result->is_valid === TRUE) {
		// If the question was answered incorrectly, repeat it
		if ($result && !$result->is_correct && $result->is_evaluated) {
			$last_q = array_pop($_SESSION['quiz_' . $quiz_id]['previous_quiz_questions']);
			array_unshift($_SESSION['quiz_' . $quiz_id]['quiz_questions'], $last_q);
			//drupal_set_message(t('The answer was incorrect. Please try again.'), 'error');
			$repeat_until_correct_error = TRUE;
			unset($_SESSION['quiz_' . $quiz->nid]['feedback']);
		}
	}
	*/
	return $result;
}

/**
 * Service wrapper to vote on a quiz.
 *
 * @param $data
 *   An associative array containing POSTed arguments.
 *   - quiz_name: The quiz name.
 *   - content_id: The content ID to be voted on.
 *   - chid: The Choice ID selected by the user.
 *   - action: Optional. The desired method - quiz or unquiz. Defaults to quiz.
 *
 * @return
 *   $quiz
 *     a quiz object.
 */
function services_quiz_finalize($data) {
  global $user;
  $quiz_id = $data['quiz_id'];
  $quiz = node_load($quiz_id);

  $return = _services_quiz_finalize($quiz);
  if ($return !== FALSE) {
    return $return;
  } else {
    return services_error(t('There was a problem finalizing this quiz: @quiz_name', array('@quiz_name' => $quiz->title)), 406);
  }
}

function _services_quiz_finalize($quiz) {
  $questions = _quiz_get_answers($quiz, $_SESSION['quiz_' . $quiz->nid]['result_id']);
  $score = quiz_end_scoring($quiz, $_SESSION['quiz_' . $quiz->nid]['result_id']);
  $session_data = $_SESSION['quiz_' . $quiz->nid];
  //unset($_SESSION['quiz_' . $quiz->nid]);

	//watchdog('sq', 'quiz : <pre>'. print_r($quiz,true) .'</pre><br /><br />sess = <pre>'. print_r($session_data,true) .'</pre><br /><br />score: <pre>'. print_r($score, TRUE) .'</pre>');
  quiz_end_actions($quiz, $score, $session_data);

  $return = new stdClass();
  $return->score = $score;
  return $return;
}