#ifndef GROUP_ITER_H
#define GROUP_ITER_H


#include "line_iter.h"

struct race_data{
    std::string team;
    int cnt_racers_completing_stage_eighteen;
    int number_of_team_members;
    bool exists;
};


class group_iter{
public:
    group_iter(const std::string& filename): m_lineIter(filename){}

    void first(){m_lineIter.first(); next();}
    void next();
    race_data Current(){return m_current;}
    bool end(){return m_end;}
private:
    line_iter m_lineIter;
    race_data m_current;
    bool m_end;
};

#endif // GROUP_ITER_H
