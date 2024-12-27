#include "./PhoneBook.hpp"

bool    AddContact(PhoneBook& Phone)
{
    Contact Contact_Buffer;

    Phone.print("Entre Your First Name: ");
    if (!std::getline(std::cin, Contact_Buffer.FirstName))
        return (Phone.Error("Fail to Add First Name"));
    Phone.print("Entre Your Last Name: ");
    if (!std::getline(std::cin, Contact_Buffer.LastName))
        return (Phone.Error("Fail to Add Last Name"));
    Phone.print("Entre Your Nick Name: ");
    if (!std::getline(std::cin, Contact_Buffer.NickName))
        return (Phone.Error("Fail to Add F Nick Name"));
    Phone.print("Entre Your Phone Number: ");
    if (!std::getline(std::cin, Contact_Buffer.PhoneNumber))
        return (Phone.Error("Fail to Add Phone Number"));
    Phone.print("Entre Your Dark Secret: ");
    if (!std::getline(std::cin, Contact_Buffer.DarkSecret))
        return (Phone.Error("Fail to Add Dark Secret"));

    //    --------------------[Test Another Way]--------------------------- //

    if (!Phone.readline("Entre Your Favorit Color: ", Contact_Buffer.Color))
        return (false);
    if (Phone.ContactIndex >= 8)
        Phone.ContactIndex = 0;
    Phone.Contact[Phone.ContactIndex++] = Contact_Buffer;
    return (true);
}

int main(void)
{
    PhoneBook Phone;

    while (std::getline(std::cin, Phone.Input))
    {
        if (Phone.Input == "ADD")
            AddContact(Phone);
    }
}