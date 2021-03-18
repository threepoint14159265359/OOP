#include <iostream>
#include <string>
#include <fstream> // file stream library

using namespace std;

void DOUBLE_1(int number){
    number *= 2; 
    cout << number << endl;
}

void DOUBLE_2(int &number){
    number *= 2; 
    cout << number << endl;
}


int main()
{
    //Passing argument by value
    int number = 10;
    DOUBLE_1(10);
    cout << "\n" << number << endl; ///this number is not changed ('coz it was just copied)

    //Passing argument by reference
    DOUBLE_2(number);

    cout << "\n" << number << endl; //now the number will be changed 


    //reading a file word by word
    ifstream ifile; // initialize input file stream object
    ifile.open("files/test.txt"); //open the -- relative path
    "files/test.txt";
    if(ifile.fail()){
        cout << "The file can't be opened!" << endl;
        exit(1);
    }
    string word;
    while(ifile >> word){
        cout << word << endl;
    }
    //close the file
    ifile.close();

    cout << "\n\n" << ifile.is_open() << "\n\n";

    //reading a file line by line
    ifile.open("files/test.txt");
    string line;
    getline(ifile, line);
    while(ifile){
        cout << line << endl;
        getline(ifile, line);
    }
    //close the file
    ifile.close();
    return 0;
}
