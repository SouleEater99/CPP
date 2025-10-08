#include "./easyfind.hpp"

int main()
{
    {

        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);
        v.push_back(50);

        try
        {
            std::vector<int>::iterator it = easyfind(v, 30);
            std::cout << "Found : " << *it << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        try
        {
            std::vector<int>::iterator it = easyfind(v, 100);
            std::cout << "Found : " << *it << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    std::cout << "=================== { list container } =========================\n";

    {
        std::list<int> list;
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
        list.push_back(40);
        list.push_back(50);
        
        try
        {
            std::list<int>::iterator it = easyfind(list, 30);
            std::cout << "Found : " << *it << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        try
        {
            std::list<int>::iterator it = easyfind(list, 100);
            std::cout << "Found : " << *it << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        

    }

}