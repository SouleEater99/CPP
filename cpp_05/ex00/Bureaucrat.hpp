#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Bureaucrat
{
private:
    const std::string   _Name;
    unsigned int                 _Grade;
    void    _CheckException() const ;
public:
    Bureaucrat(const std::string name, unsigned int grade);
    ~Bureaucrat();
    std::string getName() const;
    unsigned int        getGrade() const;
    void        increment();
    void        decrement();
};

std::ostream&   operator << (std::ostream& out, const Bureaucrat& bure);





#endif