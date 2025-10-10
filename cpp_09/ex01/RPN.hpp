#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

class RPN
{
private:
        std::stack<int> _stack;
    
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    std::string normalize(const std::string &input);
    int evaluate(const std::string &expression);
};



#endif