#include <iostream>
#include "include/group_iter.h"
#include "include/line_iter.h"
using namespace std;



void average_weight(const std::string &filename){
    group_iter iter(filename);
    float average;
    ///not working with for loop
    iter.first();
    if(iter.Current().cnt_of_measurement > 0){
        average = iter.Current().added_weight/iter.Current().cnt_of_measurement;
    }else{
        average = 0; 
    }
    cout << iter.Current().name << "\t average weight: " << average << endl;
    while(!iter.end()){
        iter.next();
        if(iter.Current().cnt_of_measurement > 0){
            average = iter.Current().added_weight/iter.Current().cnt_of_measurement;
        }else{
            average = 0; 
        }
        cout << iter.Current().name << "\t average weight: " << average << endl;
    }
}


int main(){
    average_weight("testfiles/dataset1.txt");
    return 0;
}
