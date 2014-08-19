### Enable Spatial Filter in Cartaro

***

**Example** - I am using entire world's country capitals location as geometric field which is available by default with Cartaro distribution.

* **Step 1** - Adding new view
 * Go to Administration -> structure -> Views Click on **Add new view**
 * Fill the detail as given in screenshot. 
 * Enter view name, Select Content type: **Capital**, Click on "Save and Exit" 
![Step 1](http://lsi.iiit.ac.in/naveen.panwar/GSoC-2014/User_Guide/Step0.png)

* **Step 2** - Edit view
 * Go to Administration -> Structure -> Views Click on **Edit** in front of respective view name(capitals).
![Step 2](http://lsi.iiit.ac.in/naveen.panwar/GSoC-2014/User_Guide/Step2.png)

* **Step 3** - Adding spatial filter
 * Under "Filter Criteria" click on "Add" to add new filter
![Step 3](http://lsi.iiit.ac.in/naveen.panwar/GSoC-2014/User_Guide/Step3.png)

* **Step 4** - Selection of Geometric Field
 *  Select **Content: Location (field_location)** as geometric field.
 * Click on Apply (all display).
![Step 4](http://lsi.iiit.ac.in/naveen.panwar/GSoC-2014/User_Guide/Step4.png)

* **Step 5** - Filter Configuration
 * Check the box "Expose this filter to visitors".
 * Click on Apply (all display). 
![Step 5](http://lsi.iiit.ac.in/naveen.panwar/GSoC-2014/User_Guide/Step5.png)

* **Step 6** - Save modified view.
 * 0 - Exposed filter has been added to filter criteria.
 * 1 - Click on **save** to apply changes on all views.
 * 2 - Click on **view page** to visit the page  
![Step 6](http://lsi.iiit.ac.in/naveen.panwar/GSoC-2014/User_Guide/Step06.png)

* **Step 7** - Use spatial filter.
 * Select the spatial function which you want to perform on geometric data.
 * Remember your geometric field act as Geometry B for all the spatial functions.
 * Enter the Geometry A data in WKT/EWKT format.
 * I have opted **Contain** function. 
 * WKT data - Bounding box of south america.
 * Click **Apply** to filter the results.    
![Step 7](http://lsi.iiit.ac.in/naveen.panwar/GSoC-2014/User_Guide/Step7.png)
 * South America WKT data - <br />
`POLYGON((-89.8242187410966 11.7867026934347,-30.4101562517393 12.3024353744086,-32.3437500013929 -56.2158687413592,-89.8242187410966 -55.9215079419514,-89.8242187410966 11.7867026934347))`

* **Step 8** - 
 * As result of above filter you will get the **capitals of South America region's countries**.
![Step 8](http://lsi.iiit.ac.in/naveen.panwar/GSoC-2014/User_Guide/Step8.png)


### Important notes
* If any input filed is not applicable for your filter criteria then **leave it blank**.
* Comparison Operator only applicable if you choose **Spatial Measurement** as spatial function.