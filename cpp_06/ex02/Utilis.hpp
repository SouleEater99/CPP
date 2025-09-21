#ifndef UTILIS_HPP
#define UTILIS_HPP

#include    "A.hpp"
#include    "B.hpp"
#include    "C.hpp"
#include <stdlib.h>

class Utilis
{
private:
    /* data */
public:
    Utilis(/* args */);
    ~Utilis();

    static Base * generate(void);
    static void identify(Base* p);
    static void identify(Base& p);
};





#endif