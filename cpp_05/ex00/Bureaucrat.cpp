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
    try
    {
        if (_Grade > 150)
            throw "Bureaucrat::GradeTooLowException.\n";
        else if (_Grade == 0)
            throw " Bureaucrat::GradeTooHighException\n";
    }
    catch(const char *error_msg)
    {
        std::cerr << error_msg;
        std::exit(1);
    }
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
    out << bure.getName() << ", bureaucrat grade " << bure.getGrade() << ".\n";
    return out;
}

std::string Bureaucrat::getName() const     {return (_Name);}

unsigned int        Bureaucrat::getGrade() const    {return (_Grade);}