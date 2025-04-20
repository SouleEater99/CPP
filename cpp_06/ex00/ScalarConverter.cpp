#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter: Constructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    std::cout << "ScalarConverter: Copy Constructor Called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter: Destructor Called" << std::endl;
}

ScalarConverter&    ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this == &other)
        return *this;
    return *this;
}

void    ScalarConverter::convert(const std::string& str)
{

}

bool    ScalarConverter::IsChar(const std::string& str)
{
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
        if (isalpha(str[1]))
            return (true);
    return (false);
}

bool    ScalarConverter::IsInt(const std::string& str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (i == 0 && (str[i] == '-' || str[i] == '+'))
            continue;
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool    ScalarConverter::IsFloat(const std::string& str)
{
    int i;
    int n_dot;
    
    i = 0; 
    n_dot = 0;

    if (str[i] == '.')
        return false;
    if (i == 0 && (str[i] == '-' || str[i] == '+'))
        i++;
    while (i < str.length() - 1)
    {
        if (str[i] == '.' && str[i + 1] && str[i + 1] != 'f')
            n_dot++;
        else if (!isdigit(str[i++]))
            return false;
    }
    if (n_dot > 1 || !str[i] == 'f')
        return false;
    return true;
}

bool    ScalarConverter::IsDouble(const std::string& str)
{
    int i;
    int n_dot;
    
    i = 0; 
    n_dot = 0;

    if (str[i] == '.')
        return false;
    if (i == 0 && (str[i] == '-' || str[i] == '+'))
        i++;)
    while (i < str.length() - 1)
    {
        if (str[i] == '.' && str[i + 1])
            n_dot++;
        else if (!isdigit(str[i++]))
            return false;
    }
    if (n_dot > 1)
        return false;
    return true;
}