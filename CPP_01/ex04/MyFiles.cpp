#include "./MyFiles.hpp"

MyFiles::MyFiles(const std::string& filename, const std::string& s1, const std::string& s2) : _FileName(filename),
 _NewFile(filename + ".replace"), _S1(s1), _S2(s2), _ReadFile(filename), _FileReplace(_NewFile) {}

MyFiles::~MyFiles()
{
    closeFiles();
    std::cout << "Files is Closed | Object is Destroyed\n";
}

bool    MyFiles::checkFiles() const
{
    if (!_ReadFile.is_open())
    {
        std::cerr << "Fail to open ReadFile\n";
        return false;
    }
    if(!_FileReplace.is_open())
    {
        std::cerr << "Fail to open ReplcaeFile\n";
        return false;
    }
    return true;
}

void    MyFiles::closeFiles()
{
    _ReadFile.close();
    _FileReplace.close();
}

void    MyFiles::replaceAll()
{
    int pos;

    pos = 0;
    while (getline(_ReadFile, _Buffer))
    {
        while (!_S1.empty() && (pos = _Buffer.find(_S1)) != std::string::npos)
        {
            if (pos >= 0)
            {
                _Buffer.erase(pos, _S1.length());
                _Buffer.insert(pos, _S2);
            }
        }
        _FileReplace << _Buffer << std::endl;
    }
}

