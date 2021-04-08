#ifndef LINE_ITER_H
#define LINE_ITER_H


#include <string>
#include <sstream>
#include <fstream>

struct comp_info{
    int year_of_compition;
    std::string name;
    bool ten_correct_solution;
    bool at_most_three;
};


class line_iter{
public:
    enum errors{fileError};
    line_iter(const std::string&);

    void first(){next();}
    void next();
    comp_info Current(){return m_currentLine;}
    bool end(){return m_end;}
private:
    std::ifstream m_file;
    comp_info m_currentLine;
    bool m_end;
};

#endif // LINE_ITER_H
