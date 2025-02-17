#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
std::cout << "+++++++++++++ { Polymorphism Classes using pointer} ++++++++++++++\n";
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout <<  "type name: " << j->getType() << " " << std::endl;
std::cout <<  "type name: " << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

std::cout << "+++++++++++++ { Polymorphism Classes using reference} ++++++++++++++\n";
const Animal& ref_meta = Animal();
const Animal& ref_j = Dog();
const Animal& ref_i = Cat();

std::cout <<  "type name: " << ref_i.getType() << " " << std::endl;
std::cout <<  "type name: " << ref_j.getType() << " " << std::endl;
ref_i.makeSound();
ref_j.makeSound();
ref_meta.makeSound();



std::cout << "+++++++++++++ { Wrong Classes } ++++++++++++++\n";
const   WrongAnimal*    wrong_animal = new WrongAnimal();
const   WrongAnimal*       wrong_cat = new WrongCat();

std::cout << "type name: " << wrong_animal->getType() << " " << std::endl;
std::cout << "type name: " << wrong_cat->getType() << " " << std::endl;
wrong_animal->makeSound();
wrong_cat->makeSound();

std::cout << "+++++++++++++ { Call without ref/pointers } ++++++++++++++\n";
Animal without_animal = Animal();
Animal without_dog = Dog();
Animal without_cat = Cat();

std::cout << "type name: " << without_animal.getType() << " " << std::endl;
std::cout << "type name: " << without_dog.getType() << " " << std::endl;
std::cout << "type name: " << without_cat.getType() << " " << std::endl;
without_animal.makeSound();
without_dog.makeSound();
without_cat.makeSound();

std::cout << "+++++++++++++ { Test assingment operator = } ++++++++++++++\n";
without_cat = without_animal;
std::cout << "type name: " << without_cat.getType() << " " << std::endl;
without_cat.makeSound();

std::cout << "+++++++++++++ { Destructor part } ++++++++++++++\n";
delete  meta;
delete  j;
delete  i;
delete  wrong_animal;
delete  wrong_cat;
return 0;
}