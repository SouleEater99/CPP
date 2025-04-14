#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << "Name: " <<  rrf->GetName() << std::endl;
    }

    return 0;
}