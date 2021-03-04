#include <iostream>
#include "menu.h"
#include "../read.hpp"
#include <sstream>
#define menudb 5

using namespace std;

inline bool getElemCheck(int a){return a>=0;}
inline bool ChessType(int a){return a!=0;}
inline bool check(int a){return a>=0 && a<=menudb;}
inline bool MenuCheck(int a){return a>=0 && a <3;}
inline bool entryCheck(int a){return a>=2 && a % 2 == 0;}


void CLEARSCREEN(){
#ifdef _WIN32
    system("cls");
#endif // _WIN32
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
    std::string msg = "PRESS ENTER TO RETURN";
    int v;
    do{
        v=printMenu();
        switch(v)
        {
            case 1:
                add();
                if(m_output.getSize() != 0)
                    print();
                cout << msg;
                cin.get();
                break;
            case 2:
                multiply();
                if(m_output.getSize() != 0)
                    print();
                cout << msg;
                cin.get();
                break;
            case 3:
                getElem();
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
    cout<<"3. GET AN ELEMENT OF A CHESS TYPE MATRIX BY GIVEN ROW AND COLUMN\n";
    cout<<"4. PRINT\n";
    cout<<"5. Load test\n";
    cout<<"****************************************\n";
    ostringstream s;
    s<<"**It has to be a number between 0 and "<<menudb<<"!**";
    string errmsg=s.str();
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
    std::string errmsg = "**It has to be a number between 0 and 2!**";
    option=read<int>("==>CHOICE:",errmsg, MenuCheck);
    switch(option){
default:
    return;

    case 1:
        CLEARSCREEN();
        cout << "ENTER THE PATH OF FILE 1: ";
        cin >> filename1;
        try{
            ChessMatrix M1(filename1);
            m_output = M1; //copy the first matrix
        }catch(ChessMatrix::ERRORS e){
            if(e == ChessMatrix::ERRORS::CORRUPT_FILE){
                cout << "**ERROR OPENING FILE, please try again with a different file.**\nPRESS ENTER TO REUTRN";
            }else{
                cout << "**UNKNOW ERROR**\nPRESS ENTER TO RETURN";
            }
            cin.get();
            cin.get();
            goto top;
        }
        cout << "ENTER THE PATH OF FILE 2: ";
        cin >> filename2;
        try{
            ChessMatrix M2(filename2);
            m_output = m_output + M2; // add the second matrix
        }catch(ChessMatrix::ERRORS e){
            if(e == ChessMatrix::ERRORS::CORRUPT_FILE){
                cout << "**ERROR OPENING FILE, please try again with a different file.**\nPRESS ENTER TO REUTRN";
            }else{
                cout << "**UNKNOW ERROR**\nPRESS ENTER TO RETURN";
            }
            cin.get();
            cin.get();
            goto top;
        }
        CLEARSCREEN();
        cin.get();
        break;


    case 2:
        CLEARSCREEN();
        unsigned int SIZE;
        std::vector<int> db;
        std::string sizeErr = "**ERROR, PLEASE ENTER THE SIZE (an integer number) OF CHESS-TYPE MATRIX.**";
        std::string vecErr = "**ERROR, PLEASE ENTER NON-ZERO ENTRIES.**";
        SIZE=read<int>("SIZE1:",sizeErr,entryCheck);
        unsigned int copy = SIZE;
        cout << "ENTER YOUR DATA HERE: " << endl;
        for(unsigned int i = 0; i<SIZE * (SIZE/2); i++){
            cout << i+1;
            db.push_back(read<int>(" . ", vecErr, ChessType));
        }
        //create a matrix
        ChessMatrix m1(db);
        db.clear(); //clear the matrix so that we could take the input again in the same vector
        do{
            SIZE=read<int>("SIZE2:",sizeErr,entryCheck);
            if(SIZE != copy)
                cout << "**ERROR, CANNOT ADD MATRICES OF DIFFERENT SIZES. Please Try again**\nSIZE:" << endl;
        }while(SIZE != copy);
        cout << "ENTER YOUR DATA HERE: " << endl;
        for(unsigned int i = 0; i<SIZE * (SIZE/2); i++){
            cout << i+1;
            db.push_back(read<int>(" . ", vecErr, ChessType));
        }
        ChessMatrix m2(db);
        try{
            m_output = m1 + m2;
        }catch(ChessMatrix::ERRORS e){
            if(e == ChessMatrix::ERRORS::NOT_EQUAL_SIZE){
                cout << "**ERROR, CANNOT MULTIPLY MATRICES OF DIFFERENT SIZES. Please Try again**\nPRESS ENTER TO RETURN: " << endl;
            }else{
                cout << "**UNKNOW ERROR!**\nPRESS ENTER TO RETURN:";
            }
            cin.get();
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
    std::string errmsg = "**It has to be a number between 0 and 2!**";
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
            if(e == ChessMatrix::ERRORS::CORRUPT_FILE){
                cout << "**ERROR OPENING FILE, please try again with a different file.**\nPRESS ENTER TO REUTRN";
            }else{
                cout << "**UNKNOW ERROR**\nPRESS ENTER TO RETURN";
            }
            cin.get();
            cin.get();
            goto top;
        }
        cout << "ENTER PATH TO FILE 2: ";
        cin >> filename2;
        try{
            ChessMatrix M2(filename2);
            m_output = m_output * M2; // Multiply the second matrix by the copied one
        }catch(ChessMatrix::ERRORS e){
            if(e == ChessMatrix::ERRORS::CORRUPT_FILE){
                cout << "**ERROR OPENING FILE, please try again with a different file.**\nPRESS ENTER TO REUTRN";
            }else{
                cout << "**UNKNOW ERROR**\nPRESS ENTER TO RETURN";
            }
            cin.get();
            cin.get();
            goto top;
        }
        CLEARSCREEN();
        cin.get();
        break;

    case 2:
        CLEARSCREEN();
        unsigned int SIZE;
        std::vector<int> db;
        std::string sizeErr = "**ERROR, PLEASE ENTER THE SIZE (an integer number) OF CHESS-TYPE MATRIX.**";
        std::string vecErr = "**ERROR, PLEASE ENTER NON-ZERO ENTRIES.**";
        SIZE=read<int>("SIZE1:",sizeErr,entryCheck);
        unsigned int copy = SIZE;
        cout << "ENTER YOUR DATA HERE: " << endl;
        for(unsigned int i = 0; i<SIZE * (SIZE/2); i++){
            cout << i+1;
            db.push_back(read<int>(" . ", vecErr, ChessType));
        }
        //create a matrix
        ChessMatrix m1(db);
        db.clear(); //clear the matrix so that we could take the input again in the same vector

        do{
            SIZE=read<int>("SIZE2:",sizeErr,entryCheck);
            if(SIZE != copy)
                cout << "**ERROR, CANNOT MULTIPLY MATRICES OF DIFFERENT SIZES. Please Try again**\nSIZE:" << endl;
        }while(SIZE != copy);
        cout << "ENTER YOUR DATA HERE: " << endl;
        for(unsigned int i = 0; i<SIZE * (SIZE/2); i++){
            cout << i+1;
            db.push_back(read<int>(" . ", vecErr, ChessType));
        }
        ChessMatrix m2(db);
        try{
            m_output = m1 * m2;
        }catch(ChessMatrix::ERRORS e){
            if(e == ChessMatrix::ERRORS::NOT_EQUAL_SIZE){
                cout << "**ERROR, CANNOT MULTIPLY MATRICES OF DIFFERENT SIZES. Please Try again**\nPRESS ENTER TO RETURN:" << endl;
            }else{
                cout << "**UNKNOW ERROR!**\nPRESS ENTER TO RETURN:";
            }
            cin.get();
            goto top;
        }
        break;
    }


}


void Menu::getElem(){
top:CLEARSCREEN();
    cout << endl << endl;
    std::string filename;
    unsigned int col, row;
    int element;
    int option;
    cout << "*************************************************\n";
    std::string msg = "0. RETURN TO MAIN MENU\n1. GET ELEMENT OF GIVEN COLUMN AND ROW FROM A FILE\n2. ENTER MATRICES MANUALLY\n";
    cout << msg;
    cout << "*************************************************\n";
    std::string errmsg = "**It has to be a number between 0 and 2!**";
    option=read<int>("==>CHOICE:",errmsg,MenuCheck);

    switch(option){
        default:
            return;
        case 1:{
            CLEARSCREEN();
            std::string filename;
            cout << "ENTER THE PATH TO THE FILE: ";
            cin >> filename;
            try{
                ChessMatrix m(filename);
                m_output = m; //copy the matrix to the output here
            }catch(ChessMatrix::ERRORS e){
                if(e == ChessMatrix::ERRORS::CORRUPT_FILE){
                    cout << "**ERROR OPENING FILE**\n\nPRESS ENTER TO RETURN:";
                }else{
                    cout << "**UKNOWN ERROR**\n\nPRESS ENTER TO RETURN:";
                }
                cin.get();
                cin.get();
                goto top;
            }

            col=read<int>("COLUMN: ", "PLEASE ENTER AN INTEGER NUMBER.", getElemCheck);
            row=read<int>("ROW: ", "PLEASE ENTER AN INTEGER NUMBER.", getElemCheck);
            try{
                element = m_output.getElemAt(row, col);
            }catch(ChessMatrix::ERRORS e){
                if(e == ChessMatrix::ERRORS::INDEX_OUT_OF_BOUND){
                    cout << "**ERROR, INDEX OUT OF BOUND**\nPRESS ENTER TO RETURN";
                }else{
                    cout << "**UNKNOW ERROR**\nPRESS ENTER TO RETURN";
                }
                cin.get();
                goto top;
            }
            CLEARSCREEN();
            cout << "\nINFO: COUNTING START FROM 0\n\nELEMENT AT COLUMN " << col << " AND ROW " << row << " IS " << element;
            cout << "\nPRESS ANY KEY TO REUTRN";
            cin.get();
            break;
        }


        case 2:{
            CLEARSCREEN();
            unsigned int SIZE;
            std::vector<int> db;
            std::string sizeErr = "**ERROR, PLEASE ENTER THE SIZE (an integer number) OF CHESS-TYPE MATRIX.**";
            std::string vecErr = "**ERROR, PLEASE ENTER NON-ZERO ENTRIES.**";
            SIZE=read<int>("SIZE1:",sizeErr,entryCheck);
            cout << "ENTER YOUR DATA HERE: " << endl;
            for(unsigned int i = 0; i<SIZE * (SIZE/2); i++){
                cout << i+1;
                db.push_back(read<int>(" . ", vecErr, ChessType));
            }
            //create a matrix
            ChessMatrix m1(db);
            m_output = m1; //copying to output
            col = read<int>("COLUMN: ", "**PLEASE ENTER AN INTEGER NUMBER.**", getElemCheck);
            row = read<int>("ROW: ", "**PLEASE ENTER AN INTEGER NUMBER**", getElemCheck);
            try{
                element = m1.getElemAt(row, col);
            }catch(ChessMatrix::ERRORS e){
                if(e == ChessMatrix::ERRORS::INDEX_OUT_OF_BOUND){
                    cout << "**ERROR, INDEX OUT OF BOUND.\nPRESS ENTER TO RETURN:**";
                }else{
                    cout << "**UNKNOW ERROR!\nPRESS ENTER TO RETURN:**";
                }
                cin.get();
                goto top;
            }
            CLEARSCREEN();
            cout << "\nINFO: COUNTING START FROM 0\n\nELEMENT AT COLUMN " << col << " AND ROW " << row << " IS " << element;
            cout << "\nPRESS ENTER TO RETURN";
            cin.get();
            break;
        }

    }


}

void Menu::print(){
    CLEARSCREEN();
    cout << "THIS IS YOUR CURRENT MATRIX: \n\n"<<m_output;
}





