#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
    const std::string _Name;
    bool _IsSigned;
    const int _SignGrade;
    const int _ExecuteGrade;

public:
    AForm();
    AForm(const std::string &name, int sign, int excute);
    AForm(const AForm &other);
    virtual ~AForm();
    AForm &operator=(const AForm &other);

    std::string GetName() const;
    bool GetIsSigned() const;
    int GetSignedGrade() const;
    int GetExecuteGrade() const;

    void beSigned(const Bureaucrat &Bure);

    void _CheckException() const;
    virtual void execute(Bureaucrat const &executor) const = 0;
    void check_execute(Bureaucrat const &executor) const;

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
    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif