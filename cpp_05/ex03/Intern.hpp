#ifndef INTERN_HPP
#define INTERN_HPP

#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"


class Intern
{
private:
    AForm*      (Intern::*_CreateForm[3])(const std::string& target);
    AForm*      _CreateShrubberyCreation(const std::string& target);
    AForm*      _CreateRobotMyRequest(const std::string& target);
    AForm*      _CreatePresidentialPardon(const std::string& target);
    int         _GetIndexForm(const std::string& formName);
public:
    Intern();
    Intern(const Intern &other);
    ~Intern();
    Intern& operator = (const Intern& other);

    AForm*    makeForm(const std::string& formName, const std::string& target);
};





#endif