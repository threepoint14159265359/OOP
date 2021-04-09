#ifndef LINE_ITER_H
#define LINE_ITER_H

#include <string>
#include <sstream>
#include <fstream>

struct race_info{
    std::string team, racer_name;
    bool stage_18_completion_in_lessMin;
    bool stage_18_completion;
};


class line_iter{
public:
    enum errors{fileError};
    line_iter(const std::string&);

    void first(){next();}
    void next();
    race_info Current(){return m_current_line;}
    bool end(){return m_end;}
private:
    std::ifstream m_file;
    race_info m_current_line;
    bool m_end;
};


#endif LINE_ITER_H //LINE_ITER
