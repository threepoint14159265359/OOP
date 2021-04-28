#ifndef AREA_H
#define AREA_H

#include <iostream>
#include "Weather.h"
#include "constants.h"
#include <string>

class Weather; 
class Sunny;
class Cloudy; 
class Rainy;


/**
 * Since an area is still an area even if we remove the weather from it. More precisely, if the container of Area Class 
 * is Weather Class and we destroy the container, Area will still be an object. So, there is an aggregation relation 
 * between Weather and Area Class. However, it can also be considered as dependcy if we want to ceate the concrete
 * objects in the main.
 **/

class Area
{
public:
    //exceptions
    enum ERRORS{negative_water_level};

    //constructor
    Area(const std::string& area, const std::string& owner, int waterlevel = 0);


    //getters
    int getWaterLevel()const {return water_level;}
    std::string getAreaType()const{return area_type;}
    std::string getAreaOwner()const{return area_owner;}

    //setters
    void setAreaType(const std::string& area){area_type = area;}
    void setAreaOwner(const std::string& owner){area_owner = owner;}
    void setWaterLevel(int level){water_level += level;}
    
    //gonna use it in Weather class; providing a negative parameter, to decrease the level 


    //virtual methods
    virtual Area* changeArea() = 0;
    virtual void changeWaterLevelAreaHumidity(Weather* season) = 0;



protected:   
    std::string area_type, area_owner; 
    size_t water_level;
};


class Plain: public Area{
public:

    //constructor
    Plain(const std::string& area, const std::string& owner, int waterlevel = 0): Area(area, owner, waterlevel){}

    //virtual function override
    Area* changeArea() override; 
    void changeWaterLevelAreaHumidity(Weather* season) override;
    
};

class Grassland: public Area{

public:

    //constructor
    Grassland(const std::string& area, const std::string& owner, int waterlevel = 0): Area(area, owner, waterlevel){}
    Area* changeArea() override;
    void changeWaterLevelAreaHumidity(Weather* season) override;
     
};

class Lake: public Area{

public:

    //constructor
    Lake(const std::string& area, const std::string& owner, int waterlevel = 0): Area(area, owner, waterlevel){}

    //virtual method override
    Area* changeArea() override; 
    void changeWaterLevelAreaHumidity(Weather* season) override;
};



#endif //AREA_H