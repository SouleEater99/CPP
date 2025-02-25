#include "./Character.hpp"
#include "./MateriaSource.hpp"
#include "./Cure.hpp"
#include "./Ice.hpp"

int main()
{
ICharacter*     person = new Character("ali");
IMateriaSource* src = new MateriaSource();

for (int i = 0; i < 4; i++)
    src->learnMateria(new Ice());

std::cout << "++++++++++ { testing enquipe is cross the limit for grabage collector } +++++++++++\n";

for (int i = 0; i < 100; i++)
{
    person->equip(src->createMateria("ice"));
    person->unequip(0);
}
person->use(0, *person  );




delete person;
delete src;
return 0;
}