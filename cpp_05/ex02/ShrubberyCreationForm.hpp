#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "./AForm.hpp"

class ShrubberyCreationForm: public AForm
{
public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm&  operator = (const ShrubberyCreationForm& other);

    void execute(Bureaucrat const & executor) const;

    class FileNotOpen : public std::exception
    {
        public:
            const char *what() const throw();
    };
};



#endif