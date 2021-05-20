#include <iostream>
#include "library/counting.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"
#include "library/maxsearch.hpp"



using namespace std;


/*Task: Give the contest and the angler id of the contestant who caught most fish in one contest.*/
struct Fish_data{
    string fish_type;
    int size;
    friend istream &operator>>(istream &is, Fish_data &f)
    {
        is >> f.fish_type >> f.size;
        return is;
    }
};

//Inheriting counting Algorithmic Pattern => will find the cnt of fish
class FishCount : public Counting<Fish_data> {};

struct Contest_data{
    string angler;
    string contest_id;
    int no_of_fish_caught;
    int counter;
    friend istream &operator>>(istream &is,Contest_data &icontest){   
        string line;
        getline(is,line,'\n');
        stringstream ss(line);
        ss >> icontest.angler >> icontest.contest_id;
        FishCount pr;
        StringStreamEnumerator<Fish_data> ssenor(ss);
        pr.addEnumerator(&ssenor);
        pr.run();
        icontest.no_of_fish_caught = pr.result();
        return is;
    }
};

//Inheriting Maximum Search Algorithm Pattern => will find the maximum fish count
class MaxFish : public MaxSearch<Contest_data,int>{
protected:
    int func(const Contest_data& e) const override { return e.no_of_fish_caught;}
};


//Infile Line Enumerator: Inheriting Enumerator => Will iterate over each line, increasing the counter for each fish
class InfileLineIter : public Enumerator<Contest_data>
{
private:
    SeqInFileEnumerator<Contest_data>* _f;
    Contest_data _contest;
    bool _end;
public:
    InfileLineIter(const string &fname) { _f = new SeqInFileEnumerator<Contest_data>(fname);}
    ~InfileLineIter(){ delete _f;}
    void first() override { _f->first(); next();}
    void next() override{
        if (_end = _f->end()) return;
        _contest.angler = _f->current().angler;
        _contest.contest_id = _f->current().contest_id;
        MaxFish pr2;
        pr2.addEnumerator(_f);
        pr2.run();
        _contest.no_of_fish_caught = pr2.opt();
        if(_contest.no_of_fish_caught == 0){
            _contest.counter++;
        }
    }
    bool end() const override {return _end;}
    Contest_data current() const override { return _contest;}
};




/*Task: Give the number of Contests where no fish were cuaght OR number of fish == 0*/
struct Championship_data{
    string name;
    int Cnt;
};


class NoFishSum : public Summation<Contest_data,bool>{
private:
    string _name;
public:
    NoFishSum(const string &name) : _name(name) {}
    protected:
    bool func(const Contest_data& e) const override {return e.no_of_fish_caught;}
    bool neutral() const override { return true;}
    bool add( const bool& a, const bool& b) const override { return a && b;}
    bool whileCond(const Contest_data& e) const override { return e.contest_id == _name; }
    void first() override { }
};



//Infile Group Enumerator: inherating Enumerator again
class InfileGroupIter : public Enumerator<Championship_data>{
private:
    SeqInFileEnumerator<Contest_data>* _f;
    Championship_data _champ;
    bool _end;
public:
    InfileGroupIter(const string fname) { _f = new SeqInFileEnumerator<Contest_data>(fname);}
    ~InfileGroupIter() { delete _f;}
    void first() override { _f->first(); next(); }
    void next() override{
        if (_end = _f->end()) return;
        _champ.name = _f->current().contest_id;
        NoFishSum pr2(_champ.name);
        pr2.addEnumerator(_f);
        pr2.run();
        _champ.Cnt = pr2.result();
    }
    bool end() const override { return _end;}
    Championship_data current() const override { return _champ;}
};


class Zero_Fish : public Counting<Championship_data>{
protected:
    bool cond(const Championship_data& current) const override { return current.Cnt == 0; }
};



int main(){
    try{

        MaxFish pr3;
        Zero_Fish pr4;
        InfileLineIter fenor("input.txt");
        InfileGroupIter fenor2("input.txt");

        pr4.addEnumerator(&fenor2);
        pr4.run();

        pr3.addEnumerator(&fenor);
        pr3.run();
        cout << "Max Fish " << pr3.optElem().contest_id <<" by "
        << pr3.optElem().angler << " which is "<<pr3.opt()<<"\n";

         cout << "Zero Fish : "<<pr4.result() <<endl;
    }catch (SeqInFileEnumerator<Contest_data>::Exceptions e){
        cout <<"File not found!\n";
    }
    return 0;
}
