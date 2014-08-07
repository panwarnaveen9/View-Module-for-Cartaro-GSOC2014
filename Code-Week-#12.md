**Weekly Report (3rd August to 9th August) -**

***

**Aim** - Implement the spatial filter functions for the module.

**Things, I have done this week**
* Completed the query for **Spatial Measurements**.
* Added comparison operators to support measurement query. 
* Added numeric data input with Geometry B text area.

**Comments**
* Faced error when I enable users to expose the filter module. Which is probably due to unset variable, will try to fix it ASAP.  

**Mentor Suggestions**
* Look into [node_load_multiple] (https://api.drupal.org/api/drupal/modules%21node%21node.module/function/node_load_multiple/7) function to get the list of all node ids. 
 
**Things to do next week**
* Testing for existing functionality.
* GSoC documentation, code cleaning and commenting 

**Reference Modules/Files** - 
* [views_handler_filter.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/master/cartaro_distribution/profiles/cartaro/modules/contrib/views/handlers/views_handler_filter.inc)
* [postgis_views_handler_filter_geometry.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/20964232f29365a6ff28f54c11b09244936f9eec/cartaro/profiles/cartaro/modules/contrib/postgis/views/postgis_views_handler_filter_geometry.inc) 

**Am I blocked on anything ?**

No.