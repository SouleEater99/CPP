#include "./easyfind.hpp"


template <typename T>
typename T::iterator easyfind(T &v, int n)
{
    typename T::iterator it = std::find(v.begin(), v.end(), n);

    if (it == v.end())
        throw std::runtime_error("Exception::EasyFind Value Not Found");
    return it;
}