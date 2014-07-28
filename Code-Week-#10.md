**Weekly Report (20th July to 26th July) -**

***

**Aim** - Implement the spatial filter functions for the module.

**Things, I have done this week**
* Tested the query function for the remaining operations like: ST_Within, ST_Covers, ST_Overlaps etc..
* Geometry validation by adding [ST_IsValid](http://postgis.refractions.net/documentation/manual-1.4/ST_IsValid.html) in where clause of query.
* Added more spatial relationship function to module like: ST_Crosses, ST_CoveredBy, ST_ContainsProperly.

[**Revised Plan/Timeline**](#Revised Plan)

* Week 11 - Building query for **Spatial Measurements** and **Operators**.
* Week 12 - Building query for specific functions for  **Geometry Accessors** and **Geometry Editors**.
* Week 13 - Testing the all functionality of View module. 

**Approach**

There are two ways to provide all spatial functions/operations to users.

1. **Categorization**
 1. We can categorize all functions/operations according the [PostGIS Reference](http://postgis.net/docs/manual-2.0/reference.html#Spatial_Relationships_Measurements) and make different input forms to access them. 
 2. Once user select the category then he will get the list of all available functions/operations in that particular category and customized input form.
 3. Example
    * Drop-down for list of categories.
    * Spatial Measurements
       * ST_Area, ST_Azimuth, ST_Centroid etc..
     * Spatial Relationships
        * ST_Equals, ST_Touches, ST_Within etc.. 
     * Respective input form

2. **Query Builder**
  1. We can provide the list of all available functions/operations at once and a common form to take the all possible inputs.
  2. Once user submit this form then based on his selected function we will consider only particular fields values associate with it and build the query. 
  3. Example form
    * List of all functions
    * Choose PostGIS field drop-down
    * Input Geometry B data
    * Extra Value (like: distance for ST_DWithin function etc..)

**Things to do next week**
* Select one out of two approaches and modified the code accordingly.
* Complete the query functionality for all **Spatial Measurements** and **Operators**.  

**Reference Modules/Files** - 
* [PostGIS Reference Manual](http://postgis.net/docs/manual-2.0/reference.html)
* [postgis_views_handler_filter_geometry.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/20964232f29365a6ff28f54c11b09244936f9eec/cartaro/profiles/cartaro/modules/contrib/postgis/views/postgis_views_handler_filter_geometry.inc) 

**Am I blocked on anything ?**

No.