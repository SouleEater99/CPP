#ifndef PHONEBOOK_HPP
#Define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class   PhoneBook
{
    PhoneBook()
    {
        ContactNumber = 0;
    }
    public:
        Contact Contact[8];
        int     ContactNumber;

}

#endif