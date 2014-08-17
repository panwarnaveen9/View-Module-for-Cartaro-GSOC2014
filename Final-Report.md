## 91 days of GSoC    

### Aim 
Our aim was to provide views integration for PostGIS module in cartaro, which implements spatial query filter on geometry data.<br /> 
We successfully fulfilled the above the goal in current **integration of views in PostGIS module**.<br /> 

### Outcomes
* User can apply spatial filter on following functions.
  * Spatial Relationships
  * Spatial Operators
  * Spatial Measurements with comparison (like: Area > 10)
* User can provide the geometry in following ways-
  * WKT/EWKT input filed(textarea).
  * Select of already existing PostGIS field.
* **[List of functions](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/wiki/List-of-spatial-functions) which user can exposed.** Current implementation support only Type 1-A and Type 2 functions.  

### Work Experience
<p>It was a great experience for me. I have learned about technology as well as open source development.</p> 
* **Things, I have learned**
  * How to implements hooks to views data in cartaro(drupal).
  * Customize filter handler for the fields.
  * Drupal form API.
  * How to expose filters to users.
  * Building query based on users' need.
  * PostGIS database functions. 
  * **EntityFieldQuery class** - Used in finding entities based on entity properties or based on users' need.
  * Spatial relations and measurements of geometries. 

* **Things, in which I have improved**
  * Knowledge of PHP and coding in it.
  * Usage of classes and inheritance. 
  * Get to know about open source development.
  * Experience in drupal. 

<br />
### Issues faced during GSoC
1. Need to build PostGIS-2.0 in order to enable cartaro to store geometry data. <br />`sudo apt-get install postgresql-9.1-postgis` won't work for me. 
2. Getting the data of particular entity - Used build in function `node_load_multiple`. 
3. Problem while exposing filter to users - Need to overwrite function `accept_exposed_input()` and set the parameters according to users' inputs.   
<br />

### Feature Work
There are two major area where this project has great opportunity of development.

1. **Users' Input** - In current implementation users need to provide geometry in **WKT/EWKT** format.<br />Which can be improve as follow -  
  * **Geometry interface** - By providing a interactive map / interface to users where they can draw the geometry so we can store this geometry temporarily in PostGIS and apply the spatial function on it.  
  * **Geometry files** - Instead of providing the geometry as input, user can upload the shape file(.shp) or GML file(.gml). And we extract geometry from these files to process the query. 

2. **Derived geometry or additional field** - In current implementation we only provide the filter functionality on geometries. But we can provide more information based on users' need like - 
  * Area, perimeter along with geometries.
  * Derived geometry by applying function like: ST_Union, ST_Split etc.. 
  * More functions can be added in this category like: ST_Buffer, ST_BuildArea etc..
  * Function lies in this implementation are as follows
    * Geometry Processing
    * Spatial Outputs
    * Spatial Measurements
  * List of these functions also [complied here](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/wiki/List-of-spatial-functions#future-work).
<br /><br />

### Important Files 
* **postgis/views/**
  * [`postgis.views.inc`](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/master/postgis_module/views/postgis.views.inc) - Set custom filter handler for PostGISare fields.
  * [`postgis_views_handler_filter_geometry.inc`](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/master/postgis_module/views/postgis_views_handler_filter_geometry.inc) -  A handler to provide filter for geospatial data.
* **postgis/includes/**
  * [`postgis.geometry.inc`](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/master/postgis_module/includes/postgis.geometry.inc) - PostGIS geometry class. 
<br />

### View Associate Files
* [views_handler_filter.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/20964232f29365a6ff28f54c11b09244936f9eec/cartaro/profiles/cartaro/modules/contrib/views/handlers/views_handler_filter.inc)
* [handlers.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/master/cartaro_distribution/profiles/cartaro/modules/contrib/views/includes/handlers.inc)
* [views_plugin_query_default.inc](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/blob/master/cartaro_distribution/profiles/cartaro/modules/contrib/views/plugins/views_plugin_query_default.inc)
<br />

### Reference Modules or Files
* [PostGIS Reference Manual](http://postgis.net/docs/manual-2.0/reference.html)
* [PostGIS Module](https://drupal.org/project/postgis)
* [Geofield](https://drupal.org/project/geofield)
* [View Module](https://drupal.org/project/views)