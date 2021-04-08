#ifndef GROUP_ITER_H
#define GROUP_ITER_H

#include "line_iter.h"


struct comp_data{
    int year;
    bool areSolutionAtMostThree;
};


class group_iter{
public:
    group_iter(const std::string& filename): m_lineIter(filename){}

    void first(){m_lineIter.first(); next();}
    void next();
    comp_data Current(){return m_current;}
    bool end(){return m_end;}
private:
    line_iter m_lineIter;
    comp_data m_current;
    bool m_end;
};


#endif // GROUP_ITER_H
