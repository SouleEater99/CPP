#include "PmergeMe.hpp"




int main(int argc, char **argv)
{
    try
    {
        PmergeMe pmerge;
        pmerge.sort(argc, argv);
        pmerge.printResults();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}