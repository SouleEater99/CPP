#include "./PhoneBook.hpp"


int PhoneBook::Error(std::string ErrorMsg)
{
        std::cout << ErrorMsg << '\n';
        return (false);
}

bool PhoneBook::readline(std:: string Prompt, std::string& Contact_Buffer)
{
    std::cout << (Prompt);
    if (!std::getline(std::cin, Contact_Buffer))
        return (false);
    if (Contact_Buffer.empty())
        return false;
    return (true);
}


void    PhoneBook::ReplaceWhiteSpace(std::string& str, char replacement)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (std::isspace(str[i]))
            str[i] = replacement;
    }
}

void    PhoneBook::print_ten_char(std::string& str)
{
    std::string truncted;

    if (str.empty())
    {
        std::cout << std::setw(10);
        return ;
    }
    truncted = str.substr(0, 10);
    ReplaceWhiteSpace(truncted, ' ');
    if (truncted.length() == 10 && str.length() > 10)
        truncted[9] = '.';
    std::cout  << std::setw(10)<< truncted;
}

bool    PhoneBook::IsNumber(std::string& str)
{
    if (str.length() > 2 || !isdigit(str[0]))
        return (false);
    return true;
}