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
std::vector<areaWeatherContainer> container; 


bool allEqualAreas();
void CreateAreas(const std::string& filename);
void simulate(const std::string& filename);

int main(){
    simulate("input1.txt");
    return 0;
}

bool allEqualAreas(){
    int i = 0; 
    bool flag = true; 
    for(int i = 0; i<container.size(); i++){
        if( container[i].area->getAreaType() != container[0].area->getAreaType()){
            flag = false;
        }
    }
    return flag; 
}

//reads the file, stores the values in a vector, and reads humidity
void CreateAreas(const std::string& filename){
    std::vector<Area*> areas;
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
    }catch(...){
        cout << "ERROR! the water level can't be negative!" << endl;
    }
    file >> input_humdidity;
    if(numberOfAreas == 1){
        cout << "Mr." << areas[0]->getAreaOwner() << " " << areas[0]->getAreaType() << " " << areas[0]->getWaterLevel() << endl; 
        exit(0);
    }
    Weather* weather = new Weather();
    weather->ChangeWeather(input_humdidity);

    //initially we have the same weather for each area and let's assume that initial weather is arbitrary for each area
    for(auto area: areas){
        container.push_back({area, weather});
    }
}

void simulate(const std::string& filename){
    CreateAreas(filename);  
    //got a vector of areas and Unkown Weather with humidity - that's why we change the weather first
    //since the water level depend upon the weather and now we got the weather - that's why we can change water level now
     
    int i = 0;
    while(!(allEqualAreas())){
        cout << "Simulation Round: " << i+1 << endl; 
        try{
            for(int j = 0; j<container.size(); j++){
                Area* tempArea;
                container[j].weather->changeAirHumidity(container[j].area); //based of of the area in the cont, change the humidity
                container[j].weather->ChangeWeather(container[j].weather->getAirHumidity());
                container[j].area->changeWaterLevel(container[j].weather); //base on the weather in the container, change the water level    
                container[j].area = container[j].area->changeArea();

                cout << "Mr. " << container[j].area->getAreaOwner() << " " << container[j].area->getAreaType() << " " << container[j].area->getWaterLevel()<< endl;
                //cout << container[j].weather->getWeatherType() << " " << container[j].weather->getAirHumidity() << endl; 
            }
        }
        catch(...){
            cout << "Water level can't be negative" << endl;
            exit(1); 
        }

        cout << "==============================================" << endl << endl; 
        i++;
    }
        
}

