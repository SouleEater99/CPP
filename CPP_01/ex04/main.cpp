#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
        std::cout << "[./ProgramName] [Arg_1: filename] [Arg_2: String_1] [Arg_3: String_2]\n";
    std::string     buffer;
    std::string     filename = av[1];
    std::ifstream   ReadFile(filename);
    std::ofstream   FileReplace(filename + ".replace");
    while (getline(ReadFile, buffer))
    {
        filename
    }




}