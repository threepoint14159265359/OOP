#include <iostream> 
#include <fstream>
#include <string>

using std::ifstream; 
using std::string;
using std::cout;
using std::endl;


int main(){
    ifstream file;
    file.open("t7.txt");
    if(file.fail()){
        cout << "file error!";
        return 1;
    }

    string str;
    file >> str >> str >> str; 
    cout << str << endl;
    return 0;
}
