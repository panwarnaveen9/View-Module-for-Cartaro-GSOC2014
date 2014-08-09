**Weekly Report (3rd August to 9th August) -**

***

**Aim** - Implement the spatial filter functions for the module.

**Things, I have done this week**
* Completed the query for **Spatial Measurements**.
* Added comparison operators to support measurement query. 
* Added numeric data input with Geometry B text area.
* Added the list of all node ids which has module type **'postgis'** to input form. 

**Comments**
* Faced error when I enable users to expose the filter module. Which is probably due to unset variable, will try to fix it ASAP.  
* Need to add some variable as global rather then recalculating them again and again. 
 Like: List of postgis fields and their respective nids.
 
**Things to do next week**
* Testing for existing functionality.
* GSoC documentation, code cleaning and commenting.

**Reference Modules/Files** - 
* [views_handler_filter.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/master/cartaro_distribution/profiles/cartaro/modules/contrib/views/handlers/views_handler_filter.inc)
* [postgis_views_handler_filter_geometry.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/20964232f29365a6ff28f54c11b09244936f9eec/cartaro/profiles/cartaro/modules/contrib/postgis/views/postgis_views_handler_filter_geometry.inc) 

**Am I blocked on anything ?**

No.