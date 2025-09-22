#include "./iter.hpp"

template <typename T>
void ft_print_with_dollar(T a)
{
    std::cout << "$$$ " << a << " $$$\n";
}

int main()
{
    std::string array[3] = {"test1", "test2", "test3"};
    int array2[3] = {11, 22, 33};
    double array3[3] = {11.11, 22.22, 33.33};

    iter(array, 3, ft_print_with_dollar<std::string>);
    std::cout << "=======================\n";
    iter(array2, 3, ft_print_with_dollar<int>);
    std::cout << "=======================\n";
    iter(array3, 3, ft_print_with_dollar<double>);
}