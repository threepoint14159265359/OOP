#pragma once

#include "procedure.hpp"
#include <iostream>

template < typename Item, typename Value = Item >
class Summation : public Procedure<Item>
{
private:
    Value _result;
protected:
    void init() final override  { _result = neutral(); }
    void body(const Item& e) final override  {
        if(cond(e)) _result = add(_result, func(e));
    }
    virtual Value func(const Item& e) const = 0;
    virtual Value neutral() const = 0;
    virtual Value add( const Value& a, const Value& b) const = 0;
    virtual bool cond(const Item& e) const { return true; }
public:
    Summation(){}
    Summation(const Value &v) : _result(v) {}
    const Value& result() const { return _result; }
};

//template specialization if the second parameter is ostream
//it is used to solve collated problems
template < typename Item >
class Summation<Item, std::ostream> : public Procedure<Item, std::ostream>
{
private:
    std::ostream *_result;
protected:
    void init() override final { }
    void body(const Item& e) override final {
        if(cond(e)) *_result << func(e);
    }
    virtual std::string func(const Item& e) const = 0;
    virtual bool cond(const Item& e) const { return true; }
public:
    Summation(std::ostream *o) : _result(o) {}
};

//template specialization if the second parameter is vector
//it is used to solve problems with multiple answers.
template < typename Item, typename Value = Item >
class Summation<Item, std::vector<Value> > : public Procedure<Item, std::vector<Value> >
{
private:
    std::vector<Value> _result;
protected:
    void init() override final { }
    void body(const Item& e) override final {
        if(cond(e)) _result.push_back(func(e));
    }
    virtual Value func(const Item& e) const = 0;
    virtual bool cond(const Item& e) const { return true; }
public:
    Summation() {}
    Summation(const std::vector<Value> &v) : _result(v) {}
    const std::vector<Value>& result() const { return _result; }
};
