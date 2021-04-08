#include <iostream>
#include "line_iter.h"
#include "group_iter.h"

using namespace std;

comp_info first_search_fortran_at_most_ten(const std::string &filename){
    line_iter ll(filename);
    comp_info result;
    result.ten_correct_solution = false;
    for(ll.first(); !ll.end(); ll.next()){
        if(ll.Current().ten_correct_solution){
            result = ll.Current();
            break;
        }
    }
    return result;
}


comp_data first_search_fortran_at_most_three(const std::string &filename){
    group_iter gg(filename);
    comp_data result;
    result.areSolutionAtMostThree = false;
    for(gg.first(); !gg.end(); gg.next()){
        if(gg.Current().areSolutionAtMostThree){
            result = gg.Current();
            break;
        }
    }
    return result;
}

int main()
{
    std::string filename = "input.txt";
    try{
        comp_info comp1 = first_search_fortran_at_most_ten(filename);
        if (comp1.ten_correct_solution){
            cout << comp1.year_of_compition << " " << comp1.name << endl;
        }else{
            cout << "There is no language with the matched description!" << endl;
        }
    }catch(...){
        cout << "file error!" << endl;
    }

    try{
        comp_data comp1 = first_search_fortran_at_most_three(filename);
        if (comp1.areSolutionAtMostThree){
            cout << "Year of Competition: " << comp1.year << endl;
        }else{
            cout << "There is no language with the matched description!" << endl;
        }
    }catch(...){
        cout << "file error!" << endl;
    }
    return 0;
}
