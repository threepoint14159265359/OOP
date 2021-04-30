#define CATCH_CONFIG_MAIN 
#include <iostream>
#include <fstream>
#include <vector>
#include "Weather.h"
#include "Area.h"
#include "catch.hpp"



/**
 * Random inputs for water level at different areas. Solutions worked out by hand.
 * Unit tests for changeWaterLevel(Weather* weather) method.
 */
TEST_CASE("changeWaterLevel() CASE 1", "Area Lake, Seasons: Sunny, Rainy, Cloudy"){
    Weather* sunny = new Sunny("Sunny", 36);
    Weather* rainy = new Rainy("Rainy", 68);
    Weather* cloudy = new Cloudy("Cloudy", 45);

    //lake
    Area* lake = new Lake("Lake", "Mr. Mike", 83);

    //SUNNY
    lake->changeWaterLevel(sunny); 
    REQUIRE(lake->getWaterLevel() == 73); //reduced by 10

    //RAINY (the waterlevel is asummed to be 73 now)
    lake->changeWaterLevel(rainy);
    REQUIRE(lake->getWaterLevel() == 93); //increased by 20 

    //Cloudy (the waterleve is assumed to be 93)
    lake->changeWaterLevel(cloudy);
    REQUIRE(lake->getWaterLevel() == 90); //reduced by 3
}

TEST_CASE("changeWaterLevel() CASE 2", "Area Grassland, Seasons: Sunny, Rainy, Cloudy"){
    Weather* sunny = new Sunny("Sunny", 36);
    Weather* rainy = new Rainy("Rainy", 68);
    Weather* cloudy = new Cloudy("Cloudy", 45);

    //Grassland
    Area* grassland = new Grassland("Grassland", "Mr. Mike", 36);

    //SUNNY
    grassland->changeWaterLevel(sunny); 
    REQUIRE(grassland->getWaterLevel() == 30); //reduced by 6

    //RAINY (the waterlevel is asummed to be 30 now)
    grassland->changeWaterLevel(rainy);
    REQUIRE(grassland->getWaterLevel() == 45); //increased by 15 

    //Cloudy (the waterlevel is assumed to be 45)
    grassland->changeWaterLevel(cloudy);
    REQUIRE(grassland->getWaterLevel() == 43); //reduced by 3
}

TEST_CASE("changeWaterLevel() CASE 3", "Area Plain, Seasons: Sunny, Rainy, Cloudy"){
    Weather* sunny = new Sunny("Sunny", 36);
    Weather* rainy = new Rainy("Rainy", 68);
    Weather* cloudy = new Cloudy("Cloudy", 45);

    //Plain
    Area* plain = new Plain("Plain", "Mr. Mike", 14);

    //SUNNY
    plain->changeWaterLevel(sunny); 
    REQUIRE(plain->getWaterLevel() == 11); //reduced by 3

    //RAINY (the waterlevel is asummed to be 11 now)
    plain->changeWaterLevel(rainy);
    REQUIRE(plain->getWaterLevel() == 31); //increased by 20

    //Cloudy (the waterlevel is assumed to be 31)
    plain->changeWaterLevel(cloudy);
    REQUIRE(plain->getWaterLevel() == 30); //reduced by 1
}


TEST_CASE("changeWaterLevel() CASE 4", "Areas: all inclusive, Negative Value for water"){
    CHECK_THROWS(new Plain("Plain", "Mr. Bean", -1));
    CHECK_THROWS(new Grassland("Plain", "Mr. Bean", -1));
    CHECK_THROWS(new Lake("Plain", "Mr. Bean", -1));
}


/***
 * Unit Tests for the changeArea() method. 
 */
TEST_CASE("changeArea() Case 1", "Areas: all inclusive, changing Area based of of the waterlevel"){
    Area* plain = new Plain("Plain", "Mr. Mike", 16); //expected new Grassland
    Area* grassland1 = new Grassland("Grassland", "Mr. Mike", 15); //expected new plain
    Area* grassland2 = new Grassland("Grassland", "Mr. Mike", 51); //expected new Lake
    Area* lake = new Lake("Lake", "Mr. Mike", 50); //expected Grassland


    //changing
    plain = plain->changeArea();
    REQUIRE(plain->getAreaType() == "Grassland");

    //changing
    grassland1 = grassland1->changeArea();
    REQUIRE(grassland1->getAreaType() == "Plain");
    grassland2 = grassland2->changeArea();
    REQUIRE(grassland2->getAreaType() == "Lake");

    //changing
    lake = lake->changeArea();
    REQUIRE(lake->getAreaType() == "Grassland");
}

TEST_CASE("changeArea() case 2", "Vector of areas"){
    std::vector<Area*> container; 
    container.push_back(new Plain("Plain", "Mr. Mike", 15)); //shouldn't change
    container.push_back(new Plain("Plain", "Mr. Mike", 0)); //shouldn't change
    container.push_back(new Plain("Plain", "Mr. Mike", 40)); //expected new Grassland
    container.push_back(new Plain("Plain", "Mr. Mike", 40));  //expected new Grassland
    container.push_back(new Plain("Plain", "Mr. Mike", 400000));  //expected new Grassland
    container.push_back(new Grassland("Grassland", "Mr. Mike", 16)); //shouldn't change
    container.push_back(new Grassland("Grassland", "Mr. Mike", 15)); //expected new Plain
    container.push_back(new Grassland("Grassland", "Mr. Mike", 0)); //expected new Plain 
    container.push_back(new Grassland("Grassland", "Mr. Mike", 1000)); //expected new Lake
    container.push_back(new Grassland("Grassland", "Mr. Mike", 50)); //shouldn't cange
    container.push_back(new Lake("Lake", "Mr. Mike", 15)); //expected new Grassland
    container.push_back(new Lake("Lake", "Mr. Mike", 50)); //expected new Grassland
    container.push_back(new Lake("Lake", "Mr. Mike", 100)); //shouldn't change
    container.push_back(new Lake("Lake", "Mr. Mike", 0));  //expected new Grassland
    container.push_back(new Lake("Lake", "Mr. Mike", 100000)); //shouldn't change


    for(int i = 0; i<15; i++){
        container[i] = container[i]->changeArea();
    }

    REQUIRE(container.at(0)->getAreaType() == "Plain");
    REQUIRE(container.at(1)->getAreaType() == "Plain");
    REQUIRE(container.at(2)->getAreaType() == "Grassland");
    REQUIRE(container.at(3)->getAreaType() == "Grassland");
    REQUIRE(container.at(4)->getAreaType() == "Grassland");
    REQUIRE(container.at(5)->getAreaType() == "Grassland");
    REQUIRE(container.at(6)->getAreaType() == "Plain");
    REQUIRE(container.at(7)->getAreaType() == "Plain");
    REQUIRE(container.at(8)->getAreaType() == "Lake");
    REQUIRE(container.at(9)->getAreaType() == "Grassland");
    REQUIRE(container.at(10)->getAreaType() == "Grassland");
    REQUIRE(container.at(11)->getAreaType() == "Grassland");
    REQUIRE(container.at(12)->getAreaType() == "Lake");
    REQUIRE(container.at(13)->getAreaType() == "Grassland");
    REQUIRE(container.at(14)->getAreaType() == "Lake");
}


/**
 * Unit tests for changeAirHumidity(Area* area).
 * NOTE: it does't depend upon the weather
 */

TEST_CASE("changeAirHumidity() Case 1", "Season: all inclusive, Area: all inclusive"){
    Weather* sunny = new Sunny("Sunny", 36);
    Weather* rainy = new Rainy("Rainy", 68);
    Weather* cloudy = new Cloudy("Cloudy", 45);

    Area* plain = new Plain("Plain", "Mr. Mike", 14);
    Area* lake = new Lake("Lake", "Mr. Mike", 83);
    Area* grassland = new Grassland("Grassland", "Mr. Mike", 36);

    //SUNNY
    sunny->changeAirHumidity(plain); //expected air_humidity = 41
    REQUIRE(sunny->getAirHumidity() == 41);

    sunny->changeAirHumidity(lake); //expected air_humidity = 41+15
    REQUIRE(sunny->getAirHumidity() == 56);

    sunny->changeAirHumidity(grassland); //expected air_humidity = 41 + 15 + 10
    REQUIRE(sunny->getAirHumidity() == 66);

    //RIANY
    rainy->changeAirHumidity(plain); //expected air_humidity = 68 + 5
    REQUIRE(rainy->getAirHumidity() == 73);

    rainy->changeAirHumidity(lake); //expected air_humidity = 68 + 5 + 15
    REQUIRE(rainy->getAirHumidity() == 88);

    rainy->changeAirHumidity(grassland); //expected air_humidity = 68 + 5 + 15 + 10
    REQUIRE(rainy->getAirHumidity() == 98);


    //RIANY
    cloudy->changeAirHumidity(plain); //expected air_humidity = 45 + 5
    REQUIRE(cloudy->getAirHumidity() == 50);

    cloudy->changeAirHumidity(lake); //expected air_humidity = 45 + 5 + 15
    REQUIRE(cloudy->getAirHumidity() == 65);

    cloudy->changeAirHumidity(grassland); //expected air_humidity = 45 + 5 + 15 + 10
    REQUIRE(cloudy->getAirHumidity() == 75);
}


TEST_CASE("changeWeather() Case 1", "Seasons: all inclusive, Areas: doesn't depend upon area"){
    Weather* sunny = new Sunny("Sunny", 36);
    Weather* rainy = new Rainy("Rainy", 68);
    Weather* cloudy = new Cloudy("Cloudy", 45);
    
    int newHumidity = 41; 
    sunny->ChangeWeather(newHumidity); //expected weatherType = "Cloudy"
    REQUIRE(sunny->getWeatherType() == "Cloudy");

    newHumidity = 70;
    sunny->ChangeWeather(newHumidity); //expected weatherType  = "Rainy"
    REQUIRE(sunny->getWeatherType() == "Rainy");
    
    newHumidity = 69;
    rainy->ChangeWeather(newHumidity); //expected weatherType = "Cloudy"
    REQUIRE(rainy->getWeatherType() == "Cloudy");

    newHumidity = 39; 
    rainy->ChangeWeather(newHumidity);
    REQUIRE(rainy->getWeatherType() == "Sunny");
}
