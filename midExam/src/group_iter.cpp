#include "group_iter.h"

void group_iter::next(){
    if (! (m_end = m_lineIter.end())){
        m_current.number_of_team_members = 0;
        m_current.cnt_racers_completing_stage_eighteen = 0;
        m_current.team = m_lineIter.Current().team;
        for(; !(m_lineIter.end()) && (m_current.team == m_lineIter.Current().team); m_lineIter.next()){
            m_current.number_of_team_members++;
            if(m_lineIter.Current().stage_18_completion){
                m_current.cnt_racers_completing_stage_eighteen++;
            }
        }
    }

}
