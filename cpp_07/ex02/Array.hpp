#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <exception>
#include <cstring>

template <typename T>
class Array
{
private:
    T *_data;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    ~Array();
    Array<T>  & operator=(const Array<T> &other);
    T&         operator[](const unsigned int &n);

    class OutOfBoundsException: public std::exception
    {
        public:
            const char *what() const throw ();
    };

    unsigned int size() const ;
    
};

#include "./Array.tpp"

#endif