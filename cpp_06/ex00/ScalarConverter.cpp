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
        i++;
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

int     ScalarConverter::_PrintByChar(const std::string& str)
{
    unsigned char c = static_cast<unsigned char>(str[1]);
    if (isprint (c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non dispalyable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

int     ScalarConverter::_PrintByInt(const std::string& str)
{
    unsigned char c = static_cast<unsigned char>(str[1]);
    if (isprint (c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non dispalyable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

int     ScalarConverter::_PrintByFloat(const std::string& str)
{
     unsigned char c = static_cast<unsigned char>(str[1]);
    if (isprint (c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non dispalyable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

int     ScalarConverter::_PrintByDouble(const std::string& str)
{
    unsigned char c = static_cast<unsigned char>(str[1]);
    if (isprint (c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non dispalyable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

int     ScalarConverter::_PrintByNan(const std::string& str)
{
    unsigned char c = static_cast<unsigned char>(str[1]);
    if (isprint (c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non dispalyable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void    ScalarConverter::convert(const std::string& str)
{
    if (IsChar(str))
        _PrintLiteralType = &ScalarConverter::_PrintByChar;
    else if (IsInt(str))
        _PrintLiteralType = &ScalarConverter::_PrintByInt;
    else if (IsFloat(str))
        _PrintLiteralType = &ScalarConverter::_PrintByFloat;
    else if (IsDouble(str))
        _PrintLiteralType = &ScalarConverter::_PrintByDouble;
    else
        _PrintLiteralType = &ScalarConverter::_PrintByNan;
    (this->*_PrintLiteralType)(str);
}