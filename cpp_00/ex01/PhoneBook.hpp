#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./Contact.hpp"

class   PhoneBook
{
    public:
        std::string Input;
        Contact     Contact[8];
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
    bool readline(std:: string Prompt, std::string Contact_Buffer)
    {
        print(Prompt);
        if (!std::getline(std::cin, Contact_Buffer))
            return (false);
        return (true);
    }
    

};

#endif