#include "./PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook()
{
    Input = "";
    ContactIndex = 0;
    ContactNumber = 0;
}

int PhoneBook::Error(std::string ErrorMsg)
{
    std::cout << ErrorMsg << '\n';
    return (false);
}

bool PhoneBook::readline(std:: string Prompt, std::string& Contact_Buffer)
{
    std::cout << (Prompt);
    if (!std::getline(std::cin, Contact_Buffer))
        return (false);
    if (Contact_Buffer.empty())
        return false;
    return (true);
}

bool PhoneBook::SetContact(Contact& Contact_Buffer)
{
    std::string buffer;

    if (!readline("Entre Your First Name: ", buffer))
        return (Error("Fail to Add First Name"));
    Contact_Buffer.SetFirstName(buffer);
    if (!readline("Entre Your Last Name: ", buffer))
        return (Error("Fail to Add Last Name"));
    Contact_Buffer.SetLastName(buffer);
    if (!readline("Entre Your Nick Name: ", buffer))
        return (Error("Fail to Add F Nick Name"));
    Contact_Buffer.SetNickName(buffer);
    if (!readline("Entre Your Phone Number (without spaces): ", buffer) || !IsNumber(buffer))
        return (Error("Fail to Add Phone Number"));
    Contact_Buffer.SetPhoneNumber(buffer);
    if (!readline("Entre Your Dark Secret: ", buffer))
        return (Error("Fail to Add Dark Secret"));
    Contact_Buffer.SetDarkSecret(buffer);
    return true;
}

void PhoneBook::ReplaceWhiteSpace(std::string &str, char replacement)
{
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (std::isspace(str[i]))
            str[i] = replacement;
    }
}

void PhoneBook::print_ten_char(const std::string &str)
{
    std::string truncted;

    if (str.empty())
    {
        std::cout << std::setw(10);
        return;
    }
    truncted = str.substr(0, 10);
    ReplaceWhiteSpace(truncted, ' ');
    if (truncted.length() == 10 && str.length() > 10)
        truncted[9] = '.';
    std::cout << std::setw(10) << truncted;
}

bool PhoneBook::IsNumber(std::string &str)
{
    for (int i = 0; i < (int)str.length(); i++)
        if (!std::isdigit(str[i]))
            return false;
    return true;
}

bool    PhoneBook::PrintTable()
{
    if (ContactNumber == 0)
        return(Error("No Contact To Display Or Search For\n"));
    std::cout << "|  Index   | First Name | Last Name  | Nick Name  |\n";
    std::cout << " -------------------------------------------------\n";
    for (int i = 0; i < ContactNumber; i++)
    {

        std::cout << "|" << std::setw(10) << i << "| ";
        print_ten_char(Contacts[i].GetFirstName());
        std::cout << " | ";
        print_ten_char(Contacts[i].GetLastName());
        std::cout << " | ";
        print_ten_char(Contacts[i].GetNickName());
        std::cout << " |\n";
    }
    return true;
}

bool    PhoneBook::FindContactInfo()
{
    int     index;

    if (!PrintTable())
        return false;
    if (!readline("Please Entre The Contact Index: ", Input))
        return(Error("No Input\n"));
    index = std::atoi(Input.c_str());
    if (!IsNumber(Input) || index > 8 ||  index < 0 || index >= ContactNumber)
        return (Error("This Index Not Found!\n"));
    else
    {
        std::cout << "Index : " << index << std::endl;
        std::cout << "First Name : " << Contacts[index].GetFirstName() << std::endl;
        std::cout << "Last Name : " << Contacts[index].GetLastName() << std::endl;
        std::cout << "Nick Name : " << Contacts[index].GetNickName() << std::endl;
    }
    return true;
}

bool    PhoneBook::AddContact()
{
    Contact Contact_Buffer;

    if (!SetContact(Contact_Buffer))
        return false;
    if (ContactIndex >= MAX_CONTACTS)
        ContactIndex = 0;
    Contacts[ContactIndex++] = Contact_Buffer;
    if (ContactNumber < MAX_CONTACTS)
        ContactNumber++;
    return (true);
}

void    PhoneBook::Run()
{
    std::string  prompt;

    prompt = "Welcome to your phonebook\nwrite ADD to add contact\nWrite SEARCH  to find contact info\nWrite EXIT\n";
    std::cout << prompt; 
    while (true)
    {
        if (!readline("Choose Your Option? ", Input) && !Input.empty())
            return ;
        if (Input == "ADD")
            AddContact();
        else if (Input == "SEARCH")
            FindContactInfo();
        else if (Input == "EXIT")
            return ;
    }
}