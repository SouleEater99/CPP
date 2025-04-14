#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    
    std::cout <<  "Valid form\n";
    {
        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Garden");
        if (shrub) 
        delete shrub;
    }
    
    std::cout <<  "Valid form\n";
    {
    AForm* robot = someRandomIntern.makeForm("robotomy request", "Bender");
    if (robot) 
        delete robot;
    }   
    
    std::cout <<  "Invalid form\n";
    {

        AForm* unknown = someRandomIntern.makeForm("tax return", "Office");
        if (unknown) 
        delete unknown;  // Should be NULL
    }
    
    return 0;
}