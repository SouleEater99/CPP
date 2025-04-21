#include "./ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ScalarConverter scalar;

    double  d;

    d = strtof(av[1], NULL);
        std::cout << d << std::endl;
        scalar.convert(av[1]);
    }
}