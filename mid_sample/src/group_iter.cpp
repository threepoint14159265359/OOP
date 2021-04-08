#include "group_iter.h"


void group_iter::next(){
    if( ! (m_end = m_lineIter.end())){
        m_current.year = m_lineIter.Current().year_of_compition;
        m_current.areSolutionAtMostThree = true;
        for(; !(m_end = m_lineIter.end()) && (m_current.year == m_lineIter.Current().year_of_compition); m_lineIter.next()){
            m_current.areSolutionAtMostThree = m_current.areSolutionAtMostThree && m_lineIter.Current().at_most_three;
        }
    }
}
