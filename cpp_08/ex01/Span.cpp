#include "./Span.hpp"

Span::Span(): N(10)
{
}
Span::Span(const Span &other): N(other.N), _vec(other._vec)
{
}

Span::Span(const unsigned int &n): N(n)
{
}

Span::~Span()
{
}

Span& Span::operator=(const Span &other)
{
    if (this == &other)
        return *this;
    this->N = other.N;
    this->_vec = other._vec;
    return *this;
}

void    Span::addNumber(int n)
{
    if (_vec.size() < N)
        _vec.push_back(n);
    else
        throw std::runtime_error("Exception::SpanCapacityIsFull");
}

int     Span::shortestSpan()
{
    if (_vec.size() < 2)
        throw std::runtime_error("Exception::SpanLessThanTwoElement");
    std::sort(_vec.begin(),_vec.end());

    std::vector<int> differ(_vec.size());

    std::adjacent_difference(_vec.begin(), _vec.end(), differ.begin());
     return *(std::min_element(differ.begin() + 1, differ.end()));
}

int     Span::longestSpan()
{
    if (_vec.size() < 2)
        throw std::runtime_error("Exception::SpanLessThanTwoElement");
    std::sort(_vec.begin(),_vec.end());

    int min = *std::min_element(_vec.begin(), _vec.end());
    int max = *std::max_element(_vec.begin(), _vec.end());
    return (max - min);
}

void    Span::addRangeNubmers()
{

    std::srand(std::time(0));

    for (int i = 0; _vec.size() < N; i++)
    {
        int randomNumber = std::rand(); // random number between 0 and 999
        _vec.push_back(randomNumber);
    }
    std::random_shuffle(_vec.begin(), _vec.end());
}

void    Span::printContainer()
{
    std::vector<int>::iterator it;
    
    std::cout << "[ ";
    for (it = _vec.begin(); it != _vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << "]\n";
}