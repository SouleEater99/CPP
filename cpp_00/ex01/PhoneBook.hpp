#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./Contact.hpp"

#define MAX_CONTACTS 8

class   PhoneBook
{
    private:
        std::string Input;
        Contact     Contacts[MAX_CONTACTS];
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
        bool    PrintTable();
        bool    FindContactInfo();
        void    Run();


    
};

#endif