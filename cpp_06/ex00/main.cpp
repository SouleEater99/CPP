#include "./ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        double d;

        d = strtof(av[1], NULL);
        std::cout << d << std::endl;
        ScalarConverter::convert(av[1]);
    }
}