#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
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
