#include "./PhoneBook.hpp"

int main(void)
{
    PhoneBook Phone;

    std::string  prompt;
    std::string  Input;

    prompt = "Welcome to your phonebook\nwrite ADD to add contact\nWrite SEARCH  to find contact info\nWrite EXIT\n";
    std::cout << prompt; 
    while (true)
    {
        if (!Phone.readline("Choose Your Option? ", Input))
            return (0);
        if (Input == "ADD")
            Phone.AddContact();
        else if (Input == "SEARCH")
            Phone.FindContactInfo();
        else if (Input == "EXIT")
            return 0;
    }
}