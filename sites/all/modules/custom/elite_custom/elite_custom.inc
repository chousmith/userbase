<?php

function elite_custom_user_purchase($data) {
  global $user;
  $product_id = $data['product_id'];
  $shipping_data = $data['shipping_data'];
  if($product = commerce_product_load($product_id)) {
    $user_points = userpoints_get_current_points($user->uid);
    $product_points = $product->commerce_price[LANGUAGE_NONE][0]['amount'];
    if ($product->commerce_price[LANGUAGE_NONE][0]['amount'] == 'USD') {
      $product_points *= .1;
    }
    if ($user_points > $product_points) {
      $order = commerce_order_new($user->uid, 'pending');

      $product = commerce_product_load($product_id);
      $line_item = commerce_product_line_item_new($product, 1, $order->order_id, array());
      commerce_line_item_save($line_item);

      $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
      $order_wrapper->commerce_line_items[] = $line_item;

      $profile_data = commerce_customer_profile_new('shipping', $user->uid);
      $profile_data->commerce_customer_address = $shipping_data;
      commerce_customer_profile_save($profile_data);
      $profile_id = $profile_data->profile_id;
      $order->commerce_customer_shipping[LANGUAGE_NONE][0]['profile_id'] = $profile_id;
      
      commerce_order_save($order);

      userpoints_userpointsapi($product_points * -1);
      return 'Success';
    } else {
      return 'You do not have enough points for this transaction';
    }
  } else {
    return 'Invalid Product';
  }
  return 'There was an error processing this purchase';
}

function elite_custom_user_picture($data) {
  global $user;
  $fid = $data['fid'];
  
  $check = db_select('file_managed', 'fm')
    ->fields('fm')
    ->condition('fid', $fid, '=')
    ->condition('uid', $user->uid, '=')
    ->execute()
    ->fetchAssoc();

  if (!empty($check)) {
    $result = db_update('users')
      ->fields(array('picture' => $fid))
      ->condition('uid', $user->uid, '=')
      ->execute();
    
    if (!empty($result)) {
      $user = user_load($user->uid, TRUE);
      user_save($user);
      
      return 'Success';
    } 
  }
  return services_error('Could not find picture');
}

function elite_custom_services_imagecache($data) {
  $fid = $data['fid'];
  $style = $data['style'];

  $file = file_load($fid);
  $uri = image_style_url($style, $file->uri);

  $return = new stdClass();
  $return->path = $uri;

  return $return;
}

/**
 * callback for services /user/counts
 * #needswork
 * #todo :
 * i(alex) think we could just store ALL the Points / Favorites count / Completed Trainings & Completed Trends counts in fields in the USER object
 * since they dont get updated very often, and would be a way to CACHE and SAVE this result & improve performance?
 * 
 * returns
 * uid of current user
 * points total for current user
 * total + complete + remaining # for both Trainings & Trends
 */
function elite_custom_services_user_counts() {
	global $user;
	
	$return = new stdClass();
	if (!$user->uid) {
    // User is not logged in
    return services_error(t('User is not logged in.'), 406);
  } else {
		$uid = (int)$user->uid;
	
		$account = user_load($uid);
		$region = elite_custom_user_region();
		
		$trainings = elite_custom_user_training_count( $uid, $region, true );
		$trends = elite_custom_user_trend_count( $uid, $region, true );
		$points = (int)userpoints_get_current_points($uid);
		$favorites = (int)elite_custom_user_favorites_count();
		
		$return->uid = $uid;
		$return->points = $points;
		$return->trainings = $trainings;
		$return->trends = $trends;
		$return->favorites = $favorites;
	}
	return $return;
}

/**
 * callback for services /regions
 * 
 * returns
 * regions for registering peoples
 */
function elite_custom_services_regions() {
	$field = field_info_field('field_region');
	$values = list_allowed_values($field);
	
	//$return = new stdClass();
	$return = $values;
	
	return $return;
}
/**
 * callback for services /regions/verbose
 * 
 * returns
 * regions for registering peoples
 */
function elite_custom_services_regions_verbose() {
	return elite_custom_default_regions_list_verbose();
}
function _elite_custom_language_list_sort( $a, $b ) {
	return $a['weight'] - $b['weight'];
}
/**
 * callback for services /languages
 * 
 * returns
 * list of enabled languages
 */
function elite_custom_services_languages_list() {
	$oot = array();
	if ( function_exists('language_list') ) {
		$languages = language_list('enabled');
		if ( isset( $languages[1] ) ) {
			foreach ( $languages[1] as $l ) {
				$oot[] = array(
					'code' => $l->language,
					'name' => $l->name,
					'native' => $l->native,
					'weight' => $l->weight,
				);
			}
			usort( $oot, '_elite_custom_language_list_sort' );
		}
	}
	foreach ( $oot as $k => $v ) {
		if ( isset($v['weight']) ) unset( $oot[$k]['weight'] );
	}
	// and then append REGIONS list to it as well for simplifying calls
	$regions = elite_custom_default_regions_list_verbose();
	$oot = array(
		'languages' => $oot,
		'regions' => $regions,
	);
	
	return $oot;
}
/**
 * callback for services /terms
 * 
 * returns
 * Content from the About / Terms / Privacy pages all at once
 */
function elite_custom_services_terms() {
	$return = array();
	
	$pages = array(
		'about' => 'about',
		'privacy' => 'about/privacy-policy',
		'cookie' => 'about/cookie-policy',
		'terms' => 'about/terms-conditions',
	);
	foreach ( $pages as $k => $v ) {
		$path = drupal_lookup_path('source', $v);
		$node = menu_get_object('node', 1, $path);
		
		$return[$k] = new stdClass();
		if ( $node ) {
			$return[$k]->title = $node->title;
			$return[$k]->body = $node->body[LANGUAGE_NONE][0]['safe_value'];
		} else {
			$return[$k]->title = $k;
			$return[$k]->body = '<p>'. t('There appears to have been some kind of an error. Please contact the Site Administrators.') .'</p>';
		}
	}
	return $return;
}