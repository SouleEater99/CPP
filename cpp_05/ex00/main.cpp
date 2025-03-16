#include "./Bureaucrat.hpp"

int main ()
{
    Bureaucrat bure("ali", 1);

    bure.~Bureaucrat();
    std::cout << bure;
}