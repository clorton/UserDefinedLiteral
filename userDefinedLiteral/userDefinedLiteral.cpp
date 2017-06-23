// userDefinedLiteral.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>

class Probability {
public:
    Probability(float initial);
    Probability operator -() { throw "Negative probabilities not allowed."; }
    operator float() const { return value; }

protected:
    float value;

private:
    Probability() : value(0) { }
};

Probability::Probability(float initial) : value(initial)
{
    if ((value < 0) || (value > 1))
        throw "Probability out of range [0,1]";
}

Probability operator "" _p(long double literal)
{
    Probability ret((float)literal);
    return ret;
}

int main()
{
    auto certain = 1.0_p;
    auto never = 0.0_p;
    auto maybe = 0.5_p;
    try {
        auto uhoh = -0.25_p;
    }
    catch (const char* e)
    {
        std::cout << "Caught exception on 'auto uhoh = -0.25_p;' : " << e << std::endl;
    }
    try {
        auto whoops = 1.85_p;
    }
    catch (const char* e)
    {
        std::cout << "Caught exception on 'auto whoops = 1.85_p;' : " << e << std::endl;
    }

    std::cout << "certain: " << certain << std::endl;
    std::cout << "never:   " << never << std::endl;
    std::cout << "maybe:   " << maybe << std::endl;

    return 0;
}

