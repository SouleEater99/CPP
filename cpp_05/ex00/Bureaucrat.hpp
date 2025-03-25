#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Bureaucrat
{
private:
    const std::string   _Name;
    int                 _Grade;
    void    _CheckException() const ;
public:
    Bureaucrat(const std::string name, int grade);
    ~Bureaucrat();
    std::string getName() const;
    int        getGrade() const;
    void        increment();
    void        decrement();

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    
};

std::ostream&   operator << (std::ostream& out, const Bureaucrat& bure);





#endif