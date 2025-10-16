#include "./iter.hpp"

template <typename T>
void ft_print_with_dollar(T &a)
{
    std::cout << "$$$ " << a << " $$$\n";
}

int main()
{
    const std::string array[3] = {"test1", "test2", "test3"};
    const int array2[3] = {11, 22, 33};
    const double array3[3] = {11.11, 22.22, 33.33};

    iter(array, 3, ft_print_with_dollar<const std::string>);
    std::cout << "=======================\n";
    iter(array2, 3, ft_print_with_dollar<const int>);
    std::cout << "=======================\n";
    iter(array3, 3, ft_print_with_dollar<const double>);
}