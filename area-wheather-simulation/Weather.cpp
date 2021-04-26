#include "Weather.h"


Weather::Weather(int humid){
    humidity = humid;
}

Weather* Weather::determinWeather(){
    if(this->humidity < HUMID_SUNNY){
        return Sunny::instance();
    }
    if((this->humidity >= HUMID_CLOUDY_LOWER_BOUND && this->humidity <= HUMID_CLOUDY_UPPER_BOUND) && (this->humidity- HUMID_MULTIPLICITY_CONST2) * HUMID_MULTIPLICITY_CONST1 >= 100){
        Rainy::instance();
    }else{
        return Cloudy::instance();
    }
    if( this->humidity >= HUMID_RAINY_BEFORE){
        humidity = HUMID_RAINY_AFTER;
        return Rainy::instance();
    }
}


Sunny* Sunny::s_instance = nullptr;
Sunny* Sunny::instance(){
    if(s_instance == nullptr){
        s_instance = new Sunny();
    }
    return s_instance;
}

void Sunny::destroy(){
    if(nullptr != s_instance){
        delete s_instance; 
        s_instance = nullptr;
    }
}

//Sunny weather and different areas
Weather* Sunny::changeWaterLevel(Grassland *land){
    land->changerWaterLevel(-1 * GRASSLAND_SUNNY_WATER_LEVEL_DIFF); //decrease
    return this;
}
Weather* Sunny::changeWaterLevel(Plain *area){  
    area->changerWaterLevel(-1 * PLAIN_SUNNY_WATER_LEVEL_DIFF); //decrease
    return this;
}
Weather* Sunny::changeWaterLevel(Lake *area){
    area->changerWaterLevel(-1 * LAKES_SUNNY_WATER_LEVEL_DIFF); //decrease
    return this;
}




Cloudy* Cloudy::c_instance = nullptr;
Cloudy* Cloudy::instance(){
    if(c_instance == nullptr){
        c_instance = new Cloudy();
    }
    return c_instance;
}

void Cloudy::destroy(){
    if(nullptr != c_instance){
        delete c_instance; 
        c_instance = nullptr;
    }
}

//Cloudy weather and different areas
Weather* Cloudy::changeWaterLevel(Grassland *area){
    area->changerWaterLevel(-1 * GRASSLAND_CLOUDY_WATER_LEVEL_DIFF); //decrease
    return this;
}
Weather* Cloudy::changeWaterLevel(Plain *area){
    area->changerWaterLevel(-1 * PLAIN_CLOUDY_WATER_LEVEL_DIFF); //decrease
    return this;
}
Weather* Cloudy::changeWaterLevel(Lake *area){
    area->changerWaterLevel(-1 * LAKES_CLOUDY_WATER_LEVEL_DIFF); //decrease
    return this;
}


/**
 * NOTE: the Humidity changes only once for each simulation. It's quite counter intuitive that 
 *       Weather depends upon the Humidity, but Humidity doesn't depend upon weather.
 *       Atleast for this task, the humidity depends upon the given type of land. 
 *       It's given in the task that 
 *          - Humidity is increased by 5 percent each time we encounter a plain land
 *          - Humidity is increased by 10 percent each time we encounter a grassland 
 *          - Humidity is increased by 15 percent each time we encounter a lake
 *      In the main function, we will first deal with the Rainy instance first on each simulation so that we can updated humidity every time.
 */


Rainy* Rainy::r_instance = nullptr;
Rainy* Rainy::instance(){
    if(r_instance == nullptr){
        r_instance = new Rainy();
    }
    return r_instance;
}

void Rainy::destroy(){
    if(nullptr != r_instance){
        delete r_instance; 
        r_instance = nullptr;
    }
}

Weather* Rainy::changeWaterLevel(Grassland *area){
    //changing humidity 
    changeHumdity(GRASSLAND_HUMIDITY_RAISE); //increase
    area->changerWaterLevel(GRASSLAND_RAINY_WATER_LEVEL_DIFF); //increase
    return this;
}
Weather* Rainy::changeWaterLevel(Lake *area){
    //changing humidity 
    this->changeHumdity(LAKES_HUMIDITY_RAISE); //increase
    area->changerWaterLevel(LAKES_RANIY_WATER_LEVEL_DIFF); //increase
    return this;
}
Weather* Rainy::changeWaterLevel(Plain *area){
    //changing humidity 
    this->changeHumdity(PLAIN_HUMIDITY_RAISE); //increase
    area->changerWaterLevel(PLAIN_RAINY_WATER_LEVEL_DIFF); //increase
    return this;
}