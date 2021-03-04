#include <iostream>
#include "menu.h"
#include "../read.hpp"
#include <sstream>
#define menudb 5

using namespace std;

inline bool ChessType(int a){return a!=0;}
inline bool check(int a){return a>=0 && a<=menudb;}
inline bool MenuCheck(int a){return a>=0 && a <3;}
inline bool entryCheck(int a){return a>=2 && a % 2 == 0;}


void CLEARSCREEN(){
#ifdef _WIN64
    system("cls");
#endif // _WIN64
#ifdef __linux
    system("clear");
#endif // __linux
#ifdef __unix
    system("clear");
#endif
}

void Menu::run()
{
    std::string msg = "ENTER ENTER TO RETURN";
    int v;
    do{
        v=printMenu();
        switch(v)
        {
            case 1:
                add();
                //if(m_output.getSize() != 0){ //if the size of the matrix is zero that means that the user  wants to just go back in the menu
                    print();
                    cout << msg;
                    cin.get();
                //}
                break;
            case 2:
                multiply();
                cout << "OKAY";
                print();
                cout << "THIS SHOULD WORK";
                cout << msg;
                cin.get();
                break;
            case 3:
               // getElem();
              //  print();
                break;
            case 4:
                print();
                cout << msg;
                cin.get();
                break;
            case 5:
               // loadTest();
                break;
            default:
                cout<<"\nGoodbye!\n";
                break;

        }
    }while(v!=0);
}

int Menu::printMenu() const
{
    CLEARSCREEN();
    int response;
    cout<<"\n****************************************\n";
    cout<<"0. EXIT\n";
    cout<<"1. ADD TWO CHESS TYPE MATRICES\n";
    cout<<"2. MULTIPLY TWO CHESS TYPE MATRICES\n";
    cout<<"3. GET AN ELEMENT OF A CHESS TYPE MATRIX WITH TWO INDECES?\n";
    cout<<"4. PRINT\n";
    cout<<"5. Load test\n";
    cout<<"****************************************\n";
    //produce error message
    ostringstream s;
    s<<"It has to be a number between 0 and "<<menudb<<"!";
    string errmsg=s.str();
    //read using read.hpp
    response=read<int>("==>CHOICE:",errmsg,check);

    return response;
}

void Menu::add(){
top:CLEARSCREEN();
    cout << endl << endl;
    std::string filename1, filename2;
    int option;
    cout << "*************************************************\n";
    std::string msg = "0. RETURN TO MAIN MENU\n1. ADD TWO MATRICES FROM TWO DIFFERENT TEXT FILES\n2. ENTER MATRICES MANUALLY\n";
    cout << msg;
    cout << "*************************************************\n";
    std::string errmsg = "It has to be a number between 0 and 2!";
    option=read<int>("==>CHOICE:",errmsg, MenuCheck);
    switch(option){
default:
    return;
case 1:
        CLEARSCREEN();
        cout << "ENTER THE NAME AND THE COMPLETE PATH OF FILE 1: ";
        cin >> filename1;
        try{
            ChessMatrix M1(filename1);
            m_output = M1; //copy the first matrix
        }catch(ChessMatrix::ERRORS e){
            cout << "[ERROR OPENING, please try again with a different file.]";
            goto top;
        }
        cout << "ENTER THE NAME AND THE COMPLETE PATH OF FILE 2: ";
        cin >> filename2;
        try{
            ChessMatrix M2(filename2);
            m_output = m_output + M2; // add the second matrix
        }catch(ChessMatrix::ERRORS e){
            cout << "ERROR OPENING FILE, please try again with a different file.]";
            goto top;
        }
        break;


    case 2:
        CLEARSCREEN();
        unsigned int SIZE;
        std::vector<int> db;
        std::string sizeErr = "ERROR, PLEASE ENTER THE SIZE (an integer number) OF CHESS-TYPE MATRIX.";
        std::string vecErr = "ERROR, PLEASE ENTER NON-ZERO ENTRIES.";
        SIZE=read<int>("SIZE1:",sizeErr,entryCheck);
        cout << "ENTER YOUR DATA HERE: " << endl;
        for(unsigned int i = 0; i<SIZE * (SIZE/2); i++){
            cout << i+1;
            db.push_back(read<int>(" . ", vecErr, ChessType));
        }
        //create a matrix
        ChessMatrix m1(db);
        db.clear(); //clear the matrix so that we could take the input again in the same vector
        SIZE=read<int>("SIZE2:",sizeErr,entryCheck);
        cout << "ENTER YOUR DATA HERE: " << endl;
        for(unsigned int i = 0; i<SIZE * (SIZE/2); i++){
            cout << i+1;
            db.push_back(read<int>(" . ", vecErr, ChessType));
        }
        ChessMatrix m2(db);
        try{
            m_output = m1 + m2;
        }catch(ChessMatrix::ERRORS e){
            cout << "ERROR, CANNOT SUM MATRICES OF DIFFERENT SIZES. Please Try again\nENTER ANY KEY TO RETURN: " << endl;
            cin.get();
            goto top;
        }
        break;

    }

}


void Menu::multiply(){
top:CLEARSCREEN();
    cout << endl << endl;
    std::string filename1, filename2;
    int option;
    cout << "*************************************************\n";
    std::string msg = "0. RETURN TO MAIN MENU\n1. MULTIPLY TWO MATRICES FROM TWO DIFFERENT TEXT FILES\n2. ENTER MATRICES MANUALLY\n";
    cout << msg;
    cout << "*************************************************\n";
    std::string errmsg = "It has to be a number between 0 and 2!";
    option=read<int>("==>CHOICE:",errmsg,MenuCheck);
    switch(option){
    default:
    return;
    case 1:
        CLEARSCREEN();
        cout << "ENTER PATH TO FILE 1: ";
        cin >> filename1;
        try{
            ChessMatrix M1(filename1);
            m_output = M1; // copy the first one to the output
        }catch(ChessMatrix::ERRORS e){
            cout << "[ERROR OPENING, please try again with a different file.]";
            goto top;
        }
        cout << "ENTER PATH TO FILE 2: ";
        cin >> filename2;
        try{
            ChessMatrix M2(filename2);
            m_output = m_output * M2; // Multiply the second matrix by the copied one
        }catch(ChessMatrix::ERRORS e){
            cout << "ERROR OPENING FILE, please try again with a different file.]";
            goto top;
        }
        break;

    case 2:
        CLEARSCREEN();
        unsigned int SIZE;
        std::vector<int> db;
        std::string sizeErr = "ERROR, PLEASE ENTER THE SIZE (an integer number) OF CHESS-TYPE MATRIX.";
        std::string vecErr = "ERROR, PLEASE ENTER NON-ZERO ENTRIES.";
        SIZE=read<int>("SIZE1:",sizeErr,entryCheck);
        cout << "ENTER YOUR DATA HERE: " << endl;
        for(unsigned int i = 0; i<SIZE * (SIZE/2); i++){
            cout << i+1;
            db.push_back(read<int>(" . ", vecErr, ChessType));
        }
        //create a matrix
        ChessMatrix m1(db);
        db.clear(); //clear the matrix so that we could take the input again in the same vector
        SIZE=read<int>("SIZE2:",sizeErr,entryCheck);
        cout << "ENTER YOUR DATA HERE: " << endl;
        for(unsigned int i = 0; i<SIZE * (SIZE/2); i++){
            cout << i+1;
            db.push_back(read<int>(" . ", vecErr, ChessType));
        }
        ChessMatrix m2(db);
        try{
            m_output = m1 * m2;
        }catch(ChessMatrix::ERRORS e){
            cout << "ERROR, CANNOT MULTIPLY MATRICES OF DIFFERENT SIZES. Please Try again\nENTER ANY KEY TO RETURN: " << endl;
            cin.get();
            goto top;
        }
        break;
    }

}

void Menu::print(){
    cout << m_output;
}





