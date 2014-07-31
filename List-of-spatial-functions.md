### Type 1

**Input type -** function_name(geometry A, geometry B)

**Return type -** Boolean True/False. `Used in where clause to filtered out the results.`

**Example -** ST_Touches(geom A, geom B), &&(geom A, geom B)

**Geometry A -** Geometry field store in PostGIS.

**Geometry B -** Users' input in WKT(Well-Known-Text) format
    

* **Spatial Relationships**
 * ST_Contains 
 * ST_Intersects 
 * ST_Disjoint
 * ST_Covers
 * ST_Equals
 * ST_Touches
 * ST_Within
 * ST_Overlaps 
 * ST_Crosses
 * ST_CoveredBy
 * ST_ContainsProperly

* **Spatial Operators**
  * && 
  * &&&
  * &< 
  * &<| 
  * &> 
  * << 
  * <<| 
  * = 
  * >> 
  * @ 
  * |&> 
  * |>> 
  * ~ 
 * ~= 

### Type 2

**Input type -** function_name(geometry A)

**Return type -** New field or modified value of geometric field. ``

**Example -** ST_Area(geom A), ST_Perimeter (geom A).

**Geometry A -** Geometry field store in PostGIS.

**Spatial Measurements**
* ST_Area
* ST_Azimuth
* ST_Centroid
* ST_HasArc
* ST_Length
* ST_Perimeter