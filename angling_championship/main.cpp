#include <iostream>
#include "contest.h"

using namespace std;


int noFishContestCount(const std::string &filename){
    contest e(filename);
    int cnt = 0;
    for(e.first(); !e.end(); e.next()){
        if(e.current().counter == 0){
            cnt++;
        }
    }
    return cnt;
}

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


int main()
{
    std::string filename = "t7.txt";
    cout << noFishContestCount(filename) << endl;
    contest_data max = mostFishOnOneContest(filename);
    cout << max.angler_name << " " << max.contest_id << " " << max.counter << " " << endl;
    return 0;
}
