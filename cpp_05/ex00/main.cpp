#include "./Bureaucrat.hpp"

int main()
{
    std::cout << "++++++++++ : test valid grade: +++++++++++++\n" << std::endl;
    {
        try
        {
            Bureaucrat bure("ali", 11);

            bure.decrement();
            std::cout << "< == decrement == >" << std::endl << bure << std::endl;

            bure.increment();
            std::cout << "< == increment == >" << std::endl << bure << std::endl;
            
            std::cout << "< == Trying to Throw exception by INC Grade == >" << std::endl;
            for (int i = 0; i < 150; i++)
                bure.increment();

            std::cout << "IF THIS PRINT, THEN IT;S NOT WORK" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what();
        }
    }

    std::cout << std::endl << "++++++++++ : test high grade: +++++++++++++\n" << std::endl;
    {
        try
        {
            Bureaucrat bure("ali", -1);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what();
        }
    }

    std::cout << std::endl <<"++++++++++ : test low grade: +++++++++++++\n" << std::endl;
    {
        try
        {
            Bureaucrat bure("ali", 151);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what();
        }
    }
}