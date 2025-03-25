#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): _Name(name), _Grade(grade)
{
    _CheckException();
}

Bureaucrat::~Bureaucrat()
{
}

void        Bureaucrat::_CheckException() const
{
        if (_Grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else if (_Grade < 1)
            throw Bureaucrat::GradeTooHighException();
}

void        Bureaucrat::increment()
{
    _Grade--;
    _CheckException();
}

void        Bureaucrat::decrement()
{
    _Grade++;
    _CheckException();
}

std::ostream&   operator << (std::ostream& out, const Bureaucrat& bure)
{
    out << bure.getName() << ", bureaucrat grade " << bure.getGrade() << ".";
    return out;
}

std::string Bureaucrat::getName() const     {return (_Name);}

int         Bureaucrat::getGrade() const    {return (_Grade);}


const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat::GradeTooHighException.\n";
}


const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat::GradeTooLowException.\n";
}