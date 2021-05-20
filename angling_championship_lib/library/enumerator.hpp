
#pragma once

template <typename Item>
class Enumerator
{
    public:
        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool end() const = 0;
        virtual Item current() const = 0;
        virtual ~Enumerator(){}
};
