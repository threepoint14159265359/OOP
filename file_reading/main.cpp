#include <iostream> 
#include <fstream> 
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string; 

int main(){
    ifstream f;
    f.open("1.txt");
    if(f.fail()){
        cout << "file is corrupt!" << endl;
    }

    /**
     * file is read line by line. 
     * After the first execution, ifstream reads first line 
     * After exection of the same line of code, it reads second line and so on...
     */

    int x; 
    f >> x; // reads the first integer
    cout << x << endl;
    f >> x; // reads the second integer
    cout << x << endl;
    f >> x; //reads the third integer
    cout << x << endl;
    ///same thing for strings;
    string str = "0";
    getline(f, str);  //this will read empty string, because after reading third line above in the x, the execution of the ifstream ptr is still on that line, which is actually empty 
    cout << str << endl; 
    getline(f, str); //reads fourth line
    cout << str << endl;
    getline(f, str); //reads fifth line
    cout << str << endl;
    return 0;
}