#include "Utilis.hpp"


Utilis::Utilis(/* args */)
{
}

Utilis::~Utilis()
{
}

Base * Utilis::generate(void)
{
    Base * ptr;

    std::srand(time(NULL));
    int randomValue = std::rand() % 3;

    switch (randomValue)
    {
    case 0:
        ptr = new A();
        break;
    case 1:
        ptr = new B();
        break;
    default:
        ptr = new C();
        break;
    }
    return ptr;
}


void Utilis::identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "the actual type of the object pointed to by p: 'A'\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "the actual type of the object pointed to by p: 'B'\n";
    else if (dynamic_cast<C *>(p))
        std::cout << "the actual type of the object pointed to by p: 'C'\n";
    else
        std::cout << "the actual type of the object pointed to by p: 'NOTHING'\n";
}

void Utilis::identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void) a;
        std::cout << "the actual type of the object pointed to by p: 'A'\n";
        return ;
    }
    catch(...) {}

    try
    {
        B& b = dynamic_cast<B&>(p);
        (void) b;
        std::cout << "the actual type of the object pointed to by p: 'B'\n";
        return ;
    }
    catch(...) {}
    
    try
    {
        C& c = dynamic_cast<C &>(p);
        (void) c;
        std::cout << "the actual type of the object pointed to by p: 'C'\n";
        return ;
    }
    catch(...) {}

    std::cout << "Unkonw type \n";
}