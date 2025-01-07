#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./Contact.hpp"

class   PhoneBook
{
    private:
        std::string Input;
        Contact     Contacts[8];
        int         ContactNumber;
        int         ContactIndex;

    public:
        PhoneBook();
        int     Error(std::string ErrorMsg);
        bool    readline(std:: string Prompt, std::string& Contact_Buffer);
        void    print_ten_char(const std::string& str);
        bool    IsNumber(std::string& str);
        void    ReplaceWhiteSpace(std::string& str, char replacement);
        bool    SetContact(Contact &Contact_Buffer);
        bool    AddContact();
        bool    FindContactInfo();
        void    Run();


    
};

#endif