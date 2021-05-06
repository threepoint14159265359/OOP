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
    if(this->water_level > PLAIN_GRASSLAND_CHANGE){
        return new Grassland("Grassland", this->getAreaOwner() , this->water_level);
    }else{
        return new Plain("Plain",this->getAreaOwner() , this->water_level);
    }
}


Area* Grassland::changeArea(){
    if(this->water_level < GRASSLAND_PLAIN_CHANGE){
        return new Plain("Plain",this->getAreaOwner() , this->water_level);
    }
    if(this->water_level > GRASSLAND_LAKE_CHANGE){
        return new Lake("Lake", this->getAreaOwner() , this->water_level);
    }
    return new Grassland("Grassland", this->getAreaOwner() , this->water_level);
}

Area* Lake::changeArea(){
    if(this->water_level < LAKES_GRASSLAND_CHANGE){
        return new Grassland("Grassland", this->getAreaOwner() , this->water_level);
    }else{
        return new Lake("Lake", this->getAreaOwner() , this->water_level);
    }
}




/**
 *  Change Water Level based on the given Season
 *  - Every ground/area has a water level and a season, and based on that season we would change the water level in each simulation round
 *  - For instance if the ground is plain and the season is Sunny, we could decrease the water level by PLAIN_SUNNY_WATER_LEVEL_DIFF amount
 */

void Plain::changeWaterLevel(Weather* season){
    if( season->getWeatherType() == "Sunny"){
        water_level -= PLAIN_SUNNY_WATER_LEVEL_DIFF; //decrease
    }

    if( season->getWeatherType() == "Cloudy"){
        water_level -= PLAIN_CLOUDY_WATER_LEVEL_DIFF; //decrease
    }

    if( season->getWeatherType() == "Rainy"){
        water_level += PLAIN_RAINY_WATER_LEVEL_DIFF; //increase
    }
    
}


void Grassland::changeWaterLevel(Weather* season){
    if( season->getWeatherType() == "Sunny"){
        water_level -= GRASSLAND_SUNNY_WATER_LEVEL_DIFF; //decrease
    }

    if( season->getWeatherType() == "Cloudy"){
        water_level -= GRASSLAND_CLOUDY_WATER_LEVEL_DIFF; //decrease
    }

    if( season->getWeatherType() == "Rainy"){
        water_level += GRASSLAND_RAINY_WATER_LEVEL_DIFF; //increase
    }
}

void Lake::changeWaterLevel(Weather* season){
    if( season->getWeatherType() == "Sunny"){
        water_level -= LAKES_SUNNY_WATER_LEVEL_DIFF; //decrease 
    }

    if( season->getWeatherType() == "Cloudy"){
        water_level -= LAKES_CLOUDY_WATER_LEVEL_DIFF; //decrease
    }

    if( season->getWeatherType() == "Rainy"){
        water_level += LAKES_RANIY_WATER_LEVEL_DIFF; //increase
    }
    
}


