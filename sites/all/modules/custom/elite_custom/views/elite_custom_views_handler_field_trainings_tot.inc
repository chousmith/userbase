<?php
 
/**
 * A handler to display user total # of trainings?
 *
 * @ingroup views_field_handlers
 */
class elite_custom_views_handler_field_trainings_tot extends views_handler_field_numeric {
  /**
   * {@inheritdoc}
   *
   * Perform any database or cache data retrieval here. In this example there is
   * none.
   */
  function query() {
	//watchdog('ecvh q', 'query here?!');
  }
  
  
  
  /**
   * {@inheritdoc}
   *
   * Modify any end user views settings here. Debug $options to view the field
   * settings you can change.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }
 
  /**
   * {@inheritdoc}
   *
   * Make changes to the field settings form seen by the end user when adding
   * your field.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
 
  /**
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */
  function render($values) {
    //watchdog('ecvh v', '<pre>'. print_r($values,true) .'</pre>');
    $num = 0;
    // shrug
    if ( isset ( $values->uid ) ) {
      $uid = $values->uid;
      $counts = elite_custom_user_training_count( $uid, false, true );
      if ( isset( $counts['total'] ) ) {
        $num = $counts['total'];
      }
    }
    return $num;
  }
}