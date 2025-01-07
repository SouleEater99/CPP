#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>


class   Contact
{
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkSecret;
    public:
        std::string GetFirstName() const;
        std::string GetLastName()const;
        std::string GetNickName()const;
        std::string GetPhoneNumber() const;
        std::string GetDarkSecret()const;

        void    SetFirstName(std::string first);
        void    SetLastName(std::string last);
        void    SetNickName(std::string nick);
        void    SetPhoneNumber(std::string phone);
        void    SetDarkSecret(std::string secret);
};

#endif