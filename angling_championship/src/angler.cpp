#include "angler.h"
#include <iostream>

void angler::next(){
    if(! (m_end = m_contest.end())){
        m_current.no_fish_count = 0;
        m_current.id = m_contest.current().contest_id;
        while(!(m_contest.end()) && m_current.id == m_contest.current().contest_id){
            m_current.no_fish_count += m_contest.current().counter;
            m_contest.next();
        }
    }
}
