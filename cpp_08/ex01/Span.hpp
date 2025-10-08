#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>


class Span
{
private:
    unsigned int        N;
    std::vector<int>    _vec;
public:
    Span(/* args */);
    Span(const Span &other);
    Span(const unsigned int &N);
    Span& operator=(const Span &other);
    ~Span();

    void    addNumber(int n);
    int     shortestSpan();
    int     longestSpan();
    void    addRangeNubmers();
    void    printContainer();
};



#endif