#include "./Character.hpp"
#include "./MateriaSource.hpp"
#include "./Cure.hpp"
#include "./Ice.hpp"
#define MATERIA_LEARN 10


int main()
{
AMateria*       tmp[MATERIA_LEARN];
ICharacter*     me = new Character("me");
IMateriaSource* src = new MateriaSource();

for (int i = 0; i < MATERIA_LEARN; i++)
{
    if (i % 2 == 0)
        tmp[i] = new Ice();
    else
        tmp[i] = new Cure();
    src->learnMateria(tmp[i]);
    std::cout << "=========\n";
    me->equip(tmp[i]);
    me->use(0, *me);
}


delete me;
delete src;
return 0;
}