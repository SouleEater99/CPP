#include "./MyFiles.hpp"

MyFiles::MyFiles(const std::string& filename, const std::string& s1, const std::string& s2) : _FileName(filename),
 _NewFile(filename + ".replace"), _S1(s1), _S2(s2), _ReadFile(filename.c_str()), _FileReplace(_NewFile.c_str()) {}

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

void MyFiles::replaceAll()
{
    size_t pos;

    while (getline(_ReadFile, _Buffer))
    {
        pos = 0;
        while (!_S1.empty() && (pos = _Buffer.find(_S1, pos)) != std::string::npos)
        {
            // std::cout << "pos : " << pos << std::endl;
            _Buffer.erase(pos, _S1.length());
            // std::cout << "Buffer.earse() : " << _Buffer << std::endl;
            _Buffer.insert(pos, _S2);
            // std::cout << "Buffer.insert() : " << _Buffer << std::endl;
            pos += _S2.length();
        }
        _FileReplace << _Buffer << std::endl;
    }
}
