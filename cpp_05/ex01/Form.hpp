#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
    const std::string   _Name;
    bool                _IsSigned;
    const int           _SignGrade;
    const int           _ExecuteGrade;
public:
    Form();
    Form(const std::string& name, int sign, int excute);
    Form(const Form& other);
    ~Form();
    Form&   operator = (const Form& other);

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

    std::string GetName() const;
    bool        GetIsSigned() const;
    int         GetSignedGrade() const;
    int         GetExecuteGrade() const;

    void        beSigned(const Bureaucrat& Bure);

    void        _CheckException() const;
};

std::ostream&    operator << (std::ostream& out ,const Form& form);

#endif