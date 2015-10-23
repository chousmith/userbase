<?php

/**
 * @file
 * Services integration for the poll module.
 */

function services_poll_data($content_id) {
  $poll = node_load($content_id);
  
  return _services_poll_data($poll);
}

function _services_poll_data($poll, $reset = FALSE) {
  if($reset) {
    $poll = node_load($poll->nid, $poll->vid, TRUE);
  }
  $return = new stdClass();

  $return->nid = $poll->nid;
  $return->title = $poll->title;
  $return->choices = $poll->choice;
  $return->voted = services_poll_is_voted_on($poll->nid);
  $return->total_votes = services_poll_get_total_votes($poll->choice);

  foreach(module_implements('services_poll_data_fetch') as $module) {
    $function = $module . '_services_poll_data_fetch';
    $function($return);
  }
	
  return $return;
}

function services_poll_is_voted_on($content_id) {
  global $user;
  $vote = db_select('poll_vote', 'pv')
    ->fields('pv')
    ->condition('uid', $user->uid, '=')
    ->condition('nid', $content_id, '=')
    ->execute()
    ->fetchAssoc();

  if ($vote == NULL) {
    return FALSE;
  } else {
    return TRUE;
  }
}

function services_poll_get_total_votes($choices) {
  $vote_count = 0;
  foreach ($choices as $choice) {
    $vote_count += $choice['chvotes'];
  }

  return $vote_count;
}

/**
 * Service wrapper to vote on a poll.
 *
 * @param $data
 *   An associative array containing POSTed arguments.
 *   - poll_name: The poll name.
 *   - content_id: The content ID to be voted on.
 *   - chid: The Choice ID selected by the user.
 *   - action: Optional. The desired method - poll or unpoll. Defaults to poll.
 *
 * @return
 *   $poll
 *     a poll object.
 */
function services_poll_vote($data) {
  global $user;
  $poll = node_load($data['content_id']);
  $chid = $data['chid'];
  $uid = $user->uid;

  $return = _services_poll_vote($poll, $uid, $chid);
  if ($return !== TRUE) {
    return $return;
  }

  return _services_poll_data($poll, TRUE);
}

function _services_poll_vote($poll, $uid, $chid) {
  if (isset($poll) && isset($uid) && isset($chid)) {
    $choice = db_select('poll_choice', 'pc')
      ->fields('pc')
      ->condition('chid', $chid, '=')
      ->condition('nid', $poll->nid, '=')
      ->execute()
      ->fetchAssoc();

    if (!isset($choice)) {
      return services_error(t('Invalid choice'), 406);
    }
    
    if(!services_poll_is_voted_on($poll->nid)) {
      db_insert('poll_vote')
        ->fields(array(
          'nid' => $poll->nid,
          'chid' => $chid,
          'uid' => $uid,
          'hostname' => ip_address(),
          'timestamp' => REQUEST_TIME,
        ))
        ->execute();

      // Add one to the votes.
      db_update('poll_choice')
        ->expression('chvotes', 'chvotes + 1')
        ->condition('chid', $chid)
        ->execute();
  
      return TRUE;
    } else {
      return services_error(t('You\'ve already voted on this poll'), 406);
    }
  }
  return services_error(t('There was a problem voting on the poll: @poll_name', array('@poll_name' => $poll->title)), 406);
}