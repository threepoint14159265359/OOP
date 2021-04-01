#ifndef GROUP_ITER_H
#define GROUP_ITER_H
#include "line_iter.h"

struct black_hole_data{
    std::string name;
    int added_weight = 0 ;
    int cnt_of_measurement = -1;
};


class group_iter{
public:

    group_iter(const std::string& filename): lineIter(filename){};
    void first(){next();}
    void next();
    black_hole_data Current(){return m_currentGroup;}
    bool end(){return m_end;}
private:
    line_iter lineIter;
    black_hole_data m_currentGroup;
    bool m_end;

    void read();
};

#endif // GROUP_ITER_H
