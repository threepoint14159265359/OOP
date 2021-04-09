#include <iostream>

#include "line_iter.h"
#include "group_iter.h"
using namespace std;

race_info first_racer_search_(const std::string& filename){
    line_iter ll(filename);
    race_info result;
    result.stage_18_completion_in_lessMin = false;
    for(ll.first(); !ll.end(); ll.next()){
        if(ll.Current().stage_18_completion_in_lessMin){
            result = ll.Current();
            break;
        }
    }
    return result;
}

race_data greatest_team_search(const std::string& filename){
    group_iter gg(filename);
    race_data result;
    result.exists = false;
    int max = 0; ///count in real world starts from 1, So anything is greater than 0

    for(gg.first(); !gg.end(); gg.next()){
        //debug:
//        cout <<"-----------"<<endl;
//
//        cout << " team : " << gg.Current().team << " no of team mems: " <<  gg.Current().number_of_team_members << endl;
//
//        cout << " -----------" << endl;

        if( gg.Current().number_of_team_members > 4 && gg.Current().cnt_racers_completing_stage_eighteen > max){
            max = gg.Current().cnt_racers_completing_stage_eighteen;
            result.exists = true;
            result.team = gg.Current().team;
            result.cnt_racers_completing_stage_eighteen = gg.Current().cnt_racers_completing_stage_eighteen;
        }
    }

    return result;
}



int main()
{
    std::string filename = "input.txt";
    try{
        race_info race1 = first_racer_search_(filename);
        if (race1.stage_18_completion_in_lessMin){
            cout  << race1.racer_name <<  " completed the STAGE_18 in less than 400 minutes." <<endl;
        }else{
            cout << "There is no racer with the matched description!" << endl;
        }
    }catch(...){
        cout << "file error!" << endl;
    }

    try{
        race_data race1 = greatest_team_search(filename);
        if (race1.exists){
            cout  << race1.team <<  " has the maximum number of racers completing the stage 18. The number of member is: " << race1.cnt_racers_completing_stage_eighteen <<endl;
        }else{
            cout << "There is no team with the matched description!" << endl;
        }
    }catch(...){
        cout << "file error!" << endl;
    }

    return 0;
}
