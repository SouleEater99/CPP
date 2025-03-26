#include "./Bureaucrat.hpp"

int main()
{
    Form        f1("marrying form", 3, 7);
    Bureaucrat  b1("ali", 2);

    b1.signForm(f1);
    std::cout << f1 << std::endl;

}