#include "./ScalarConverter.hpp"

ScalarConverter&    ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this == &other)
        return *this;
    return *this;
}

void ScalarConverter::convert(const std::string& literal) {
    Type type = detectType(literal);
    double value = 0.0;

    switch (type) {
        case CHAR:
            value = static_cast<double>(literal[1]);
            break;
        case INT:
        case FLOAT:
        case DOUBLE:
            if (type == FLOAT) {
                std::string substr = literal.substr(0, literal.size() - 1);
                value = std::strtod(substr.c_str(), NULL);
            } else {
                value = std::strtod(literal.c_str(), NULL);
            }
            break;
        case INVALID:
            std::cout << "Invalid input" << std::endl;
            return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

ScalarConverter::Type ScalarConverter::detectType(const std::string& literal) {
    if (isChar(literal))
        return CHAR;
    else if (isFloat(literal))
        return FLOAT;
    else if (isInt(literal))
        return INT;
    else if (isDouble(literal))
        return DOUBLE;
    else
        return INVALID;
}

bool ScalarConverter::isChar(const std::string& literal) {
    if (literal.size() != 3 || literal[0] != '\'' || literal[2] != '\'')
        return false;
    return std::isprint(literal[1]);
}

bool ScalarConverter::isInt(const std::string& literal) {
    char* end;
    long intVal = std::strtol(literal.c_str(), &end, 10);
    if (*end != '\0')
        return false;
    if (intVal < INT_MIN || intVal > INT_MAX)
        return false;
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    size_t len = literal.size();
    if (len < 2 || (literal[len - 1] != 'f' && literal[len - 1] != 'F'))
        return false;
    std::string substr = literal.substr(0, len - 1);
    if (substr == "nan" || substr == "+inf" || substr == "-inf")
        return true;
    char* end;
    std::strtod(substr.c_str(), &end);
    return (end == substr.c_str() + substr.size());
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;
    char* end;
    std::strtod(literal.c_str(), &end);
    return (*end == '\0');
}

void ScalarConverter::printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 255) {
        std::cout << "impossible" << std::endl;
        return;
    }
    unsigned char c = static_cast<unsigned char>(value);
    if (std::isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) {
    std::cout << "float: ";
    if (std::isnan(value)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << (value < 0 ? "-inff" : "inff") << std::endl;
    } else {
        float f = static_cast<float>(value);
        std::cout << f;
        if (f == std::floor(f) && !std::isinf(f))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value) {
    std::cout << "double: ";
    if (std::isnan(value)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << (value < 0 ? "-inf" : "inf") << std::endl;
    } else {
        std::cout << value;
        if (value == std::floor(value) && !std::isinf(value))
            std::cout << ".0";
        std::cout << std::endl;
    }
}
