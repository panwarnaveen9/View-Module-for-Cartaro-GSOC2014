**Name**


Naveen Panwar<br>
<br>
**Country**


India<br>
<br>
**School and Degree**


International Institute of Information Technology, Hyderabad, India.


B.Tech. in Computer Science + MS by research in Spatial Informatics.


<br>
Email


panwarnaveen9@gmail.com<br>
<br>
**Phone**


+91-9030736015<br>
<br>
OSGeo project(s)


Cartaro <br>
<br>
**Title:**


Add PostGIS spatial query support for the views module in Cartaro.

**Describe your idea** --<br>


1. Introduction


Right now Cartaro already provides support for simple spatial queries using the views module. But the configuration options are still limited and need to be extended. The plugin system of the views module makes it possible to create potentially complex queries for nodes based on any combination of the fields in a content type. The available fields should of course include geometry fields allowing for spatial operations like intersects or contains. Besides adding Views support to the PostGIS module which mainly requires PHP and SQL knowledge, this project will also require some JavaScript skills to use OpenLayers as a display and filter interface.


2. Background


Content management systems like Drupal has a need for building queries on geospatial data. This means, we have to build a good query processing system which can handle potentially complex queries for nodes based on any combination of the fields in a content type. The available fields should of course include geometry fields, allowing for spatial operations like intersects or contains. And the result set of the query should be able to display either as some kind of list or directly on a map.


<br>
3. The idea


The idea is to design and implement a PostGIS module with views integration, which should implement a Relationship plugin and a Filter plugin. The Relationship plugin would provide the ability to build spatial relationships between entities. The Filter plugin would make spatial filters available that can optionally be exposed to visitors. This would allow to do queries like &ldquo;show me all features within a certain region&rdquo; or &ldquo;show only features within a specified distance of feature X&rdquo;.


We can divide the idea into following three steps -


1. Input interface : Design an Interface to take inputs from user and pass on to the PostGIS backend. Input forms will developed using Drupal(PHP) and Javascript [ To perform validation of inputs ]. Interface visualization will build on OpenLayers.


2. PostGIS query processing : Perform the spatial queries using PostGIS module. To process the query we are going to PostGIS extension of PostgreSQL. The user inputs will be processed to create and execute a valid PostgreSQL query.


3. Result visualization : Display results/outputs of the queries in PostGIS on the views module in Cartaro. This part will be implemented by using JavaScript and OpenLayers.


4. Project plan [ Detailed Timeline ]


Before May 19


* Get familiarise with Drupal and PostGIS view module. And understand working of module functions with queries.
* Setup wiki page for the project&rsquo;s weekly reports and discussion.
* Make a repository on github for regular upload and easy access of the source code.

May 19-25


* Write sample function or code for plugin, learn/study the mechanism of drupal module.

May 26 - June 1


* Prepare the list of functionalities which we are going to provide the user for queries.
* Write down/ Draw technical design document.

June 2-8


* Write code to prepare input data for the queries.
* Design and implement the relationship plugin.

June 9-15


* Design and implement User Interface.

June 16-22


* Check compatibility of relationships between entities.
* Design and implement filter plugin.

June 23-29


* Mid Term Evaluations
* Testing the query processing module.
* Documentation.

June 30 - July 6


* Continue with the filter plugin.
* Process and test for all types of spatial queries.

July 7-13


* Integrating User interface with Query Processing module

July 14-20


* Buffer time
* Testing and bugs solving
* Code cleaning and documenting

July 21-27


* Display the output on OpenLayers (if time permits)

July 28 - August 3


* Working on displaying the output (continued from last week)
* A robust testing of all functionalities provided in the GUI.

August 4-10


* Testing and bug fixing
* Cleaning up the code
* Wrapping up documentation

August 11-17


* Buffer time
* Testing and bug fixing

August 18-22


* Final evaluations
* Testing and bug fixing ( if still something is left over)

After 22nd August


* Work on any issues regarding the particular deployment of project(code).
* Remain an active member of the Cartaro and OSGeo community.<br>

5. Future ideas / How can your idea be expanded ?


This idea can be extended to provide applications of PostGIS and Cartaro which includes routing services (pg_routing), location based services etc.. Also other PostgreSQL DB module can be club with the Cartaro.


Explain how your SoC task would benefit the OSGeo member project and more generally the OSGeo Foundation as a whole ?


Adding a PostGIS module support will open a huge possibility of spatial data processing with the Cartaro. It enable a big scope of spatial query processing with content management system.


<br>
Please provide details of general computing experience


Operating Systems: Linux (Ubuntu, Fedora Xfce), Windows.<br>
Programming Languages: C, C++, Python, Java, Matlab.<br>
Libraries and API: OpenGL, OpenCV, Google Map API (Basic).<br>
Web Development: PHP, HTML, JavaScript, Drupal, AJAX (Basic), Web2py.<br>
Database Management Systems: MySQL, PostGreSQL, SQLite.<br>
Programming Environment: Vim, NetBeans, Eclipse.


Please provide details of previous GIS experience


I am pursuing my Masters in the field of Spatial Informatics at Lab for Spatial Informatics, IIIT-Hyderabad. I have worked on GIS applications and remote sensing during my graduation.


I was also member of team which participated in ACM SIGSPATIAL GISCUP-2013. In which our task is to design efficient algorithms about geo-fencing. I am currently working on multi agents system framework for a road traffic system, which will help understand the traffic flows based on a range of interactions between the road network, spatio-temporal patterns of the traffic flow, and driver behavior.


<br>
Please provide details of any previous involvement with GIS programming and other software programming


I was part of [[VRGeo Project]] development which is an &ldquo;Open-Source Collaborative Mapping Platform for Crowdsourcing Location based information&rdquo; developed by our lab.


I developed android application which provide location based service for the freelance worker like: plumber, carpenter, electrician etc. to find a suitable job nearby. This app has won first prize for application development at [[Socinity, IIIT-Hyderabad]]. <br>


<br>
Please tell us why you are interested in GIS and open source software.


Since my freshman year of graduation I am using open source technologies Like: Wikipedia, Linux, Firefox etc. These things always motivated me to learn more and contribute for the development of open-source technologies. and When it comes to operating system I always choose Ubuntu and Fedora Xfce.


During my junior year I get to know about GIS tools like GRASS, QGIS, PostgreSQL etc.. Which gives me an opportunity to work in the very vast field like Data Modeling, Analysis, and Management.


Please tell us why you are interested in working for OSGeo and the software project you have selected.


I have worked before, both in PHP (Drupal) and Spatial Databases. And these project provided me the good opportunity of development in php with my research areas. So working with Cartaro will provide me the better opportunity my skills and experiences.


<br>
Please tell us why you are interested in your specific coding project.


I am always interested in backhand programming. As I am Students Web Administrator for my lab. This particular project will provide me to build spatial query processing module which allow me to code at low of technical design architecture.


<br>
Would your application contribute to your ongoing studies/ degree? If so, how?


As a part of my research work, I am designing Distribute Data Processing and Spatio-Temporal Data Analysis Framework in which I will make use of PostgreSQL with PostGIS extension at DB level. This project will provide me very good opportunity to work on this extension.


<br>
Please explain how you intend to continue being an active member of your project and/or OSGeo AFTER the summer is over.


I contributed in the development of open-source platform &rdquo;[[VRGeo]]&rdquo; , developed in my research center. Since then I am very much passionate to be a part of good open-source programme. GSOC gives me an opportunity to get associated with the OSGeo community and contribute for the benefit of open-source society. I want to pursue my interest with my research work. So I intend to be active member of OSGeo society even after summer.


Do you understand this is a serious commitment, equivalent to a full-time paid summer internship or summer job?


Yes. I am fully prepared for the work and will put in my best efforts.


<br>
Do you have any known time conflicts during the official coding period? (May 19 to August 19).


No, there will be no known time conflicts during the official coding period.
