#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
std::cout << "+++++++++++++ { Polymorphism Classes } ++++++++++++++\n";
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout <<  "type name: " << j->getType() << " " << std::endl;
std::cout <<  "type name: " << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

std::cout << "+++++++++++++ { Wrong Classes } ++++++++++++++\n";
const   WrongAnimal*    wrong_animal = new WrongAnimal();
const   WrongAnimal*       wrong_cat = new WrongCat();

std::cout << "type name: " << wrong_animal->getType() << " " << std::endl;
std::cout << "type name: " << wrong_cat->getType() << " " << std::endl;
wrong_animal->makeSound();
wrong_cat->makeSound();




std::cout << "+++++++++++++ { Destructor part } ++++++++++++++\n";
delete  meta;
delete  j;
delete  i;
delete  wrong_animal;
delete  wrong_cat;
return 0;
}