**Weekly Report (13th July to 19th July) -**

***

**Aim** - Implement the spatial filter functions for the module.

**Things, I have done this week**

* Changed the input WKT data to geometry_A in operation function.

  `$geometry_where = "$operation(st_setsrid(:wkt,4326), $table_name.$field_name)";`
* Added a complex where clause to the query.

  `$this->query->add_where_expression($this->options['group'], $geometry_where, $args = array(':wkt' => $geometry_B_wkt_data) );`
* Completed the query function also successfully tested it for ST_Contains.
* Removed unnecessary lines from the code. 


**Cautions**
* We need to set the SRID as 4326 for input WKT geometry.

**Mentor Suggestions**
* 

**Things to do next week**
* Test the query function for the rem.

**Reference Modules/Files** - 
* [postgis_views_handler_filter_geometry.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/20964232f29365a6ff28f54c11b09244936f9eec/cartaro/profiles/cartaro/modules/contrib/postgis/views/postgis_views_handler_filter_geometry.inc) 

**Am I blocked on anything ?**

No.