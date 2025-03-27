#include "./Bureaucrat.hpp"
#include "./AForm.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): _Name(name), _Grade(grade)
{
    _CheckException();
}


Bureaucrat::Bureaucrat(const Bureaucrat& other): _Name(other._Name), _Grade(other._Grade)
{
    _CheckException();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destractor Called\n";
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other)
{
    if (this == &other)
        return *this;
    this->_Grade = other._Grade;
    return *this;
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


void    Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _Name << " signed " << form.GetName() << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cout << _Name << " couldn't sign " << form.GetName()<< " because " << e.what() << std::endl;
    }   
}

void    Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->_Name << " executed " << form.GetName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Bureauract: ExecuteForm Fail Because of " << e.what() << '\n';
    }
}