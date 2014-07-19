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
* Use psql or pgadmin to have a look at the cartaro database and find out how the postgis field tables are structured and named.
* Turn on the "Show the SQL query" setting under Structure > Views > Settings.

**Things to do next week**
* Test the query function for the remaining operations like: ST_Intersects, ST_Covers etc..
* Define the function "check_wkt_data()", as a part of error handling. 

**Reference Modules/Files** - 
* [postgis_views_handler_filter_geometry.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/20964232f29365a6ff28f54c11b09244936f9eec/cartaro/profiles/cartaro/modules/contrib/postgis/views/postgis_views_handler_filter_geometry.inc) 

**Am I blocked on anything ?**

No.