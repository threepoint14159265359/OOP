#include "line_iter.h"

line_iter::line_iter(const std::string &filename){
    m_file.open(filename);
    if(m_file.fail()){
        throw errors::fileError;
    }
}



void line_iter::next(){
    std::string line;
    if ( !(m_end = m_file.fail())){
        std::getline(m_file, line, '\n');
        std::istringstream ss(line);
        ss >> m_current_line.team >> m_current_line.racer_name;
        m_current_line.stage_18_completion_in_lessMin = false;
        m_current_line.stage_18_completion = false;
        std::string stage_name;
        double time_to_reach_stage;
        for(ss >> stage_name >> time_to_reach_stage; ! ss.fail(); ss >> stage_name >> time_to_reach_stage){

            //condition to solve grade 3 problem
            if( stage_name == "STAGE_18" && time_to_reach_stage <= 400.0){
                m_current_line.stage_18_completion_in_lessMin = true;
            }
            //condition to solve grade 5 problem
            if(stage_name == "STAGE_18"){
                m_current_line.stage_18_completion = true;
            }

        }
    }

}
