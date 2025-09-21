#include "Utilis.hpp"

int main()
{
    Base * ptr = Utilis::generate();

    Utilis::identify(ptr);
    Utilis::identify(*ptr);

    delete ptr;
}