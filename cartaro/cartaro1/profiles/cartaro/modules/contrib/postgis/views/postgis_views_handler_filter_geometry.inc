<?php

/**
 * @file
 * Definition of postgis_views_handler_filter_geometry.
 */

/**
 * A handler to provide filter for geospatial data.
 */
class postgis_views_handler_filter_geometry extends views_handler_filter {

  var $no_operator = TRUE;

  /*var $operations = array('ST_Contains', 'ST_Intersects', 'ST_Disjoint');*/

  var $operations = array('ST_Contains', 'ST_Intersects', 'ST_Disjoint', 'ST_Covers', 'ST_Equals', 'ST_Touches', 'ST_Within', 'ST_Overlaps' );

  function option_definition() {

    $options = parent::option_definition();
    $options['operation'] = array('default' => 'ST_Contains');
    $options['origin'] = array('default' => 'nid_arg');
    $options['value'] = array(
      'default' => array(
        'nid_arg' => '',
        'nid_postgis_field' => '',
        'geometry_B_wkt_data' => '',
      ),
    );

    return $options;
  }

  function value_form(&$form, &$form_state) {

    $form['operation'] = array(
      '#type' => 'select',
      '#title' => t('Operation'),
      '#options' => array(
        'ST_Contains' => t('Contains'), 
        'ST_Intersects' => t('Intersects'), 
        'ST_Disjoint' => t('Disjoint'),
        'ST_Covers' => t('Covers'),
        'ST_Equals' => t('Equals'),
        'ST_Touches' => t('Touches'),
        'ST_Within' => t('Within'),
        'ST_Overlaps' => t('Overlaps'), 
      ),
      '#description' => t('This will be the way the relationship is determined.'),
      '#default_value' => $this->options['operation'] ? $this->options['operation'] : 'ST_Contains',
    );

    $form['value']['geometry_B_wkt_data'] = array(
      '#type' => 'textarea',
      '#title' => t('Geometry B'),
      '#description' => t('Provide the geometry in WKT format.'),
      '#default_value' => t(''),
      '#required' => TRUE,
    );

    // $form['origin'] = array(
    //   '#type' => 'select',
    //   '#title' => t('Origin'),
    //   '#options' => array(
    //     'nid_arg' => t('Node ID from contextual filter'),
    //   ),
    //   '#description' => t('This will be the way the geometry of origin is determined.'),
    //   '#default_value' => $this->options['origin'] ? $this->options['origin'] : 'nid_arg',
    // );

    // $nid_arg_options = array();
    // $arguments = $this->view->display_handler->get_handlers('argument');
    // foreach ($arguments as $id => $handler) {
    //   if ($handler->field == 'nid') {
    //     $nid_arg_options[$id] = $handler->ui_name();
    //   }
    // }

    // $form['value']['nid_arg'] = array(
    //   '#type' => 'select',
    //   '#title' => t('Contextual filter'),
    //   '#options' => $nid_arg_options,
    //   '#default_value' => $this->value['nid_arg'],
    //   '#description' => t('Select which of the contextual filters to use as the node ID.'),
    //   '#dependency' => array('edit-options-origin' => array('nid_arg')),
    //   '#weight' => 6,
    // );

    $nid_postgis_field_options = array();
    $fields = field_info_fields();
    foreach ($fields as $field) {
      if ($field['module'] == 'postgis') {
        $nid_postgis_field_options[$field['field_name']] = $field['field_name'];
      }
    }
    $form['value']['nid_postgis_field'] = array(
      '#type' => 'select',
      '#title' => t('PostGIS field'),
      '#options' => $nid_postgis_field_options,
      '#default_value' => $this->value['nid_postgis_field'],
      '#description' => t('Select which of the node\'s PostGIS field to use as the origin.'),
      '#dependency' => array('edit-options-origin' => array('nid_arg')),
      '#weight' => 7,
    );
  }

  function dvm($input, $name = NULL) {
    if (user_access('access devel information')) {
      $export = dprint_r($input, TRUE, $name, 'drupal_var_export', FALSE);
      drupal_set_message($export);
    }
    return $input;
  }

  function query() {

    //$nid_arg = $this->view->display_handler->get_handler('argument', $this->options['value']['nid_arg']);
    
    // if (empty($this->value) || empty($nid_arg) || !in_array($this->options['operation'], $this->operations)) {
    //   return;
    // }
    
    // #################### Data from value_form()

    $operation = $this->options['operation'];
    $geometry_B_wkt_data = $this->options['value']['geometry_B_wkt_data'];


    if (!in_array($this->options['operation'], $this->operations)) {
      return;
    }

    
    // Check whether the geometry field is empty or not.
    if(empty($geometry_B_wkt_data)){
      return;
    }

    // Check the text before sending it to SQL for query
    // For for we are not developing this. but this is necessary in term of user actully sending us data in WKT formate
    if(!check_wkt_data($geometry_B_wkt_data)){
      return;
    }


    $this->ensure_my_table();

    //$field_geometry = db_escape_table($this->definition['field_name'] . '_geometry');
    
    // Why do we need to append the string - (geometry) into field name. It already there  
    //$field_name = db_escape_table($this->options['value']['nid_postgis_field'] . '_geometry');
    
    $field_name = db_escape_table($this->options['value']['nid_postgis_field']);
    $table_name = db_escape_table('field_data_' . $this->options['value']['nid_postgis_field']);
    
    // $where = "$operation((select $field_name from $table_name where entity_id = :nid), $this->table_alias.$field_geometry)";
    // $this->query->add_where_expression($this->options['group'], $where, array(':nid' => $nid));

    // Need to ask what should I write here ? 
    
    $geometry_where = "$operation(($table_name.$field_name, $geometry_B_wkt_data)";
    $this->query->add_where_expression($this->options['group'], $geometry_where, $args = array() );

  }

  function check_wkt_data($geometry_B_wkt_data){
    // function description will be added soon.
    // on Success return 1; 
    $pass_fail_flag=0;
    return 1; // for now 
  }

}
