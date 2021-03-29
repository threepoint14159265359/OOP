#ifndef CONTEST_H
#define CONTEST_H

#include <string>
#include <fstream>
#include <sstream>


struct contest_data{
    std::string angler_name;
    std::string contest_id;
    int counter;
};




class contest{
    public:
        enum errors{corrupt_file};
        contest(){}
        contest(const std::string &filename);

        void first(){next();}
        void next();
        contest_data current()const{return m_current;}
        bool end() const {return m_end;}

    private:
        std::ifstream _file;
        contest_data m_current;
        bool m_end;



};

#endif // CONTEST_H
