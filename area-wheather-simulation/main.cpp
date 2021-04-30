#include <iostream>
#include <fstream>
#include <vector>
#include "Weather.h"
#include "Area.h"

using std::cout; 
using std::endl;


struct areaWeatherContainer{
    Area* area; 
    Weather* weather;
};

void CreateAreas(const std::string& filename, std::vector<Area*>& areas, int &humidity){
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
            }else if (letter  == 'P'){
                type = new Plain(plain, AreaOwner, waterLevel);
            }else{
                type = new Lake(lake, AreaOwner, waterLevel);
            }
            areas.push_back(type);
        }  
    }catch(Area::ERRORS e){
        cout << "ERROR! the water level can't be negative!" << endl;
    }
    file >> humidity;
}

void simulate(const std::string& filename, std::vector<Area*>& areas, Weather* &weather, int &humidity){
    CreateAreas(filename, areas, humidity);  
    weather->setHumidity(humidity);

    for(int i = 0; i<20; i++){
        try{
        for (int j = 0; j < areas.size(); j++){

            //debug change water level #perfectly normal
            areas.at(j)->changeWaterLevel(weather);

            //debug change humidity #perfectly normal
            //cout << weather->getAirHumidity() << endl;
            weather->changeAirHumidity(areas.at(j));
            //cout << weather->getAirHumidity() << endl;

            //debug change season #pefectly normal 
            weather->ChangeWeather(weather->getAirHumidity());

            //debug change the area #perfectly normal
            areas[j] = areas.at(j)->changeArea();
            
            
             
            //cout << "Mr. " << areas.at(j)->getAreaOwner() << " " << areas.at(j)->getAreaType() << " " << areas.at(j)->getWaterLevel() << endl;
        }
        //cout << endl << weather->getWeatherType() << " " << weather->getAirHumidity() << endl;
    }catch(...){
        cout << "Water level can't be negative" << endl;
        exit(1); 
    }
    }
        
}



int main(){
    std::vector<Area*> ground;
    Weather* weather = new Weather("Sunny", 0);
    int humidity;
    simulate("input.txt", ground, weather, humidity);
    return 0;
}




