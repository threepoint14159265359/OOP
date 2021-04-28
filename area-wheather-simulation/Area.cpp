#include "Area.h"


Area::Area(const std::string& type, const std::string& owner, int level){
    if( level < 0){throw ERRORS::negative_water_level;}
    area_type = type; 
    area_owner = owner;
    water_level = level;
}



/**
 * NOTE: Area is changed for different Area types 
 */
Area* Plain::changeArea(){
    if(water_level > PLAIN_GRASSLAND_CHANGE){
        return new Plain("Grassland", this->getAreaOwner() , water_level);
    }
    return new Plain("Plain",this->getAreaOwner() , water_level);
}


Area* Grassland::changeArea(){
    if(water_level < GRASSLAND_PLAIN_CHANGE){
        return new Plain("Plain",this->getAreaOwner() , water_level);
    } 
    if(water_level > GRASSLAND_LAKE_CHANGE){
        return new Lake("Lake", this->getAreaOwner() , water_level);
    }
    return new Plain("Grassland", this->getAreaOwner() , water_level);
}

Area* Lake::changeArea(){
    if(water_level < LAKES_GRASSLAND_CHANGE){
        return new Plain("Grassland", this->getAreaOwner() , water_level);
    }
    return new Lake("Lake", this->getAreaOwner() , water_level);
}




//CHANGE AREA HUMIDITY AND WATER LEVEL IN ALL AREAS (OVERRIDING SIGLE VIRTUAL METHOD)

void Plain::changeWaterLevelAreaHumidity(Weather* season){
    if( season->getWeatherType() == "Sunny"){
        water_level -= PLAIN_SUNNY_WATER_LEVEL_DIFF; //decrease
    }

    if( season->getWeatherType() == "Cloudy"){
        water_level -= PLAIN_CLOUDY_WATER_LEVEL_DIFF; //decrease
    }

    if( season->getWeatherType() == "Rainy"){
        water_level += PLAIN_RAINY_WATER_LEVEL_DIFF; //increase
    }
    //change Humidity
    //season->setHumidity(season->getAirHumidity() + PLAIN_HUMIDITY_RAISE);
}


void Grassland::changeWaterLevelAreaHumidity(Weather* season){
    if( season->getWeatherType() == "Sunny"){
        water_level -= GRASSLAND_SUNNY_WATER_LEVEL_DIFF; //decrease
    }

    if( season->getWeatherType() == "Cloudy"){
        water_level -= GRASSLAND_CLOUDY_WATER_LEVEL_DIFF; //decrease
    }

    if( season->getWeatherType() == "Rainy"){
        water_level += GRASSLAND_RAINY_WATER_LEVEL_DIFF; //increase
    }
    //changeHumidity
    //season->setHumidity(season->getAirHumidity() + GRASSLAND_HUMIDITY_RAISE);
}

void Lake::changeWaterLevelAreaHumidity(Weather* season){
    if( season->getWeatherType() == "Sunny"){
        water_level -= LAKES_SUNNY_WATER_LEVEL_DIFF; //decrease 
    }

    if( season->getWeatherType() == "Cloudy"){
        water_level -= LAKES_CLOUDY_WATER_LEVEL_DIFF; //decrease
    }

    if( season->getWeatherType() == "Rainy"){
        water_level += LAKES_RANIY_WATER_LEVEL_DIFF; //increase
    }
    //change Humidity
    //season->setHumidity(season->getAirHumidity() + LAKES_HUMIDITY_RAISE);
}


