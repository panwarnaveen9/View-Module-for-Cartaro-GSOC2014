
; Makefile to build a development release of Cartaro 
; which includes development snapshots of contrib projects.
; Execute a normal build-cartaro.make, then run this Makefile and
; move all modules, themes and libraries to profiles/cartaro.

; API
api = 2

; Core
core = 7.x

; Contrib modules
projects[ctools][version] = 1.3
projects[ctools][subdir]  = contrib
projects[diff][version] = 3.2
projects[diff][subdir] = contrib
projects[features][version] = 2.0
projects[features][subdir]  = contrib
projects[feeds][version] = 2.0-alpha8
projects[feeds][subdir]  = contrib
projects[gdal][version] = 1.0-beta4
projects[gdal][subdir]  = contrib
projects[geoserver][version] = 1.3
projects[geoserver][subdir]  = contrib
projects[job_scheduler][version] = 2.0-alpha3
projects[job_scheduler][subdir] = contrib
projects[libraries][version] = 2.1
projects[libraries][subdir]  = contrib
projects[module_filter][version] = 1.8
projects[module_filter][subdir]  = contrib
projects[nodetype_access][version] = 1.0-beta5
projects[nodetype_access][subdir]  = contrib
projects[nodetype_access][download][revision] = 6ea2263af7d198d1c33a91ad433a35affb31e048
projects[ole][version] = 1.0
projects[ole][subdir]  = contrib
projects[openlayers][version] = 2.0-beta7
projects[openlayers][subdir]  = contrib
projects[openlayers][download][revision] = 5093304fa0a6f1207feb08f8440cbe1e0ddd183b
projects[openlayers_filters][version] = 2.0
projects[openlayers_filters][subdir] = contrib
projects[openlayers_layer_assistant][version] = 1.0-beta2
projects[openlayers_layer_assistant][subdir]  = contrib
projects[openlayers_print][version] = 1.0-beta1
projects[openlayers_print][subdir]  = contrib
projects[pathauto][version] = 1.2
projects[pathauto][subdir]  = contrib
projects[postgis][version] = 1.2
projects[postgis][subdir]  = contrib
projects[proj4js][version] = 1.2
projects[proj4js][subdir]  = contrib
projects[token][version] = 1.5
projects[token][subdir]  = contrib
projects[strongarm][version] = 2.0
projects[strongarm][subdir]  = contrib
projects[views][version] = 3.7
projects[views][subdir]  = contrib

; Contrib themes
projects[frontmap][version] = 1.0-rc2
projects[frontmap][type] = theme
projects[zen][version] = 5.4
projects[zen][type] = theme
