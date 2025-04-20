#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
private:
    bool    _CheckScalarType(const std::string& str);
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ~ScalarConverter();
    ScalarConverter&    operator = (const ScalarConverter& other);
    void    convert(const std::string& str);

    
};

#endif