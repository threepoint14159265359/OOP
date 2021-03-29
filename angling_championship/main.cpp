#include <iostream>
#include "contest.h"
#include "angler.h"

using std::cout;
using std::endl;
using std::cin;



//task one
contest_data mostFishOnOneContest(const std::string &filename){
    contest e(filename);
    e.first();
    contest_data max = e.current();
    for(; !e.end(); e.next()){
        if(e.current().counter > max.counter ){
            max = e.current();
        }
    }
    return max;
}

//task two
int noFishContestCount(const std::string &filename){
    int cnt = 0;
    angler e(filename);
    for(e.first(); !e.end(); e.next()){
        if(e.current().no_fish_count == 0){
            cnt++;
        }
    }
    return cnt;
}


//#define NORMAL_MODE
#ifdef NORMAL_MODE


int main()
{
    std::string filename;
    cout << "Please enter the name of the file: "; cin >> filename;
    //task one
    try{
        contest_data angl  =  mostFishOnOneContest(filename);
        cout << "Mr. " <<  angl.angler_name << " has caught most fish in one contest. Contest Name: " << angl.contest_id << ", Number of fish: " << angl.counter << endl;
    }catch(contest::errors e){
        if(e == contest::errors::corrupt_file){
            cout << "Can't open file " << filename << endl;
        }
        cout << "Unknown Error!" << endl;
    }

    //task two
    try{
        int cnt;
        cnt = noFishContestCount(filename);
        cout << "The number of contests where there was no fish caught is : " << cnt << endl;
    }catch(contest::errors e){
        if(e == contest::errors::corrupt_file){
            cout << "Can't open file " << filename << endl;
        }
        cout << "Unknown Error!" << endl;
    }

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//maximum algorithm pattern
TEST_CASE("EMTPY FILE | TASK ONE", "t0.txt") {
    contest_data t = mostFishOnOneContest("t0.txt");
    CHECK(t.angler_name == "");
    CHECK(t.contest_id == "");
    CHECK(t.counter == 0);
}

TEST_CASE("CORRECT CASE | TASK ONE", "t7.txt") {
    contest_data t = mostFishOnOneContest("t7.txt");
    CHECK(t.angler_name == "Bob");
    CHECK(t.contest_id == "Kiliti0512" );
    CHECK(t.counter == 3);
}

TEST_CASE("INCORRECT FILE NAME | TASK ONE", "idk.txt"){
    contest_data t;
    CHECK_THROWS(t = mostFishOnOneContest("idk.txt"));
}

TEST_CASE("ALL ANGLERS HAVE CAUGHT SAME NUMBER OF FISH | TASK ONE", "tt4.txt"){
    contest_data t = mostFishOnOneContest("tt4.txt");
    CHECK(t.angler_name == "Peter");
    CHECK(t.contest_id == "Kiliti0512" );
    CHECK(t.counter == 3);
}

TEST_CASE("ALL ANGLERS HAVE CAUGHT ZERO FISH | TASK ONE", "tt3.txt"){
    contest_data t = mostFishOnOneContest("tt3.txt");
    CHECK(t.angler_name == "Peter");
    CHECK(t.contest_id == "Kiliti0512" );
    CHECK(t.counter == 0);
}

//count algorithmic pattern
TEST_CASE("EMTPY FILE | TASK TWO", "t0.txt") {
    int t = noFishContestCount("t0.txt");
    CHECK(t == 0);
}

TEST_CASE("CORRECT CASE | TASK TWO", "t7.txt"){
    int t = noFishContestCount("t7.txt");
    CHECK(t==1);
}

TEST_CASE("INCORRECT FILE NAME | TASK TWO", "idk.txt"){
    int t;
    CHECK_THROWS(noFishContestCount("idk.txt"));
}

TEST_CASE("ONE ALL CONTESTS, ONE OR MORE FISH WERE CAUGHT | TASK TWO", "tt5.txt"){
    int t = noFishContestCount("tt5.txt");
    CHECK(t==0);
}

TEST_CASE("ALL THE CONTESTS HAVE NO FISH CAUGHT | TASK TWO", "tt6.txt"){
    int t = noFishContestCount("tt6.txt");
    CHECK(t==3); //worked out by hand
}


#endif







