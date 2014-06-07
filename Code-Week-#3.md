**Weekly Report (1st June to 7th June) -**

***

**Aim** - Prepare for the technical design pipeline of PostGIS view module.

**Things, I have done this week**
* Understood the current implementation of geometric field display in Cartaro.
  * **Available pipeline** - 
    1. PostGIS (To store the raw geometric data)
    2. Geo-Server (To prepare geometric layer[WMS])
    3. OpenLayers (To display WMS layer)
  * **Proposed pipeline** -
    1. PostGIS
    2. View Module - Build the spatial query, execute the query, get the data and pass it to OpenLayers using handler.
    3. OpenLayers    

**Technical Design for Module (folder structure and class description)** -
* **postgis/** -
  * postgis.openlayers.inc - Provides hooks for integration with OpenLayers.

* **postgis/views/** -
  * postgis.views.inc - Hooks for views integration. A class that contain all of the data to generate a view, plus the member functions to build the view query, execute the query and render the output.
  * postgis_views_handler_filter_geometry.inc - Provide filter for geo-spatial data.  

* **postgis/views/handlers/** - 
  * Implement all handlers which are needed. like: sort, field, argument proximity, filter etc.  

**Things to do next week**
* . 

**Reference Modules**
* GeoField - [https://drupal.org/project/geofield](https://drupal.org/project/geofield)

**Am I blocked on anything ?**

No