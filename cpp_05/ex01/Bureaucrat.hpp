#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class   Form;

class Bureaucrat
{
private:
    const std::string   _Name;
    int                 _Grade;
    public:
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    Bureaucrat& operator = (const Bureaucrat& other);
    std::string getName() const;
    int        getGrade() const;
    void        increment();
    void        decrement();
    void    _CheckException() const ;

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

    void    signForm(Form& form);
};

std::ostream&   operator << (std::ostream& out, const Bureaucrat& bure);





#endif