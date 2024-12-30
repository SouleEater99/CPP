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
    if (Phone.ContactNumber < 8)
        Phone.ContactNumber++;
    return (true);
}

bool    FindContactInfo(PhoneBook& Phone)
{
    int index;

    if (Phone.ContactNumber == 0)
        return(Phone.Error("No Contact To Display Or Search For\n"));
    std::cout << "|  Index   | First Name | Last Name  | Nick Name  |\n";
    std::cout << " -------------------------------------------------\n";
    for (int i = 0; i < Phone.ContactNumber; i++)
    {
        std::cout << "|    " << i << "     | ";
        Phone.print_ten_char(Phone.Contacts[i].FirstName);
        std::cout << " | ";
        Phone.print_ten_char(Phone.Contacts[i].LastName);
        std::cout << " | ";
        Phone.print_ten_char(Phone.Contacts[i].NickName);
        std::cout << " |\n";
    }
    if (!Phone.readline("Please Entre The Contact Index: ", Phone.Input))
        return(Phone.Error("No Input\n"));
    index = std::atoi(Phone.Input.c_str());
    if (index > 8 || index < 0 || index >= Phone.ContactNumber || !Phone.IsNumber(Phone.Input))
        return (Phone.Error("This Index Not Found!\n"));
    else
    {
        std::cout << "Index : " << index << std::endl;
        std::cout << "First Name : " << Phone.Contacts[index].FirstName << std::endl;
        std::cout << "Last Name : " << Phone.Contacts[index].LastName << std::endl;
        std::cout << "Nick Name : " << Phone.Contacts[index].NickName << std::endl;
    }
    return true;
}

int main(void)
{
    PhoneBook Phone;

    std::string  prompt;

    prompt = "Welcome to your phonebook\nwrite ADD to add contact\nWrite SEARCH  to find contact info\nWrite EXIT\n";
    Phone.print(prompt);
    while (true)
    {
        Phone.readline("Choose Your Option? ", Phone.Input);
        if (std::cin.eof())
            break;
        if (Phone.Input == "ADD")
            AddContact(Phone);
        else if (Phone.Input == "SEARCH")
            FindContactInfo(Phone);
        else if (Phone.Input == "EXIT")
            return 0;
    }
}