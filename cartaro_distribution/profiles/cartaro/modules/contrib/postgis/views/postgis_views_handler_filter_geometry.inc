  <?php

  /**
   * @file
   * Definition of postgis_views_handler_filter_geometry.
   */

  /**
   * A handler to provide filter for geospatial data.
   * 
   * @author Friedjoff Trautwein <friedjoff.trautwein@geops.de>
   * @author Naveen Panwar <panwarnaveen9@gmail.com>
   * 
   */
class postgis_views_handler_filter_geometry extends views_handler_filter {

  var $no_operator = TRUE;

  // List of Spatial function supported in View Integration of PostGIS module.
  // Description at 
  // https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/wiki/List-of-spatial-functions
  var $operations = array(
    'ST_Contains', 'ST_Intersects', 'ST_Disjoint', 'ST_Covers', 'ST_Crosses', 'ST_Equals', 
    'ST_Touches', 'ST_Within', 'ST_Overlaps', 'ST_CoveredBy', 'ST_ContainsProperly',
    'ST_Area', 'ST_Azimuth', 'ST_Centroid', 'ST_HasArc', 'ST_Length', 'ST_Perimeter',
    '&&', '&&&', '&<', '&<|', '&>', '<<', '<<|', '=', '>>', '@', '|&>', '|>>', '~', '~=',
    );

  function option_definition() {

    $options = parent::option_definition();
    $options['operation'] = array('default' => 'ST_Contains');
    $options['origin'] = array('default' => 'operation');
    $options['value'] = array(
      'default' => array(
        'operation' => '',
        'comparison' => '',
        'existing_postgis_field_nid' => '',
        'geometry_A_wkt_data' => '',
      ),
    ); 
    return $options;
  }

  // In this function we develop the html components of users' form. 
  // Every input filed in this function is according Drupal Form API.
  function value_form(&$form, &$form_state) {

    // Getting the list of node ids which are related to different PostGIS filed.
    // Also categorized them according to it. 
    $all_postgis_fields_nids[''] = '';
    $nid_postgis_field_options = array();
    $fields = field_info_fields();
    foreach ($fields as $field) {
      if ($field['module'] == 'postgis') {
        $nid_postgis_field_options[$field['field_name']] = $field['field_name'];
        $query = new EntityFieldQuery();
        $entities = $query->entityCondition('entity_type', 'node')->fieldCondition($field['field_name'])->execute();
        $list_of_nids = array();
        $nodes = entity_load('node', array_keys($entities['node']));
        foreach($nodes as $single_node){
          $list_of_nids[$single_node->nid] = $single_node->title; 
        }
        $all_postgis_fields_nids[$field['field_name']] = $list_of_nids;
      }
    }

    // Categorized list of spatial function.
    // Detailed information at http://postgis.net/docs/manual-2.0/reference.html
    $form['value']['operation'] = array(
      '#type' => 'select',
      '#title' => t('Operation'),
      '#options' => array(
        
        'Spatial relationship' =>  array( 
        'ST_Contains' => t('Contains'), 
        'ST_Intersects' => t('Intersects'), 
        'ST_Disjoint' => t('Disjoint'),
        'ST_Covers' => t('Covers'),
        'ST_Crosses' => t('Crosses'),
        'ST_Equals' => t('Equals'),
        'ST_Touches' => t('Touches'),
        'ST_Within' => t('Within'),
        'ST_Overlaps' => t('Overlaps'), 
        'ST_CoveredBy' => t('CoveredBy'),
        'ST_ContainsProperly' => t('ContainsProperly'),
        ),

        'Spatial Operator' => array(
          '&&' => t('&&'),
          '&&&' => t('&&&'),
          '&<' => t('&<'),
          '&<|' => t('&<|'),
          '&>' => t('&>'),
          '<<' => t('<<'),
          '<<|' => t('<<'),
          '=' => t('='),
          '>>' => t('>>'),
          '@' => t('@'),
          '|&>' => t('|&>'),
          '|>>' => t('|>>'),
          '~' => t('~'),
          '~=' => t('~='),
          ),

        'Spatial Measurements' => array(
        'ST_Area' => t('Area'), 
        'ST_Azimuth' => t('Azimuth'),
        'ST_Centroid' => t('Centroid'), 
        'ST_HasArc' => t('HasArc'), 
        'ST_Length' => t('Length'), 
        'ST_Perimeter' => t('Perimeter'),
        ),

      ),
      '#description' => t('This will be the way the relationship is determined.'),
      '#default_value' => $this->options['value']['operation'] ? $this->options['value']['operation'] : 'ST_Contains',
    );

    // Comperision Operator applicable only for spatial measurement functions.
    // Want to make it visible only when user select spatial mesurement function in above drop down.
    // but not able to it.
    // For now developed in layman way.
    $form['value']['comparison'] = array(
      '#type' => 'select',
      '#title' => t('Comparison Operators'),
      '#options' => array(
          ''  => t(''),
          '=' => t('= (Equal)'),
          '<' => t('< (Less than)'),
          '>' => t('> (Greater than)'),
          '<=' => t('<= (Less and Equal)'),
          '>=' => t('>= (Greater and Equal)'),
        ),
      '#description' => t('Applicable only for Spatial Measurement functions. <br />Query like: Area > 100, Leave blank if not applicable.'),
      '#default_value' => t(''), 
    );
    
    // When user want to perform spatial function on existing geometry of any node.
    // Then he/she have to select that node.
    $form['value']['existing_postgis_field_nid'] = array(
      '#type' => 'select',
      '#title' => t('Select Node from existing PostGIS field'),
      '#options' => $all_postgis_fields_nids,
      '#default_value' => '',
      '#description' => t('Select node for spatial relations or operators. Leave blank if not applicable.'),
    );

    // When user want to enter geometry as input. (Only WKT/EWKT are valid)
    // Or comperision value for comperision operator. (Support avaiable, only for numeric data)
    $form['value']['geometry_A_wkt_data'] = array(
      '#type' => 'textarea',
      '#title' => t('Geometry A or Numeric Input'),
      '#description' => t('Provide the geometry in WKT format. Or numeric value for Spatial Measurements.'), 
      '#default_value' => t(''),
    );
  } 

  /**
   * Parent Class function defination:
   * Add this filter to the query.
   *
   * Due to the nature of fapi, the value and the operator have an unintended
   * level of indirection. You will find them in $this->operator
   * and $this->value respectively.
   */
  function query() {

    // Assign input form values to local variables.
    $operation = $this->options['value']['operation'];
    $geometry_A_wkt_data = $this->options['value']['geometry_A_wkt_data'];
    $Comparator = $this->options['value']['comparison'];

    // Check whether spatial operation value is empty or not.
    if (!in_array($this->options['value']['operation'], $this->operations)) {
      return;
    }

    // List of comperision operators. 
    // Need to validate users' input for the same.
    $Comparison_Operators = array(
          '=',
          '>',
          '<',
          '<=',
          '>=',
          );
    
    // List of measurement functions.
    // Need to validate users' input for the same.
    $Spatial_measurements_functions =  array(
        'ST_Area', 
        'ST_Azimuth', 
        'ST_Centroid', 
        'ST_HasArc', 
        'ST_Length', 
        'ST_Perimeter',
        );

    // List of Spatial operators 
    // Need to validate users' input for the same.
    $Spatial_operators = array(
      '&&', '&&&', 
      '&<', '&<|', '&>', 
      '<<', '<<|', '=', '>>', 
      '@', '|&>', '|>>', '~', '~=',
      );

    // Check whether users' selected operation is in measurement function or not.
    // "If" will fail if user select measurement operation
    if(!in_array($operation, $Spatial_measurements_functions)){

        // Check whether the geometry field is empty or not.
        $existing_postgis_field_nid = $this->options['value']['existing_postgis_field_nid'];
        if($existing_postgis_field_nid=='')
        {  

          // Check whether geometry input value is empty or not.
          if(empty($geometry_A_wkt_data)){
            return;
          }

          // Check the text before sending it to SQL for query
          // For now we are not developing this function. 
          if(!$this->check_wkt_data($geometry_A_wkt_data)){
              return;
          } 

          // Ensure whether the table and respective field exist in database or not.
          $this->ensure_my_table();    
          $field_name = db_escape_table($this->definition['field_name'] . '_geometry');
          $table_name = db_escape_table('field_data_' . $this->definition['field_name']);

          // Set default SRID of the geometric data.
          $WKT_srid = 4326;

          // Get the class object/instance of PostGIS geometry class.
          $WKT_raw_data = new postgis_Wkt($geometry_A_wkt_data);

          // Getting original geometry in WKT format.
          $WKT_wkt_data = $WKT_raw_data->getWktString();

          // Set the Actual SRID. If input data is in EWKT format.
          if($WKT_raw_data->hasSrid())
            $WKT_srid = $WKT_raw_data->getSrid();

          // "Validation Where" for geometric data validation.
          $validation_where = "ST_IsValid(ST_SetSRID(:wkt,$WKT_srid))";
          $this->query->add_where_expression($this->options['group'], $validation_where, $args = array(':wkt' => $WKT_wkt_data) );
          
          // Building query based on selected spatial operation
          if (!in_array($operation, $Spatial_operators)) {

            // Add query like ST_Contains(geom A, geom B). 
            $geometry_where = "$operation(ST_SetSRID(:wkt,$WKT_srid), $table_name.$field_name)";
            $this->query->add_where_expression($this->options['group'], $geometry_where, $args = array(':wkt' => $WKT_wkt_data) );
          }
          else{

            // Add query like (geom A ~ geom B).
            $operator_where = "ST_SetSRID(:wkt,$WKT_srid) $operation $table_name.$field_name";
            $this->query->add_where_expression($this->options['group'], $operator_where, $args = array(':wkt' => $WKT_wkt_data) );
          }
        }
        else
        {

          // Ensure whether the table and respective field exist in database or not.
          $this->ensure_my_table();    
          $field_name = db_escape_table($this->definition['field_name'] . '_geometry');
          $table_name = db_escape_table('field_data_' . $this->definition['field_name']);
          $existing_postgis_field_nid = $this->options['value']['existing_postgis_field_nid'];

          // To check whether user selected nid is in database or not.
          // We are getting the list of all nids related to PostGIS field.
          $fields = field_info_fields();
          $postgis_field_name  = '';
          $nid_found_flag = 0;
          foreach ($fields as $field) {
            if ($field['module'] == 'postgis') {
              $query = new EntityFieldQuery();
              $entities = $query->entityCondition('entity_type', 'node')->fieldCondition($field['field_name'])->execute();
              $list_of_nids = array();
              $nodes = entity_load('node', array_keys($entities['node']));
              foreach($nodes as $single_node){
                if($single_node->nid == $existing_postgis_field_nid)
                {
                  $nid_found_flag = 1;
                  $postgis_field_name = $field['field_name'] ;
                  break;
                }
              }
              if($nid_found_flag == 1)
                break;
            }
          }

          // Return, if selected nid is not in database.
          if($nid_found_flag == 0)
            return;

          // Ensure whether the table and respective field exist in database or not.
          $field_name_2 = db_escape_table($postgis_field_name . '_geometry');
          $table_name_2 = db_escape_table('field_data_' . $postgis_field_name);

          // Add the table of already exist PostGIS field to query. 
          $this->query->add_table($table_name_2, $relationship = NULL, $join = NULL, $alias = NULL);

          // Building query based on selected spatial operation
          if (!in_array($operation, $Spatial_operators)) {

            // Add query like ST_Contains(geom A, geom B). 
            $geometry_where = "$operation( ( select $field_name_2 from $table_name_2 where entity_id=:nid) , $table_name.$field_name)";
            $this->query->add_where_expression($this->options['group'], $geometry_where, $args = array(':nid' => $existing_postgis_field_nid) );
          }
          else{

            // Add query like (geom A ~ geom B). 
            $operator_where = "( select $field_name_2 from $table_name_2 where entity_id=:nid) $operation $table_name.$field_name"; 
            $this->query->add_where_expression($this->options['group'], $operator_where, $args = array(':nid' => $existing_postgis_field_nid) );
          }
        }
    }
    else{

      // Check whether user selected comperision operator exist in mentioned list or not.
      if (!in_array($Comparator, $Comparison_Operators)) {
      return;
      }

      // Convert the comperision value to numeric data. 
      $numeric_data = (float)$geometry_A_wkt_data;
      if(!is_numeric($numeric_data)){
            return;
      }

      // Ensure whether the table and respective field exist in database or not.
      $this->ensure_my_table();    
      $field_name = db_escape_table($this->definition['field_name'] . '_geometry');
      $table_name = db_escape_table('field_data_' . $this->definition['field_name']);

      // Building measurement query.
      // Query like "ST_area(select geom from table where nid=12132 ) > comperision_value"
      $measurement_query = $operation."(".$table_name.".".$field_name.") ".$Comparator. " ". $numeric_data ;       
      $this->query->add_where_expression($this->options['group'], $measurement_query, $args = array() );        
    }
  }

  /**
   * Parent Class function defination :
   * Check to see if input from the exposed filters should change
   * the behavior of this filter.
   */

  // Here we set users' input to class variable.
  // So that user can get the filtered output of exposed form.
  function accept_exposed_input($input) {

    if (!(isset($this->options['expose']) && isset($this->options['expose']['identifier']))) {
      return FALSE;
    }
    
    $this->options['value']['operation'] = $input['operation'];
    $this->options['value']['existing_postgis_field_nid'] = $input['existing_postgis_field_nid'];
    $this->options['value']['geometry_A_wkt_data'] = $input['geometry_A_wkt_data'];
    $this->options['value']['comparison'] = $input['comparison'];

    return TRUE;
  }

  /**
   * Parent Class function defination :
   * Display the filter on the administrative summary
   */
  function admin_summary() {

    if (!empty($this->options['exposed'])) {
      return t('exposed');
    }
    
    // If filter is exposed then we are mentioning the operator name in admin view.
    $output = t('Filter is applied on @operator operator.', array('@operator' => $this->options['value']['operation'])) ;
    return $output;
  }

  function check_wkt_data($geometry_A_wkt_data){
    
    // function description will be added soon.
    $pass_fail_flag=0;
    // on Success return 1; 
    return 1; 
  }
}
