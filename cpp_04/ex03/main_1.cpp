#include "./Character.hpp"
#include "./MateriaSource.hpp"
#include "./Cure.hpp"
#include "./Ice.hpp"

int main()
{
AMateria        *tmp;
Character*     me = new Character("me");
IMateriaSource* src = new MateriaSource();

for (int i = 0; i < 4; i++)
{
    if (i % 2 == 0)
        tmp = new Ice();
    else
        tmp = new Cure();
    src->learnMateria(tmp);
}
for (int i = 0; i < 4; i++)
{
    if (i % 2 == 0)
        me->equip(src->createMateria("ice"));
    else
        me->equip(src->createMateria("cure"));
    me->use(i, *me);
}

std::cout << "++++++++++ { testing copy assignment and copt constructor } +++++++++++\n";

Character who = *me;
Character who_2(*me);
std::cout << "Who Name: " << who.getName() << std::endl;
who.equip(NULL);
who.use(0 ,*me);
std::cout << "Who Name: " << who_2.getName() << std::endl;
who_2.equip(NULL);
who_2.use(0 ,*me);

delete me;
delete src;
return 0;
}