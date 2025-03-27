#include "./PresidentialPardonForm.hpp"
#include "./Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm: Destructor Called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    check_execute(executor);
    std::cout << this->GetName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}