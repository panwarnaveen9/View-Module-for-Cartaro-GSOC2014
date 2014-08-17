### Type 1-A

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


`We will be focusing more on filter functions. Also we are considering the other means of geometry input for geometry B. For example, using the geometry from other nodes as input. So as of now we are providing the filter functionality for followings functions thus we can modified the query as follow.`

**Query** - where (ST_Area(geom A) = or < or > numeric value)  

**Input Required** - We need following field to build this query.

1. Geometric field
2. Numeric value (like: 0, 123, 5690)
3. Comparison Operators (like: =,<,>,<> etc.)

### Type 2
    
**Input type -** function_name(geometry A)

**Return type -** New field or modified value of geometric field. `Used, when we have derived filed value, aggregated output or spatial operation on geometric field.`

**Example -** ST_Area(geom A), ST_Perimeter (geom A).

**Geometry A -** Geometry field store in PostGIS.
 
* **Spatial Measurements**
 * ST_Area
 * ST_Azimuth
 * ST_Centroid
 * ST_HasArc
 * ST_Length
 * ST_Perimeter
<br />
<br />

## Future Work

### Type 1-B 

`Take same inputs as Type 1-A but returned geometry`

* **Geometry Processing** 
 * ST_Intersection
 * ST_Union
 * ST_Split
 * ST_Difference
 * ST_SharedPaths

* **Spatial Outputs**
 * ST_AsEWKT
 * ST_AsText 
 * ST_AsLatLonText `For points only`

