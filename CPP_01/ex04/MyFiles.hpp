#ifndef MYFILES_HPP
#define MYFILES_HPP

#include <string>
#include <fstream>
#include <iostream>

class MyFiles
{
private:
    const std::string   _FileName;
    const std::string   _NewFile;
    const std::string   _S1;
    const std::string   _S2;
    std::string         _Buffer;
    std::ifstream       _ReadFile;
    std::ofstream       _FileReplace;
    
public:
    MyFiles(const std::string& filename, const std::string& s1, const std::string& s2);
    ~MyFiles();
    bool    checkFiles() const;
    void    closeFiles();
    void    replaceAll();
};

#endif