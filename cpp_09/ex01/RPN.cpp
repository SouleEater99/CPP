#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other): _stack(other._stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->_stack = other._stack;  // Safe - both objects fully constructed
    }
    return *this;
}

RPN::~RPN()
{
}

std::string RPN::normalize(const std::string &input)
{
    std::string result;
    for (size_t i = 0; i < input.size(); ++i)
    {
        char c = input[i];

        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            // Add space before operator if last char wasn't already a space
            if (!result.empty() && result[result.size() - 1] != ' ')
                result += ' ';
            
            result += c;

            // Add space after operator if next char isn't a space
            if (i + 1 < input.size() && input[i + 1] != ' ')
                result += ' ';
        }
        else
        {
            result += c;
        }
    }
    return result;
}

int RPN::evaluate(const std::string &expression)
{
    std::string normalized = normalize(expression);
    std::istringstream iss(normalized);
    std::string token;

    while (iss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: Insufficient values in the expression.");

            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            int result;

            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else // token == "/"
            {
                if (b == 0)
                    throw std::runtime_error("Error: Division by zero.");
                result = a / b;
            }
            _stack.push(result);
        }
        else
        {
            // Method 1: Enforce single digits only (matches subject requirement)
            if (token.size() != 1 || !std::isdigit(token[0]))
                throw std::runtime_error("Error");
            
            int value = token[0] - '0';  // Convert single digit to int
            _stack.push(value);
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error: The user input has too many values.");

    return _stack.top();
}