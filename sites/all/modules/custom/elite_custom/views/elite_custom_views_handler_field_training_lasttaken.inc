<?php
 
/**
 * A handler to display the last time a user completed a particular Training?
 *
 * @ingroup views_field_handlers
 */
class elite_custom_views_handler_field_training_lasttaken extends views_handler_field {
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
    
    // and our new defaults
    $options['training_nid'] = array('default' => '');
    
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
    
    // new field too
    $form['training_nid'] = array(
      '#type' => 'textfield',
      '#title' => t('Training NID'),
      '#default_value' => $this->options['training_nid'],
      '#description' => t('Training NID to query here.'),
      '#weight' => -10,
    );
  }
 
  /**
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */
  function render($values) {
    // shrug
    //watchdog('ech', '<pre>'. print_r($values,true) .'</pre>');
    $uid = ( isset( $values->uid ) ? $values->uid : 0 );
    $tnid = ( isset( $this->options['training_nid'] ) ? $this->options['training_nid'] : 0 );
    $op = 'elite_custom_quiz_finished';
    /*
    $t = format_date( time() );
    $oot = format_string( '<div>@user taken @training_nid = @time</div>', array(
      '@user' => $uid,
      '@training_nid' => $tnid,
      '@time' => $t
    ));
    */
    $query = 'SELECT time_stamp from {userpoints_txn} WHERE uid = :uid';
    $query .= ' AND entity_id = :tnid AND operation = :op';
    $tots = db_query( $query,
      array(
        ':uid' => $uid,
        ':tnid' => $tnid,
        ':op' => $op
      )
    )->fetchField();
    return $tots > 0 ? format_date( $tots, 'short' ) : '';
  }
}