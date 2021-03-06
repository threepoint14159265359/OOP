#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include "Area.h" //already has imported constants.h

class Area; 
class Plain; 
class Grassland; 
class Lake; 


class Weather
{

public:   
    //constructor
    Weather(){}
    Weather(const std::string& weathertype, int humid){weatherType = weathertype; air_humidity = humid;}
    

    //setters
    void setHumidity(int humidity){air_humidity = humidity;}
    void setType(const std::string& type){weatherType = type;}

    //getters
    std::string getWeatherType(){return weatherType;}
    int getAirHumidity(){return air_humidity;}

    //member functions
    void ChangeWeather(int humid);
    void changeAirHumidity(Area* area);
    virtual ~Weather(){}

protected:
    std::string weatherType;
    int air_humidity;
};


class Sunny: public Weather{
public:
    //constructor 
    Sunny(const std::string& name, int humid): Weather(name, humid) {}

};




class Rainy: public Weather{
public:
    //constructor
    Rainy(const std::string& name, int humid): Weather(name, humid) {}
};




class Cloudy: public Weather{
public:
    //constructor
    Cloudy(const std::string& name, int humid): Weather(name, humid) {}

};






#endif //WEATHER_H