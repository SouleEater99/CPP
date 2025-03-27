#include "./RobotomyRequestForm.hpp"
#include "./Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm: Destructor Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    check_execute(executor);
    std::cout << this->GetName()  << " has been robotomized successfully 50% of the time." << std::endl;
}