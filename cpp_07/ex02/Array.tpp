#include "./Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n)
{
    for (unsigned int i = 0; i < _size; ++i)
        _data[i] = T();
}

template <typename T>
Array<T>::Array(const Array<T> &other)
{
    this->_size = other._size;
    if (other._data && other._size > 0)
    {
        this->_data = new T[other._size];
        for (unsigned int  i = 0; i < other._size; i++)
            this->_data[i] = other._data[i];
    }
    else
        this->_data = NULL;
}

template <typename T>
Array<T>::~Array()
{
    if (_data)
        delete[] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this == &other)
        return *this;
    _size = other._size;
    if (_data)
        delete[] _data;
    if (other._data && _size > 0)
    {
        this->_data = new T[other._size];
        for (unsigned int i = 0; i < other._size; i++)
            this->_data[i] = other._data[i];
    }
    else
        this->_data = NULL;
    return *this;
}

template <typename T>
T &Array<T>::operator[](const unsigned int &n)
{
    if (n < _size)
        return _data[n];
    throw OutOfBoundsException();
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
    return "Array::OutOfBoundsException\n";
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}