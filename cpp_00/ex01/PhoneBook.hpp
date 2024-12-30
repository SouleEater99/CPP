#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./Contact.hpp"

class   PhoneBook
{
    public:
        std::string Input;
        Contact     Contacts[8];
        int         ContactIndex;
    PhoneBook(void)
    {
        ContactIndex = 0;
    }

    int Error(std::string ErrorMsg)
    {
        std::cout << ErrorMsg << '\n';
        return (false);
    }

    void    print(std::string Msg)
    {
        std::cout << Msg;
    }

    bool readline(std:: string Prompt, std::string& Contact_Buffer)
    {
        print(Prompt);
        if (!std::getline(std::cin, Contact_Buffer))
            return (false);
        return (true);
    }
    
    void PrintContactInfo(Contact& contacts, int i)
    {
        print(Contacts[i].FirstName);
        print(Contacts[i].LastName);
        print(Contacts[i].NickName);
        print(Contacts[i].PhoneNumber);
        print(Contacts[i].DarkSecret);
    }

};

#endif