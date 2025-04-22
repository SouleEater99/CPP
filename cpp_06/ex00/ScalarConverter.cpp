#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter: Constructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    if (this != &other)
        _PrintLiteralType = other._PrintLiteralType;
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
    for (int i = 0; i < static_cast<int>(str.length()); i++)
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

    if (str == "nanf" || str == "+inff" || str == "inff" || str == "-inff")
        return true;
    if (str[i] == '.')
        return false;
    if (i == 0 && (str[i] == '-' || str[i] == '+'))
        i++;
    while (i < static_cast<int>(str.length() - 1))
    {
        if (str[i] == '.' && str[i + 1] && str[i + 1] != 'f')
            n_dot++;
        else if (!isdigit(str[i]))
            return false;
        i++;
    }
    if (n_dot != 1 || str[i] != 'f')
    {
        return false;
    }
    return true;
}

bool    ScalarConverter::IsDouble(const std::string& str)
{
    int i;
    int n_dot;
    
    i = 0; 
    n_dot = 0;

    if (str == "nan" || str == "+inf" || str == "inf"|| str == "-inf")
        return true;
    if (str[i] == '.')
        return false;
    if (i == 0 && (str[i] == '-' || str[i] == '+'))
        i++;
    while (i < static_cast<int>(str.length() - 1))
    {
        if (str[i] == '.' && str[i + 1])
            n_dot++;
        else if (!isdigit(str[i]))
            return false;
        i++;
    }
    if (n_dot != 1)
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
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    return 0;
}

int     ScalarConverter::_PrintByInt(const std::string& str)
{
    long long i;

    i = atoll(str.c_str());

    if (isprint (i))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else if (i < 256)
        std::cout << "char: Non dispalyable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    
    if (i > __INT32_MAX__ || i < -__INT32_MAX__ - 1)
        std::cout << "int: impossible";
    else
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
    
    return 0;
}

int     ScalarConverter::_PrintByFloat(const std::string& str)
{
    float   f;

    f = strtof(str.c_str(), NULL);

    if (isprint (static_cast<unsigned char >(f)))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non dispalyable" << std::endl;
    std::cout << "int: " << static_cast<int>(f)  << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
    return 0;
}

int     ScalarConverter::_PrintByDouble(const std::string& str)
{
    double  d;

    d = strtof(str.c_str(), NULL);

    if (isprint (static_cast<unsigned char >(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non dispalyable" << std::endl;
    if (str == "nan" || str == "+inf" || str == "inf"|| str == "-inf")
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d)  << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
    return 0;
}

int     ScalarConverter::_PrintByNan(const std::string& str)
{
    (void) str;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return 0;
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