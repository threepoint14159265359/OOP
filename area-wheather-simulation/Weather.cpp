#include "Weather.h"
#include <iostream>


void Weather::ChangeWeather(int humid){

    
    if(humid  < HUMID_SUNNY){
        weatherType = "Sunny";
        this->setHumidity(humid);
        //debug
        //std::cout << "SUNNY CHANGE.." << std::endl;
    
    }
    if(humid >= HUMID_RAINY_BEFORE){
        weatherType = "Rainy";
        this->setHumidity(HUMID_RAINY_AFTER);
    }
    
    if((humid > HUMID_CLOUDY_LOWER_BOUND && humid < HUMID_CLOUDY_UPPER_BOUND)){
        weatherType = "Cloudy";
        this->setHumidity(humid);
    }

    //std::cout << "passed return" << std::endl;
}


void Weather::changeAirHumidity(Area* area){
    if(area->getAreaType() == "Plain"){
        air_humidity += PLAIN_HUMIDITY_RAISE;
    }

    if(area->getAreaType() == "Grassland"){
        air_humidity += GRASSLAND_HUMIDITY_RAISE;
    }

    if(area->getAreaType() == "Lake"){
        air_humidity += LAKES_HUMIDITY_RAISE;
    }
}


 