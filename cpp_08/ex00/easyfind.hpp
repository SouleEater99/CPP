#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>
#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
typename T::Iterator easyfind(T &v, int n);

#include "./easyfind.tpp"

#endif