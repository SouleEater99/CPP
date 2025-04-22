#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <climits>
// #include <cctype>

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);

    static Type detectType(const std::string& literal);
    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);

    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);
};
    

    
#endif