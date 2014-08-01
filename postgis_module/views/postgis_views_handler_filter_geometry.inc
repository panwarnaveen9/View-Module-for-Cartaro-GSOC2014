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
        '#dependency' => array('edit-options-origin' => array('nid_arg')),
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

          'Spatial Measurements' => array(
          'ST_Area' => t('Area'), 
          'ST_Azimuth' => t('Azimuth'),
          'ST_Centroid' => t('Centroid'), 
          'ST_HasArc' => t('HasArc'), 
          'ST_Length' => t('Length'), 
          'ST_Perimeter' => t('Perimeter'),
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

        ),
        '#description' => t('This will be the way the relationship is determined.'),
        '#default_value' => $this->options['value']['operation'] ? $this->options['value']['operation'] : 'ST_Contains',
      );

      $form['value']['geometry_B_wkt_data'] = array(
        '#type' => 'textarea',
        '#title' => t('Geometry B'),
        '#description' => t('Provide the geometry in WKT format.'),
        '#default_value' => t(''),
       // '#required' => TRUE,
      );
    }


    function query() {

      $operation = $this->options['value']['operation'];
      $geometry_B_wkt_data = $this->options['value']['geometry_B_wkt_data'];

      if (!in_array($this->options['value']['operation'], $this->operations)) {
        return;
      }
      
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
          $operator_where = "ST_SetSRID(:wkt,4326) ~ $table_name.$field_name";
          $this->query->add_where_expression($this->options['group'], $operator_where, $args = array(':wkt' => $geometry_B_wkt_data) );
        }
      }

      else{

        $this->ensure_my_table();    
        $field_name = db_escape_table($this->options['value']['nid_postgis_field'] . '_geometry');
        $table_name = db_escape_table('field_data_' . $this->options['value']['nid_postgis_field']);

        // Have to add new field here like ST_Area Example :
        //SELECT ST_Area(Field_name)  
        //FROM Table_name. 

        // I think we have to used compile_fields or add_field function 
        
        $measurement_query = $field_name; //'ST_Area(ST_SetSRID(:geom, 4326))';
        $this->query->add_field($table_name, $measurement_query, $alias = 'Area', $params = array());

        //$this->query->add_where_expression($this->options['group'], $measurement_query, $args = array(':geom' => $table_name.$field_name) );        

      }
    }

    function check_wkt_data($geometry_B_wkt_data){
      // function description will be added soon.
      $pass_fail_flag=0;
      return 1; // on Success return 1; 
    }

  }
