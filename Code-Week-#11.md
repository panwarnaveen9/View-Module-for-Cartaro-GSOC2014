**Weekly Report (27th July to 2nd August) -**

***

**Aim** - Implement the spatial filter functions for the module.

**Things, I have done this week**
* Completed the query for **Spatial Operators**
* Made the list of all functions which we are going to provide to user, as well as divide them into different categories based on inputs/outputs
* Wiki page - [List of spatial functions](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/wiki/List-of-spatial-functions)
* ~~Modified the query to add additional field in the select statement but couldn't figure out, how to get derived field value as results~~. 

**Mentor Suggestions**
* We will stay focused on filtering area and work on other means of geometry input for geometry B.
 For example, using the geometry from other nodes as input.

**Things to do next week**
* 


**Reference Modules/Files** - 
* Add Field - `$this->query->add_field($table_name, $field_name, $alias = '', $params = array());`
* [List of spatial functions](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/wiki/List-of-spatial-functions)
* [PostGIS Reference Manual](http://postgis.net/docs/manual-2.0/reference.html)
* [postgis_views_handler_filter_geometry.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/20964232f29365a6ff28f54c11b09244936f9eec/cartaro/profiles/cartaro/modules/contrib/postgis/views/postgis_views_handler_filter_geometry.inc) 

**Am I blocked on anything ?**

No.