#include "./Form.hpp"
#include "./Bureaucrat.hpp"

Form::Form(): _Name("Defual form"), _IsSigned(false), _SignGrade(10), _ExecuteGrade(5)
{
    _CheckException();
}

Form::Form(const std::string& name, int sign, int excute): _Name(name), _IsSigned(false), _SignGrade(sign), _ExecuteGrade(excute)
{
    _CheckException();
}

Form::Form(const Form& other): _Name(other._Name), _IsSigned(other._IsSigned), _SignGrade(other._SignGrade), _ExecuteGrade(other._ExecuteGrade)
{
    _CheckException();
}

Form::~Form()
{
    std::cout << "Form: Destractor Called\n";
}

Form&   Form::operator = (const Form& other)
{
    if (this == &other)
        return *this;
    this->_IsSigned = other._IsSigned;
    return (*this);
}

const char  *Form::GradeTooHighException::what() const throw()
{
    return "Form::GradeTooHighException.";
}


const char  *Form::GradeTooLowException::what() const throw()
{
    return "Form::GradeTooLowException.";
}

void    Form::_CheckException() const
{
    if (_SignGrade > 150)
        throw Form::GradeTooLowException();
    else if (_SignGrade < 1)
        throw Form::GradeTooHighException();

    if (_ExecuteGrade > 150)
        throw Form::GradeTooLowException();
    else if (_ExecuteGrade < 1)
        throw Form::GradeTooHighException();
}

std::string Form::GetName() const
{
    return _Name;
}

bool        Form::GetIsSigned() const
{
    return _IsSigned;
}

int         Form::GetSignedGrade() const
{
    return _SignGrade;
}

int         Form::GetExecuteGrade() const
{
    return _ExecuteGrade;
}


void        Form::beSigned(const Bureaucrat& Bure)
{
    if (Bure.getGrade() <= _SignGrade)
        _IsSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream&    operator << (std::ostream& out ,const Form& form)
{
    out << "name : " << form.GetName();
    out << " | Is_Signed : " << form.GetIsSigned();
    out << " | Signed_Grade : " << form.GetSignedGrade();
    out << " | Execute_Grade : " << form.GetExecuteGrade();
    return out;
}