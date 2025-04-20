#include "./ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ScalarConverter scalar;

        scalar.convert(av[1]);
    }
}