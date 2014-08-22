**Cartaro GSoC-2014** : Add PostGIS spatial query support for the views Cartaro<br /><br />
**Student** : Naveen Panwar <panwarnaveen9@gmail.com><br /><br />
**Mentors** : Friedjoff Trautwein <friedjoff.trautwein@geops.de>, Nico Mandery <nico.mandery@geops.de>

The idea is to design and implement a PostGIS module with views integration, which should implement a Relationship plugin and a Filter plugin. The Relationship plugin would provide the ability to build spatial relationships between entities. The Filter plugin would make spatial filters available that can optionally be exposed to visitors. This would allow to do queries like `show me all features within a certain region` or `show only features within a specified distance of feature X`.

We can divide the idea into following three steps -

**Input interface** : Design an Interface to take inputs from user and pass on to the PostGIS backend. Input forms will developed using Drupal(PHP) and Javascript [To]. Interface visualization will build on OpenLayers.

**PostGIS query processing** : Perform the spatial queries using PostGIS module. To process the query we are going to PostGIS extension of PostgreSQL. The user inputs will be processed to create and execute a valid PostgreSQL query.

**Result visualization** : Display results/outputs of the queries in PostGIS on the views module in Cartaro. This part will be implemented by using JavaScript and OpenLayers.
