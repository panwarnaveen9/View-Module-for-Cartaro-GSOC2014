**Weekly Report (29th June to 5th July) -**

***

**Aim** - Implement the spatial filter functions for the module.

**Things, I have done this week**

* Tracing the query function call.  
* Query function Pipeline. 
  * postgis_views_handler_filter_geometry.inc
  * ../views/handlers/views_handler_filter.inc
  * ../views/includes/handlers.inc
  * ../views/plugins/views_plugin_query_default.inc
* Expose the "query->add_where()" function in [postgis_views_handler_filter_geometry.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/20964232f29365a6ff28f54c11b09244936f9eec/cartaro/profiles/cartaro/modules/contrib/postgis/views/postgis_views_handler_filter_geometry.inc) 

**Comments**
* I am still confuse which "where-function" we are supposed to expose. There are two functions:
  1. query->add_where()
  2. query->add_where_expression() 

**Mentor Suggestions**
* Due to network unavailability I was not able to connect with my mentor. I will discuss above issue with mentor and try to resolve it ASAP.

**Modified Timeline**
* Developing the fully functional filter module take 2 more week. 
* I am planning to use 9th week's Buffer time to complete the filter module. 

**Things to do next week**

* Work on new timeline, based on the progress I have made so far.
* Continue the work on filter module.
* Understand the query functions customization in Views.   


**Reference Modules/Files** - 
* [postgis_views_handler_filter_geometry.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/20964232f29365a6ff28f54c11b09244936f9eec/cartaro/profiles/cartaro/modules/contrib/postgis/views/postgis_views_handler_filter_geometry.inc)
* [views_handler_filter.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/20964232f29365a6ff28f54c11b09244936f9eec/cartaro/profiles/cartaro/modules/contrib/views/handlers/views_handler_filter.inc)

**Am I blocked on anything ?**

No.