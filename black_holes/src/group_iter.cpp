#include "../include/group_iter.h"




void group_iter::next(){
    if(!(m_end = lineIter.end())){

        //when we call the first() of the group iterator, it should read the first line of the file and initialize the cnt to zero
        if(m_currentGroup.cnt_of_measurement < 0){
            lineIter.first();
            m_currentGroup.cnt_of_measurement = 0;
            m_currentGroup.added_weight = 0;
        }
        int weight = 0, cnt = 0;
        m_currentGroup.name = lineIter.Current().name;
        for(; !(m_end = lineIter.end()) && (m_currentGroup.name == lineIter.Current().name); lineIter.next()){
            if(lineIter.Current().closer_than_2700){
                weight += lineIter.Current().weight;
                cnt++;
            }
        }
        m_currentGroup.added_weight = weight;
        m_currentGroup.cnt_of_measurement = cnt;
    }
}

