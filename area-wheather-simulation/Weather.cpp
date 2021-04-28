#include "Weather.h"
#include <iostream>


void Weather::ChangeWeather(int humid){

    
    if(humid  < HUMID_SUNNY){
        weatherType = "Sunny";
        this->setHumidity(humid);
        //debug
        //std::cout << "SUNNY CHANGE.." << std::endl;
    
    }else if(humid > HUMID_RAINY_BEFORE){
        //debug
        //std::cout << "Rainy CHANGE.." << std::endl;
        weatherType = "Rainy";
        this->setHumidity(HUMID_RAINY_AFTER);
    }else if((humid > HUMID_CLOUDY_LOWER_BOUND && humid < HUMID_CLOUDY_UPPER_BOUND) && (humid- HUMID_MULTIPLICITY_CONST2) * HUMID_MULTIPLICITY_CONST1 >= 100){  
        
        weatherType = "Rainy";
        this->setHumidity(HUMID_RAINY_AFTER);
        
    }else{
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


 