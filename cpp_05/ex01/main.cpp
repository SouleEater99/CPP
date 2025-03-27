#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int main()
{
    std::cout << "+++++++++ { test valid form and bureaucrat } ++++++++++\n";
    {
        try
        {
            Form f1 = Form("marrying form", 3, 7);
            Bureaucrat b1 = Bureaucrat("ali", 2);

            b1.signForm(f1);
            std::cout << f1 << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    std::cout << "\n+++++++++ { test signFrom exception } ++++++++++\n";
    {
        try
        {
            Form f1 = Form("marrying form", 3, 7);
            Bureaucrat b1 = Bureaucrat("ali", 10);

            b1.signForm(f1);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    std::cout << "\n+++++++++ { test Invalid form in constructor  } ++++++++++\n";
    {
        try
        {
            Form f1 = Form("marrying form", 0, 7);
            std::cout << "======== print this if form is valid\n";
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    std::cout << "\n+++++++++ { test Invalid Bureaucrat in constructor  } ++++++++++\n";
    {
        try
        {
            Bureaucrat b1 = Bureaucrat("ali", 222);
            std::cout << "======== print this if Bureaucrat is valid\n";
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}