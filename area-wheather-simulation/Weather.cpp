#include "Weather.h"
#include <iostream>


Weather* Weather::ChangeWeather(int humid){
    Weather* weather; 

    
    if(humid  < HUMID_SUNNY){
        weather = new Sunny("Sunny",humid);
        //debug
        //std::cout << "SUNNY CHANGE.." << std::endl;
    
    }
    if(humid > HUMID_RAINY_BEFORE){
        //debug
        //std::cout << "Rainy CHANGE.." << std::endl;
        weather = new Rainy("Rainy", HUMID_RAINY_AFTER);
        std::cout << weather->getAirHumidity() << std::endl;
    }
    if((humid >= HUMID_CLOUDY_LOWER_BOUND && humid <= HUMID_CLOUDY_UPPER_BOUND) && (humid- HUMID_MULTIPLICITY_CONST2) * HUMID_MULTIPLICITY_CONST1 < 50){  
        //debug
        //std::cout << "Cloudy CHANGE.." << std::endl;
        weather = new Cloudy("Cloudy", humid);
    }

    //std::cout << "passed return" << std::endl;
    return weather;
}


 