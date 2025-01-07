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
        PhoneBook()
        {
            ContactIndex  = 0;
            ContactNumber = 0;
        }

        int     Error(std::string ErrorMsg);
        bool    readline(std:: string Prompt, std::string& Contact_Buffer);
        void    print_ten_char(std::string& str);
        bool    IsNumber(std::string& str);
        void    ReplaceWhiteSpace(std::string& str, char replacement);


    
};

#endif