#include "line_iter.h"

line_iter::line_iter(const std::string& filename){
    m_file.open(filename);
    if(m_file.fail()){
        throw errors{};
    }
}


void line_iter::next(){
    std::string line;
    std::getline(m_file, line, '\n');
    if( ! (m_end = m_file.fail())){
        std::istringstream ss(line);
        ss >> m_currentLine.year_of_compition >> m_currentLine.name;
        m_currentLine.ten_correct_solution = false;

        //if there is no language named fortran, it should store true
        m_currentLine.at_most_three = true;
        std::string language;
        int size;
        for( ss >> language >> size; !ss.fail(); ss >> language >> size){
            if (language == "Fortran" && size > 10){
                m_currentLine.ten_correct_solution = true;
            }

            //if there is a langauge named fortran and the solutions provided are less than 3, it should store true
            if(language == "Fortran" && size > 3){
                m_currentLine.at_most_three = false;
            }


        }
    }
}
