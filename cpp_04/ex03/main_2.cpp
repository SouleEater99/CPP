#include "./Character.hpp"
#include "./MateriaSource.hpp"
#include "./Cure.hpp"
#include "./Ice.hpp"

int main()
{
    std::cout << "++++++++++ { testing the same addree if it will handle the same address } +++++++++++\n";

    AMateria *tmp2 = new Cure();
    ICharacter *person = new Character("ali");

    for (int i = 0; i < 4; i++)
    {
        person->equip(tmp2);
        person->unequip(3);
    }

    delete person;
    return 0;
}