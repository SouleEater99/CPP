#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename Func>
void    iter(T *a, int b, Func f)
{
    for (int i = 0; i < b; i++)
        f(a[i]);
}


#endif