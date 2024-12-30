#include "./PhoneBook.hpp"

bool    AddContact(PhoneBook& Phone)
{
    Contact Contact_Buffer;

    if (!Phone.readline("Entre Your First Name: ", Contact_Buffer.FirstName))
        return (Phone.Error("Fail to Add First Name"));
    if (!Phone.readline("Entre Your Last Name: ", Contact_Buffer.LastName))
        return (Phone.Error("Fail to Add Last Name"));
    if (!Phone.readline("Entre Your Nick Name: ", Contact_Buffer.NickName))
        return (Phone.Error("Fail to Add F Nick Name"));
    if (!Phone.readline("Entre Your Phone Number: ", Contact_Buffer.PhoneNumber))
        return (Phone.Error("Fail to Add Phone Number"));
    if (!Phone.readline("Entre Your Dark Secret: ", Contact_Buffer.DarkSecret))
        return (Phone.Error("Fail to Add Dark Secret"));

    if (Phone.ContactIndex >= 8)
        Phone.ContactIndex = 0;
    Phone.Contacts[Phone.ContactIndex++] = Contact_Buffer;
    return (true);
}


int main(void)
{
    PhoneBook Phone;

    std::string  prompt;

    prompt = "Welcome to your phonebook\nwrite ADD to add contact\nWrite SEARCH  to find contact info\nWrite EXIT\n";
    while (Phone.readline(prompt, Phone.Input))
    {
        int index;
        if (Phone.Input == "ADD")
            AddContact(Phone);
        index = Phone.ContactIndex - 1;
        if  (Phone.ContactIndex > 0)
            Phone.PrintContactInfo(Phone.Contacts[index], index);
    }
}