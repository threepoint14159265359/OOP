#include <iostream>
#include <fstream>
#include <vector>
#include "Weather.h"
#include "Area.h"

using std::cout; 
using std::endl;

void simulate(const std::string& filename, std::vector<Area*>& areas, std::vector<Weather*>& weathers){
    std::ifstream file(filename);
    Area* type;
    std::string grassland = "Grassland";
    std::string lake = "Lake";
    std::string plain = "Plain"; 
    if(file.fail()) { cout << "Wrong file name!\n"; exit(1);}                                            
    std::string Mr, AreaOwner; 
    int numberOfAreas, waterLevel, Humidity; 
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
    file >> Humidity;
    Weather aux(Humidity);
    Weather* weather = aux.determinWeather();
    weathers.push_back(weather);
    for(auto a: areas){
        
    }
}

int main(){
    std::vector<Area*> ground;
    std::vector<Weather*> season;
    simulate("input.txt",ground,season);
    for(int i = 0; i<ground.size(); i++){
        cout << ground.at(i)->getAreaOwner() << " "<< ground.at(i)->getAreaType() << " " << ground.at(i)->getWaterLevel() << endl;
    }

    cout << endl;
    cout << season.at(0)->getHumidity();
}