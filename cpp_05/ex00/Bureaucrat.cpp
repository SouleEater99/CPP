#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): _Name(name), _Grade(grade)
{
    _CheckException();
}

Bureaucrat::~Bureaucrat()
{
}

void        Bureaucrat::_CheckException() const
{
        if (_Grade > 150)
            throw "Bureaucrat::GradeTooLowException.\n";
        else if (_Grade == 0)
            throw "Bureaucrat::GradeTooHighException\n";


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

unsigned int        Bureaucrat::getGrade() const    {return (_Grade);}