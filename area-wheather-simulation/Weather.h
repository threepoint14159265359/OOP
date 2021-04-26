#ifndef WEATHER_H
#define WEATHER_H

#include "Area.h" //already has imported constants.h

class Plain;
class Rainy; 
class Cloudy;


class Weather
{

public:   
    Weather(){}
    Weather(int humidity);

    Weather* determinWeather();
    //will use changeWaterLevel() from Area class here => overrideing the following function for each weather
    virtual Weather* changeWaterLevel(Grassland *grassland) =0;
    virtual Weather* changeWaterLevel(Plain *plain) = 0;
    virtual Weather* changeWaterLevel(Lake *lake) = 0;
    virtual ~Weather(){};

    void changeHumdity(int humid){humidity += humid;}
    int getHumidity(){return humidity;}
protected:
    int humidity;
    
};


class Sunny: public Weather{
public:
    static Sunny* instance();
    static void destroy();

    //virtual methods override
    Weather* changeWaterLevel(Grassland *grassland) override;
    Weather* changeWaterLevel(Plain *plain) override;
    Weather* changeWaterLevel(Lake *lake) override;
protected:
    Sunny(){} 
private:
    static Sunny *s_instance; 
};




class Rainy: public Weather{
public:
    static Rainy* instance();
    static void destroy();

    //virtual methods override
    Weather* changeWaterLevel(Grassland *grassland) override;
    Weather* changeWaterLevel(Plain *plain) override;
    Weather* changeWaterLevel(Lake *lake) override;

protected:
    Rainy(){}
private:
    static Rainy* r_instance; 
};




class Cloudy: public Weather{
public:
    static Cloudy* instance();
    static void destroy();

    //virtual methods ovverride
    Weather* changeWaterLevel(Grassland *grassland) override;
    Weather* changeWaterLevel(Plain *plain) override;
    Weather* changeWaterLevel(Lake *lake) override;  
    
protected:
    Cloudy(){}
private:
    static Cloudy* c_instance;
};






#endif //WEATHER_H