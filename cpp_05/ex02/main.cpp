#include "./ShrubberyCreationForm.hpp"
#include "./Bureaucrat.hpp"


int main()
{
    std::cout << "first test" << std::endl;
    {
        try
        {
            ShrubberyCreationForm   tree = ShrubberyCreationForm("Home");
            Bureaucrat              executor = Bureaucrat("ali", 2);
    
            tree.beSigned(executor);
            std::cout << tree << std::endl;
            tree.execute(executor);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
        
}