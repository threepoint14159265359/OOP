#include "../include/line_iter.h"


line_iter::line_iter(const std::string& filename){
    m_file.open(filename);
    if(m_file.fail()){
        throw errors{};
    }
}


void line_iter::next(){
    std::string line;
    std::getline(m_file, line, '\n');
    m_currentLine.closer_than_2700 = false;
    if(!(m_end = m_file.fail()) ){
        std::istringstream ss(line);
        ss >> m_currentLine.name >> m_currentLine.station;
        for(ss>>m_currentLine.date >> m_currentLine.weight >> m_currentLine.distance_from_earth; !(ss.fail()); ss>>m_currentLine.date >> m_currentLine.weight >> m_currentLine.distance_from_earth){
            if ( m_currentLine.closer_than_2700 || m_currentLine.distance_from_earth < 2700){
                m_currentLine.closer_than_2700 = true;
            }
        }
    }
}

