**Weekly Report (6th July to 12th July) -**

***

**Aim** - Implement the spatial filter functions for the module.

**Things, I have done this week**

* Added new "where" clause to query function for geometry B data.
* Removed unnecessary '_geomerty' from field_name string. 
* Removed all the depedancy related to nid and nid_arg from "query" function in [postgis_views_handler_filter_geometry.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/20964232f29365a6ff28f54c11b09244936f9eec/cartaro/profiles/cartaro/modules/contrib/postgis/views/postgis_views_handler_filter_geometry.inc) 


**Things to do next week**
* Boost up the work on filter module.
* Implement the original query and update the results

**Reference Modules/Files** - 
* [views_plugin_query_default.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/master/cartaro/profiles/cartaro/modules/contrib/views/plugins/views_plugin_query_default.inc)
* [postgis_views_handler_filter_geometry.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/20964232f29365a6ff28f54c11b09244936f9eec/cartaro/profiles/cartaro/modules/contrib/postgis/views/postgis_views_handler_filter_geometry.inc) 

**Am I blocked on anything ?**

No.