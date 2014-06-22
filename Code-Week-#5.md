**Weekly Report (15th June to 21st June) -**

***

**Aim** - Implement the spatial relationship functions for the module.

**Things, I have done this week**

* Added new content type with geometric field in WKT(Well Known Text) format. 
* Worked on Views configuration UI.
* Customized the format(content/field) in Views.
* Configured and tested the different criteria under filter and sort of Views.
* Understand the different terminology of Views interface which as follow
  * Display
  * Filter
  * Content versus Fields 
  * Pager 
* **New relational functionalities** -
  1. ST_Covers — Returns 1 (TRUE) if no point in Geometry B is outside Geometry A.
  2. ST_Equals — Returns true if the given geometries represent the same geometry. Directionality is ignored.
  3. ST_Touches — Returns TRUE if the geometries have at least one point in common, but their interiors do not intersect.
  4. ST_Within — Returns true if the geometry A is completely inside geometry B.
  5. ST_Overlaps — Returns TRUE if the Geometries share space, are of the same dimension, but are not completely contained by each other.

**Things to do next week**

* Mid Term Evaluations.
* Test and implement the relational functions.  

**Reference Modules/Files** - 
* [1] Views terminology - (http://www.drupalgardens.com/documentation/views/terminology)[http://www.drupalgardens.com/documentation/views/terminology]

**Am I blocked on anything ?**

No.