#include <iostream>
#include <fstream>
#include <vector>
#include "Weather.h"
#include "Area.h"

using std::cout; 
using std::endl;



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
    file >> humidity;
}

void simulate(const std::string& filename, std::vector<Area*>& areas, Weather* &weather, int &humidity){
    CreateAreas(filename, areas, humidity); 


    //setting up our first weather
    weather->ChangeWeather(humidity);
    //printitng first weather
    cout << "Season: " << weather->getWeatherType() << " " << weather->getAirHumidity() << endl; 
    

    for(int i = 0; i< 40; i++){
        for (auto a: areas){
            try{
                //debug change the area #perfectly normal
                a = a->changeArea();

                //debug change humidity #perfectly normal
                weather->changeAirHumidity(a);

                //debug change season #pefectly normal 
                weather->ChangeWeather(weather->getAirHumidity()); 

                //debug change water level #perfectly normal
                a->changeWaterLevel(weather);


                cout << "Mr. " << a->getAreaOwner() << " " << a->getAreaType() << " " << a->getWaterLevel() << endl;
            }
            catch(...){
                cout << "Water level can't be negative" << endl;
                exit(1); 
            }
        }
        cout << endl << weather->getWeatherType() << " " << weather->getAirHumidity() << endl;
    }
}



int main(){
    std::vector<Area*> ground;
    Weather* weather = new Weather("Sunny", 0);
    int humidity;
    simulate("input.txt", ground, weather, humidity);
    return 0;
}