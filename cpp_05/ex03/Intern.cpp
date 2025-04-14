#include "./Intern.hpp"

Intern::Intern()
{
    _CreateForm[0] = &Intern::_CreateShrubberyCreation;
    _CreateForm[1] = &Intern::_CreateRobotMyRequest;
    _CreateForm[2] = &Intern::_CreatePresidentialPardon;
    std::cout << "Intern: Default Constructor Called\n";
}

Intern::Intern(const Intern& other)
{
    for (int i = 0; i < 3; i++)
        _CreateForm[i] = other._CreateForm[i];
    std::cout << "Intern: copy Constructor Called\n";
}

Intern::~Intern()
{
    std::cout << "Intern: Deconstructor Called\n";
}

Intern& Intern::operator = (const Intern& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 3; i++)
            _CreateForm[i] = other._CreateForm[i];
    }
    return *this;
}


int       Intern::_GetIndexForm(const std::string& formName)
{
    if (formName == "shrubbery creation")
        return 0;
    else if (formName == "shrubbery creation") 
        return 1;
    else if (formName == "presidential pardon") 
        return 2;
    return 3;
}

AForm*      Intern::_CreateShrubberyCreation(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm*      Intern::_CreateRobotMyRequest(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm*      Intern::_CreatePresidentialPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm*    Intern::makeForm(const std::string& formName, const std::string& target)
{
    int index;

    index = _GetIndexForm(formName);
    if (index <= 2)
        return (this->*_CreateForm[index])(target);
    return NULL;
}