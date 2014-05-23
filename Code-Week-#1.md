**Weekly Report (19th May to 24th May) -**

**Aim** - The task in hand was to learn and understand the Cartao and POSTGIS module functionalities. Also get  familiarize with Content type and Geometric field in Cartao.   

**Things, I have done this week**
* Finish the proper installation of the Cartaro, tomcat7, geo-server, php, PostgreSQL.
* Build PostGIS 2.1 from source.
* Configure Geo-Server which used to provide layers via Web Feature Service (WFS) and Web Map Service (WMS) to Cartaro. 
* Adding new content type and geometric field to cartaro.
* Configure OpenLayers to activate your GeoServer layer in a cartaro map and add Geo-spatial content.

**Learning**
* We must build the PostGIS 1.5 + from source before cartaro installation.
* The name of the new User-Group Service should be the same that the **Geo-server Workspace name** that you choose when installing Cartaro.
* Enable PostGIS extension in PostgreSQL database with cartaro user as an owner.  

**Things to do next week**
* Prepare the list of functionalities which were already there and which we are going to provide the user for queries.
* Write down and Draw technical design document. 

**Important URLs**
* Repository URL - [https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014)
* Development setup - [https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/wiki/Development-setup](https://github.com/panwarnaveen9/View-Module-for-Cartaro-GSOC2014/wiki/Development-setup)
* Geo-Server Configuration - [http://cartaro.org/documentation/using-drupal-users-and-roles-geoserver](http://cartaro.org/documentation/using-drupal-users-and-roles-geoserver)
* PostGIS building on Ubuntu - [http://trac.osgeo.org/postgis/wiki/UsersWikiPostGIS21Ubuntu1204src](http://trac.osgeo.org/postgis/wiki/UsersWikiPostGIS21Ubuntu1204src)