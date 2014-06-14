**Weekly Report (8th June to 14th June) -**

***

**Aim** - Design the spatial relationship functions for the View Module.

**Things, I have done this week**

* Worked on available code of spatial queries in Cartaro.

  * /supporting_module/postgis/views/postgis_views_handler_filter_geometry.inc
  * /supporting_module/postgis/postgis.test

* Identified and ranked the Spatial functionality which we are going to provide the Cartaro's user in View module.

* **Available functions** -  
  * 'ST_Contains', 'ST_Intersects', 'ST_Disjoint'

* **New relational functionality** -
  1. ST_Covers — Returns 1 (TRUE) if no point in Geometry B is outside Geometry A.
  2. ST_Equals — Returns true if the given geometries represent the same geometry. Directionality is ignored.
  3. ST_Touches — Returns TRUE if the geometries have at least one point in common, but their interiors do not intersect.
  4. ST_Within — Returns true if the geometry A is completely inside geometry B.
  5. ST_Overlaps — Returns TRUE if the Geometries share space, are of the same dimension, but are not completely contained by each other.

**Things to do next week**

* Write the ode to extract data for above functions.
* Hooks the code with OpenLayers.  

**Reference Modules/Files** - 

Hooks for Views integration - /supporting_module/postgis/views/postgis.views.inc

**Am I blocked on anything ?**

Yes, In this week I was struggling to reflect the sample changes of PostGIS view module in cartaro. I will discuss it with mentor/co-mentor and try to resolve it by this monday. 