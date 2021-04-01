#ifndef LINE_ITER_H
#define LINE_ITER_H

#include <fstream>
#include <string>
#include <sstream>



struct black_hole_info{
    std::string name;
    std::string station;
    std::string date;
    int distance_from_earth;
    int weight;
    bool closer_than_2700;
};

class line_iter{
public:
    enum errors{fileError};
    line_iter(const std::string&);

    void first(){next();}
    void next();
    black_hole_info Current(){return m_currentLine;}
    bool end(){return m_end;}
private:
    std::ifstream m_file;
    black_hole_info m_currentLine;
    bool m_end;
};

#endif // LINE_ITER_H
