#ifndef PRQUEUE_H
#define PRQUEUE_H

#include <string>
#include <istream>
#include <read.hpp>

inline bool valid(int a){return true;}
struct Item{
    int priority;
    std::string data;

    //constructor
    Item(int pr, const std::string &d): priority(pr), data(d){}

    //input stream overload
    friend std::istream operator>>(const std::istream &stream, const Item &item){
        item.priority = read<int>("Enter Priority: ", "[ERROR!] Priority should be a int...", item.priority, valid);
        std::cout << "Data: ";
        stream>>item.data;
        return stream;
    }

};

class prQueue
{
    public:

    private:
};

#endif // PRQUEUE_H
