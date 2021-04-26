#include "Area.h"



Area::Area(const std::string& type, const std::string& owner, int level){
    if( level < 0){throw ERRORS::negative_water_level;}
    area_type = type; 
    area_owner = owner;
    water_level = level;
}


//If the amount of the stored water is greater than 15 km3, the plain area changes into grassland
void Plain::changeArea(Area* &area){
    if(water_level > PLAIN_GROSSLAND_CHANGE){
        area->setAreaType("Grassland");
    }
}

//The area becomes lakes region obtaining amount of water over 50 km3, whereas in case the amount of stored water goes below 16 km3, the area changes to plain.
void Grassland::changeArea(Area* &area){
    if(water_level < GRASSLAND_PLAIN_CHANGE){
        area->setAreaType("Plain");
    } 
    if(water_level > GRASSLAND_LAKE_CHANGE){
        area->setAreaType("Lake");
    }
}


//Beyond an amount of water of 51 km3, the area changes into grassland. <- We have a type in this section (It should be "BELOW", but it's "beyond")
void Lake::changeArea(Area* &area){
    if(water_level < LAKES_GRASSLAND_CHANGE){
        area->setAreaType("Grassland");
    }
}




/**
 * NOTE: Class area just changes the area based on the amount of water it has. While reading data from the file, the amount of water would be given.
 **/
