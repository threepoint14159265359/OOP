#include <iostream>
#include <fstream>
#include <vector>
#include "Weather.h"
#include "Area.h"

using std::cout; 
using std::endl;



void CreateAreas(const std::string& filename, std::vector<Area*>& areas, std::vector<Weather*>& weathers){
    std::ifstream file(filename);
    if(file.fail()) { cout << "Wrong file name!\n"; exit(1);}    
    Area* type;
    std::string grassland = "Grassland", lake = "Lake", plain = "Plain", Mr, AreaOwner; 
    int numberOfAreas, waterLevel, input_humdidity; 
    char letter;
    file >> numberOfAreas; 
    try{
        for(int i = 0; i<numberOfAreas; i++){
            file >> Mr >> AreaOwner >> letter >> waterLevel; 
            if( letter == 'G'){
                type = new Grassland(grassland, AreaOwner, waterLevel);
                areas.push_back(type);
            }else if (letter  == 'P'){
                type = new Plain(plain, AreaOwner, waterLevel);
                areas.push_back(type);
            }else{
                type = new Lake(lake, AreaOwner, waterLevel);
                areas.push_back(type);
            }
        }  
    }catch(Area::ERRORS e){
        cout << "ERROR! the water level can't be negative!" << endl;
    }
    file >> input_humdidity;
    Weather* weather, *res;
    res = weather->ChangeWeather(input_humdidity);
    weathers.push_back(res);
}

void simulate(const std::string& filename, std::vector<Area*>& areas, std::vector<Weather*>& weathers){
    CreateAreas(filename, areas, weathers);  
    for(auto a: areas){
        cout << "Mr. " << a->getAreaOwner() << " " << a->getAreaType() << " " << a->getWaterLevel() << endl;
    }
    cout << "Season: " << weathers.at(0)->getWeatherType() << " " << weathers.at(0)->getAirHumidity() << endl; 
    for(int i = 0; i<areas.size(); i++){
        Weather* currentWeather = weathers.at(i);
        //change water and humidity
        areas.at(i)->changeWaterLevelAreaHumidity(currentWeather);

        //change Weather 
        currentWeather = currentWeather->ChangeWeather(weathers.at(i)->getAirHumidity());
        //push it to the vector 

        weathers.push_back(currentWeather);

        //chnage area 
        areas.at(i)->changeArea();


        cout << "Mr. " << areas.at(i)->getAreaOwner() << " " << areas.at(i)->getAreaType() << " " << areas.at(i)->getWaterLevel() << endl << endl;
        cout << "Season: " << weathers.at(i+1)->getWeatherType() << " " << weathers.at(i+1)->getAirHumidity() << endl; 
    }    

     
}



int main(){
    std::vector<Area*> ground;
    std::vector<Weather*> weathers; 
    simulate("input.txt", ground, weathers);
    return 0;
}