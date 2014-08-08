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

    var $operations = array('ST_Contains', 'ST_Intersects', 'ST_Disjoint', 'ST_Covers', 'ST_Crosses', 'ST_Equals', 'ST_Touches', 'ST_Within', 'ST_Overlaps', 
      'ST_CoveredBy', 'ST_ContainsProperly',
      'ST_Area', 'ST_Azimuth', 'ST_Centroid', 'ST_HasArc', 'ST_Length', 'ST_Perimeter',
      '&&', '&&&', '&<', '&<|', '&>', '<<', '<<|', '=', '>>', '@', '|&>', '|>>', '~', '~=',
      );

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
      );

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
        '#description' => t('Applicable only for Spatial Measurement Operation. <br />Query like: Area > 100, Leave blank if not applicable.'),
        '#default_value' => t(''), 
      );

      $nid_postgis_field_options_2 = array();
      $nid_postgis_field_options_2[''] = '';
      $fields = field_info_fields();
      foreach ($fields as $field) {
        if ($field['module'] == 'postgis') {
          $nid_postgis_field_options_2[$field['field_name']] = $field['field_name'];
        }
      }

      $form['value']['existing_postgis_field'] = array(
        '#type' => 'select',
        '#title' => t('Existing PostGIS field'),
        '#options' => $nid_postgis_field_options_2,
        '#default_value' => $this->value['existing_postgis_field'],
        '#description' => t('Select which of the node\'s PostGIS field to use as the geometry B.<br />Leave blank if not applicable.'),
      );
      

      $list_of_nids = array();
      $list_of_nids[''] = '';
      $nodes =  entity_load( 'field_data_field_location', $ids = FALSE, $conditions = array(), $reset = FALSE);
      foreach($nodes as $products){
        $list_of_nids[$products->nid] = $products->title; 
      }
      
      $form['value']['existing_postgis_field_nid'] = array(
        '#type' => 'select',
        '#title' => t('Select Node'),
        '#options' => $list_of_nids,
        '#default_value' => '',
        '#description' => t('Select node for spatial operations.<br />Leave blank if not applicable.'),
      );

      $form['value']['geometry_B_wkt_data'] = array(
        '#type' => 'textarea',
        '#title' => t('Geometry B or Numeric Input'),
        '#description' => t('Provide the geometry in WKT format. Or numeric value for Spatial Measurements.'), 
        '#default_value' => t(''),
      );
    } 


    function query() {

      $operation = $this->options['value']['operation'];
      $geometry_B_wkt_data = $this->options['value']['geometry_B_wkt_data'];
      $Comparator = $this->options['value']['comparison'];

      if (!in_array($this->options['value']['operation'], $this->operations)) {
        return;
      }

      $Comparison_Operators = array(
            '=',
            '>',
            '<',
            '<=',
            '>=',
            );
      
      $Spatial_measurements_functions =  array(
          'ST_Area', 
          'ST_Azimuth', 
          'ST_Centroid', 
          'ST_HasArc', 
          'ST_Length', 
          'ST_Perimeter',
          );

      $Spatial_operators = array('&&', '&&&', '&<', '&<|', '&>', '<<', '<<|', '=', '>>', '@', '|&>', '|>>', '~', '~=',);

      if(!in_array($operation, $Spatial_measurements_functions)){
        // Check whether the geometry field is empty or not.
          $existing_postgis_field = $this->options['value']['existing_postgis_field'];
          if($existing_postgis_field=='')
          {  
            if(empty($geometry_B_wkt_data)){
              return;
            }

            // Check the text before sending it to SQL for query
            // For now we are not developing this. but this is necessary in term of user actully sending us data in WKT formate
            if(!$this->check_wkt_data($geometry_B_wkt_data)){
                return;
            } 

            $this->ensure_my_table();    
            $field_name = db_escape_table($this->options['value']['nid_postgis_field'] . '_geometry');
            $table_name = db_escape_table('field_data_' . $this->options['value']['nid_postgis_field']);

            $validation_where = "ST_IsValid(ST_SetSRID(:wkt,4326))";
            $this->query->add_where_expression($this->options['group'], $validation_where, $args = array(':wkt' => $geometry_B_wkt_data) );
            
            if (!in_array($operation, $Spatial_operators)) {
              $geometry_where = "$operation(ST_SetSRID(:wkt,4326), $table_name.$field_name)";
              $this->query->add_where_expression($this->options['group'], $geometry_where, $args = array(':wkt' => $geometry_B_wkt_data) );
            }
            else{
              $operator_where = "ST_SetSRID(:wkt,4326) $operation $table_name.$field_name";
              $this->query->add_where_expression($this->options['group'], $operator_where, $args = array(':wkt' => $geometry_B_wkt_data) );
            }
          }
          else
          {
            $this->ensure_my_table();    
            $field_name = db_escape_table($this->options['value']['nid_postgis_field'] . '_geometry');
            $table_name = db_escape_table('field_data_' . $this->options['value']['nid_postgis_field']);

            $field_name_2 = db_escape_table($this->options['value']['existing_postgis_field'] . '_geometry');
            $table_name_2 = db_escape_table('field_data_' . $this->options['value']['existing_postgis_field']);

            $this->query->add_table($table_name_2, $relationship = NULL, $join = NULL, $alias = NULL);
            
            if (!in_array($operation, $Spatial_operators)) {
              $geometry_where = "$operation($table_name_2.$field_name_2, $table_name.$field_name)";
              $this->query->add_where_expression($this->options['group'], $geometry_where, $args = array() );
            }
            else{
              $operator_where = ":wkt $operation $table_name.$field_name"; 
              $this->query->add_where_expression($this->options['group'], $operator_where, $args = array(':wkt' => $table_name_2.'.'.$field_name_2) );
            }
          }
      }
      else{

        if (!in_array($Comparator, $Comparison_Operators)) {
        return;
        }

        $numeric_data = (float)$geometry_B_wkt_data;

        if(!is_numeric($numeric_data)){
              return;
        }

        $this->ensure_my_table();    
        $field_name = db_escape_table($this->options['value']['nid_postgis_field'] . '_geometry');
        $table_name = db_escape_table('field_data_' . $this->options['value']['nid_postgis_field']);

        $measurement_query = $operation."(".$table_name.".".$field_name.") ".$Comparator. " ". $numeric_data ;
        
        $this->query->add_where_expression($this->options['group'], $measurement_query, $args = array() );        

      }
    }

    function check_wkt_data($geometry_B_wkt_data){
      // function description will be added soon.
      $pass_fail_flag=0;
      return 1; // on Success return 1; 
    }

  }
