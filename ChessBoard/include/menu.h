#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "ChessMatrix.h"


/**
    @uthor: Hussain Izhar
    Taks: Assignment 1, Object Oriented Programming - Spring 2021
**/

class Menu
{
    public:
        Menu(){};
        void run();
    private:
        int printMenu() const;
        void add();
        void multiply();
        void getElem();
        void print();
        void loadTest();
        ChessMatrix m_output;
};

#endif // MENU_H_INCLUDED
