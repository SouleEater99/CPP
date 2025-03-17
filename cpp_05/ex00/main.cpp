#include "./Bureaucrat.hpp"

int main ()
{
    try
    {
        /* code */
    Bureaucrat bure("ali", 1);

    bure.increment();
        std::cout << bure;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}