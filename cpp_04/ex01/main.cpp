#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    {
        Animal *animal[100];

        for (int i = 0; i < 100; i++)
        {
            if (i < 50)
                animal[i] = new Cat();
            else
                animal[i] = new Dog();
        }

        for (int i = 0; i < 100; i++)
            animal[i]->makeSound();
        for (int i = 0; i < 100; i++)
            delete animal[i];
    }
    {
        std::cout << "+++++++++ test copy constructor  +++++++++\n";
        Animal *dog = new Dog();
        Animal *cat = new Cat();
        Animal *animal = new Animal();

        *animal = *dog;
        std::cout << "Animal Type: " << animal->getType() << std::endl;
        animal->makeSound();
        

        delete dog;
        delete cat;
        delete animal;
    }
}
