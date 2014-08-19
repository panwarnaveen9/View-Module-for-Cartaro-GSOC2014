## PostGIS View Implementation and Structure

View integration for geometry data in PostGIS module are developed in [views folder](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/tree/master/postgis_module/views). 

### **postgis/views/**
  * [`postgis.views.inc`](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/master/postgis_module/views/postgis.views.inc) - Set custom filter handler for PostGIS fields or Geometry data. <br />There are no changes required in this file in order to develop filters.
  * [`postgis_views_handler_filter_geometry.inc`](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/master/postgis_module/views/postgis_views_handler_filter_geometry.inc) -  A handler to provide filter for geospatial data. <br />All the required changes regarding the spatial query filter are need to develop in this file.

### **postgis_views_handler_filter_geometry.inc**<br />
There are three major component/functions in this file. 
  * **function value_form(&$form, &$form_state)** - In this function we develop the **html components of users' form**. Every thing written in this file is according [Drupal Form API](https://api.drupal.org/api/drupal/developer!topics!forms_api_reference.html/7).<br />
Example - Adding new text input field to form.
   1. **$form['value']['test_input']** = array(<br />
      '#type' => 'textfield',<br />
      '#title' => t('Title of input filed'),<br />
      '#description' => t('Provide some value for testing purpose.'), <br />
      '#default_value' => t(''),<br />
    );
<br />`Here "test_input" is form filed identifier. Means this input field referred by name 'test_input'.` 
  
  * **function accept_exposed_input($input)** - This function need to develop in order to enable users to expose the filter functionality. We set the users' input values to some class variables which can further use by different functions. Also in this function we can perform the different types check to ensure correctness of users' inputs. <br />
Example - <br />
   1. `$this->options['value']['test_input'] = $input['test_input'];` 
<br />
Here we set users' value of filed `test_input` to class variable $this-option['value']['test_input']. For now on whenever we want to access the users' data of this field, we use this particular variable. <br /><br />
We can also write logic whether we are accepting users' input data or not.

   2. `if(is_numeric($input['age']))`<br />
 `$this->options['value']['age'] = $input['age'];`<br />
`else`<br />
`return;`<br />
Here we are checking whether value provided in age field is numeric or not.

* **function query()** - This is very important function. In this function we decide what query is going run on PostGIS database. Also we write the logic, about how are we building the query. Which functions are we supposed to use or not. For different types of user input we need to develop different type of query.
<br />
All the functions, which we expose while building query are define in [views_plugin_query_default.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/master/cartaro_distribution/profiles/cartaro/modules/contrib/views/plugins/views_plugin_query_default.inc) 
<br /><br />
Example - We want add filter with spatialship relation function "contain" on two geometry. <br /><br />
   1. `$query_string = "ST_Contains(:wkt, $table_name.$field_name)";`<br />
`$this->query->add_where_expression($this->options['group'], $query_string, $args = array(':wkt' => $user_input_wkt_data) );`
<br /><br />
Here we are applying spatial filter, whether users' input geometry contain the geometry exist in particular table or not.

  2. It is recommended that we should ensure the tables before executing the query.<br /><br />
`$this->ensure_my_table();`


### Other important functions 

* **function option_definition()** - Use to setup all default options like: required, identifier, operator etc..

* **function admin_summary()** - Use to customize admin information regarding the filter. Whether filter is expose to user or not, if no then what are all the parameter admin has set during creation of filter.