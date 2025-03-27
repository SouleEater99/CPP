#include "./AForm.hpp"
#include "./Bureaucrat.hpp"

AForm::AForm(): _Name("Defual form"), _IsSigned(false), _SignGrade(10), _ExecuteGrade(5)
{
    _CheckException();
}

AForm::AForm(const std::string& name, int sign, int excute): _Name(name), _IsSigned(false), _SignGrade(sign), _ExecuteGrade(excute)
{
    _CheckException();
}

AForm::AForm(const AForm& other): _Name(other._Name), _IsSigned(other._IsSigned), _SignGrade(other._SignGrade), _ExecuteGrade(other._ExecuteGrade)
{
    _CheckException();
}

AForm::~AForm()
{
    std::cout << "AForm: Destractor Called\n";
}

AForm&   AForm::operator = (const AForm& other)
{
    if (this == &other)
        return *this;
    this->_IsSigned = other._IsSigned;
    return (*this);
}

const char  *AForm::GradeTooHighException::what() const throw()
{
    return "AForm::GradeTooHighException.";
}


const char  *AForm::GradeTooLowException::what() const throw()
{
    return "AForm::GradeTooLowException.";
}

const char *AForm::FormNotSigned::what() const throw()
{
    return ("AForm:NotSigned");
}

void    AForm::_CheckException() const
{
    if (_SignGrade > 150)
        throw AForm::GradeTooLowException();
    else if (_SignGrade < 1)
        throw AForm::GradeTooHighException();

    if (_ExecuteGrade > 150)
        throw AForm::GradeTooLowException();
    else if (_ExecuteGrade < 1)
        throw AForm::GradeTooHighException();
}

std::string AForm::GetName() const
{
    return _Name;
}

bool        AForm::GetIsSigned() const
{
    return _IsSigned;
}

int         AForm::GetSignedGrade() const
{
    return _SignGrade;
}

int         AForm::GetExecuteGrade() const
{
    return _ExecuteGrade;
}


void        AForm::beSigned(const Bureaucrat& Bure)
{
    if (Bure.getGrade() <= _SignGrade)
        _IsSigned = true;
    else
        throw GradeTooLowException();
}

void AForm::check_execute(Bureaucrat const& executor) const
{

    if (!this->GetIsSigned())
        throw FormNotSigned();
    else if (executor.getGrade() > this->GetExecuteGrade())
        throw Bureaucrat::GradeTooLowException();
}

std::ostream&    operator << (std::ostream& out ,const AForm& form)
{
    out << "name : " << form.GetName();
    out << " | Is_Signed : " << form.GetIsSigned();
    out << " | Signed_Grade : " << form.GetSignedGrade();
    out << " | Execute_Grade : " << form.GetExecuteGrade();
    return out;
}

