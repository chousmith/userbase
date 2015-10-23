<?php
/**
 * @file
 * elite_trainings.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function elite_trainings_default_rules_configuration() {
  $items = array();
  $items['rules_assign_points_based_on_quiz_answers'] = entity_import('rules_config', '{ "rules_assign_points_based_on_quiz_answers" : {
      "LABEL" : "Assign points based on quiz answers",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "ON" : { "quiz_question_eval" : [] },
      "DO" : []
    }
  }');
  return $items;
}
