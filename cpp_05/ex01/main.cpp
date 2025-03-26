#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int main()
{
    Form        f1 = Form("marrying form", 3, 7);
    Bureaucrat  b1 = Bureaucrat("ali", 2);

    b1.signForm(f1);
    std::cout << f1 << std::endl;

}