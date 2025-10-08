#include "./Span.hpp"

int main()
{
    std::cout << "================== test 1 ====================\n";
    {

        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.printContainer();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    std::cout << "================== test 2 ====================\n";
    {
        Span sp(10000);

        sp.addRangeNubmers();
        // sp.printContainer();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        // sp.printContainer();
    }
    std::cout << "================== test 3 ====================\n";
    {
        Span sp = Span(3);
        try
        {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(5);
            sp.addNumber(3);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "================== test 4 ====================\n";
    {
        Span sp = Span(4);
        try
        {
            sp.addNumber(6);
            sp.printContainer();
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }


    return 0;
}