#ifndef CONSTANTS_H
#define CONSTANTS_H


/*HUMIDITY CHANGE*/
#define HUMID_SUNNY 40
#define HUMID_RAINY_BEFORE  70
#define HUMID_RAINY_AFTER  30
#define HUMID_CLOUDY_UPPER_BOUND 70
#define HUMID_CLOUDY_LOWER_BOUND 40 
#define HUMID_MULTIPLICITY_CONST1 3.3
#define HUMID_MULTIPLICITY_CONST2 30



/*PLAIN AREA AND DIFFERENT WHEATHERS*/
#define PLAIN_SUNNY_WATER_LEVEL_DIFF  3
#define PLAIN_CLOUDY_WATER_LEVEL_DIFF  1
#define PLAIN_RAINY_WATER_LEVEL_DIFF  20
#define PLAIN_HUMIDITY_RAISE  5
#define PLAIN_GRASSLAND_CHANGE  15


/*GRaSSLAND AREA AND DIFFERENT WHEATHERS*/
#define GRASSLAND_SUNNY_WATER_LEVEL_DIFF 6
#define GRASSLAND_CLOUDY_WATER_LEVEL_DIFF 2
#define GRASSLAND_RAINY_WATER_LEVEL_DIFF 15
#define GRASSLAND_HUMIDITY_RAISE 10 
#define GRASSLAND_PLAIN_CHANGE 16 
#define GRASSLAND_LAKE_CHANGE 50


/*LAKES AND DIFFERENT WHEATHERS*/
#define LAKES_SUNNY_WATER_LEVEL_DIFF 10
#define LAKES_CLOUDY_WATER_LEVEL_DIFF 3
#define LAKES_RANIY_WATER_LEVEL_DIFF 20
#define LAKES_HUMIDITY_RAISE 15 
#define LAKES_GRASSLAND_CHANGE 51

#endif // CONSTANTS_H