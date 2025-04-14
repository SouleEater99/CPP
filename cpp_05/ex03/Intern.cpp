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
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; i++)
        if (formName == names[i])
            return i;
    return -1;
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
    if (index < 0)
    {
        std::cerr << "Intern: Failed to Create Form. (This Form Name doesn't Exist)\n";
        return NULL;
    }
    try
    {
        AForm* form = (this->*_CreateForm[index])(target);
        std::cout << "Intern creates " << form->GetName() << std::endl;
        return form;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Failed Form creation: " << e.what() << std::endl;
        return NULL;
    }
    return NULL;
}