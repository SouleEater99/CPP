#include "MyFiles.hpp"

#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "[./ProgramName] [Arg_1: filename] [Arg_2: String_1] [Arg_3: String_2]\n";
        return 1;
    }
    MyFiles         myfiles(av[1], av[2], av[3]);
    if (!myfiles.checkFiles())
        return 1;
    myfiles.replaceAll();
    myfiles.closeFiles();

}