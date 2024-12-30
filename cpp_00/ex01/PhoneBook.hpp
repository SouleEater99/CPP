#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./Contact.hpp"

class   PhoneBook
{
    public:
        std::string Input;
        Contact     Contacts[8];
        int         ContactNumber;
        int         ContactIndex;
    PhoneBook(void)
    {
        ContactIndex  = 0;
        ContactNumber = 0;
    }

    int Error(std::string ErrorMsg)
    {
        std::cout << ErrorMsg << '\n';
        return (false);
    }

    void    print_nl(std::string& Msg)
    {
        std::cout << Msg << std::endl;
    }

    void    print(std::string& Msg)
    {
        std::cout << Msg;
    }

    bool readline(std:: string Prompt, std::string& Contact_Buffer)
    {
        print(Prompt);
        if (!std::getline(std::cin, Contact_Buffer))
            return (false);
        if (Contact_Buffer.empty())
            return false;
        return (true);
    }

    void    print_ten_char(std::string& str)
    {
        int i;
        int count;

        i = 0;
        count = 0;
        if (str.empty())
            return;
        while (i < (int)str.length() && i < 9)
        {
            if (iswspace(str[i]) && count == 0)
            {

                std::cout << ' ';
                count++;
            }
            else if (!iswspace(str[i]))
            {
                std::cout << str[i];
                count = 0;
            }
            i++;
        }
        if (str.length() > 10)
        {
            putchar('.');
            i++;
        }
        else if (i < (int)str.length())
            putchar(str[i++]);
        while (i++ < 10)
            putchar(' '); 
    }

    bool    IsNumber(std::string& str)
    {
        if (str.length() > 2 || !isdigit(str[0]))
            return (false);
        return true;
    }
};

#endif