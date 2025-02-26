#include "./Character.hpp"
#include "./MateriaSource.hpp"
#include "./Cure.hpp"
#include "./Ice.hpp"

int main()
{
    AMateria* ice = new Ice();
    AMateria* p = new Cure();

    *p = *ice;

    std::cout << "ice : "  << ice->getType() <<  std::endl;
    std::cout << "p : "  << p->getType() <<  std::endl;




delete  ice;
delete  p;


return 0;
}