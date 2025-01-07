#include "./Contact.hpp"

std::string Contact::GetFirstName()     const {return FirstName;}
std::string Contact::GetLastName()      const {return LastName;}
std::string Contact::GetNickName()      const {return NickName;}
std::string Contact::GetPhoneNumber()   const {return PhoneNumber;}
std::string Contact::GetDarkSecret()    const {return DarkSecret;}

void    Contact::SetFirstName(std::string first)    {FirstName = first;}
void    Contact::SetLastName(std::string last)     {LastName = last;}
void    Contact::SetNickName(std::string nick)     {NickName = nick;}
void    Contact::SetPhoneNumber(std::string phone)    {PhoneNumber = phone;}
void    Contact::SetDarkSecret(std::string secret)   {DarkSecret = secret;}