#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

class ScalarConverter
{
private:
    int     (ScalarConverter::*_PrintLiteralType)(const std::string& str);
    int     _PrintByChar(const std::string& str);
    int     _PrintByInt(const std::string& str);
    int     _PrintByFloat(const std::string& str);
    int     _PrintByDouble(const std::string& str);
    int     _PrintByNan(const std::string& str);
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ~ScalarConverter();
    ScalarConverter&    operator = (const ScalarConverter& other);
    void    convert(const std::string& str);
    bool    IsChar(const std::string& other);
    bool    IsInt(const std::string& other);
    bool    IsFloat(const std::string& other);
    bool    IsDouble(const std::string& other);

};




    

    
#endif