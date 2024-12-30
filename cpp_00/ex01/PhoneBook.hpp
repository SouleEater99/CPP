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
    
    void PrintContactInfo(Contact& contacts, int i)
    {
        if (!contacts.FirstName.empty())
            std::cout << Contacts[i].FirstName << '\n';
        if (!contacts.LastName.empty())
            std::cout << Contacts[i].LastName << '\n';
        if (!contacts.NickName.empty())
            std::cout << Contacts[i].NickName << '\n';
        if (!contacts.PhoneNumber.empty())
            std::cout << Contacts[i].PhoneNumber << '\n';
        if (!contacts.DarkSecret.empty())
            std::cout << Contacts[i].DarkSecret << '\n';
    }

    void    print_ten_char(std::string& str)
    {
        int i;

        i = 0;
        if (str.empty())
            return;
        while (i < str.length() && i < 9)
            putchar(str[i++]);
        if (str.length() > 10)
            putchar('.');
        else if (i < str.length())
            putchar(str[i++]);
        while (i++ < 9)
        {
            putchar(' '); 
        }
    }

    bool    IsNumber(std::string& str)
    {
        if (str.length() > 2 || !isdigit(str[0]))
            return (false);
        return true;
    }
};

#endif