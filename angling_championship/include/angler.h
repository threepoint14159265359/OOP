#ifndef ANGLER_H
#define ANGLER_H

#include "contest.h"


struct angler_data{
    std::string id;
    int no_fish_count;
};

class angler{
public:
    angler(const std::string &str): m_contest(str){}
    void first(){m_contest.first();}
    void next();
    bool end()const{return m_end;}
    angler_data current()const{return m_current;}

private:
    contest m_contest;
    angler_data m_current;
    bool m_end;

};

#endif // ANGLER_H
