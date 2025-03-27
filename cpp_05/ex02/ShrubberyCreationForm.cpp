#include "./ShrubberyCreationForm.hpp"
#include "./Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm: Destructor Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    const std::string FileName = this->GetName() + "_shrubbery";
    const std::string shrubbery =
        "       *\n"
        "      ***\n"
        "     *****\n"
        "    *******\n"
        "   *********\n"
        "  ***********\n"
        " *************\n"
        "      |||\n"
        "      |||\n";

    check_execute(executor);

    std::fstream file(FileName.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: File " << this->GetName() << "_shrubbery not open\n";
        return;
    }
    file << shrubbery << std::endl;
    file.close();
}