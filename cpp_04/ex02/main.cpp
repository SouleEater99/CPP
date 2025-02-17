#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    Animal *animal[100];

    // animal[0] = new Animal;
    // Animal Aanimal = Animal(); // will not work cause the class is abstract 
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
