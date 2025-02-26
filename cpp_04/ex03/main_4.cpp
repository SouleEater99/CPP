#include "./Character.hpp"
#include "./MateriaSource.hpp"
#include "./Cure.hpp"
#include "./Ice.hpp"

int main()
{
    Ice ice;
    Ice p(ice);
    
    p = ice;
    Character a;
    Character b;

    a = b;
    AMateria& materia = ice;

    AMateria&  materia_2 = ice;

    std::cout << "materia : "  << materia.getType() <<  std::endl;
    std::cout << "materia_2 : "  << materia_2.getType() <<  std::endl;







return 0;
}