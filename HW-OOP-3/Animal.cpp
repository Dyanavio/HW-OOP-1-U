#include "Animal.h"
#include <iostream>

using namespace std;

Animal::Animal(std::string n, int a) 
{
    name = n;
    age = a;
}

void Animal::makeSound() const
{
    cout << "Animal " + name + ": This is a generic animal sound." << endl;
}

void Animal::eat() const { cout << "Animal is eating." << endl; }

void Animal::sleep() { std::cout << "Animal is sleeping." << endl; }

Mammal::Mammal(std::string n, int a) : Animal(n, a)  // No such constructor instance was present: Animal(n) -> Animal(n, a)
{ 
    isSleeping = false; 
}

void Mammal::makeSound() const
{
    if(!isSleeping) std::cout << "Mammal " + name + ": This is a generic mammal sound." << std::endl;
    else std::cout << "Mammal" + name + " is currently fast asleep" << endl;;
}

void Mammal::eat() const 
{
    if(!isSleeping) std::cout << "Mammal " + name + " is eating." << std::endl; 
    else std::cout << "Mammal " + name + " is currently fast asleep" << endl;;
}

void Mammal::sleep()
{
    std::cout << "Mammal " + name + " is sleeping." << std::endl;
    isSleeping = true;
}

Dog::Dog(std::string n, int a) : Mammal(n, a), tail() //Initialising tail as well
{ 
    isTailWagging = false;
}

void Dog::makeSound() const
{ 
    if (!isSleeping) std::cout << "Dog " + name + ": Woof!" << std::endl;
    else std::cout << "Dog " + name + " is currently fast asleep" << endl;;
}

void Dog::eat() const 
{ 
    if(!isSleeping) std::cout << "Dog " + name + " is eating." << std::endl; 
    else std::cout << "Dog " + name + " is currently fast asleep" << endl;;
}

void Dog::sleep() 
{
    std::cout << "Dog " + name + " is sleeping." << std::endl;
    isSleeping = true;
}

void Dog::fetch() { std::cout << "Dog is fetching." << std::endl; }

void Dog::wagTail()
{
    if (isSleeping) 
    {
        std::cout << "Dog " + name + " can't wag its tail because it's sleeping." << std::endl;
    }
    else 
    {
        cout << "Dog " + name + "is wagging its tail." << endl;
        isTailWagging = true;
    }
}

Cat::Cat(std::string n, int a) : Mammal(n, a) { numberOfLives = 9; }

void Cat::makeSound() const 
{
    if(!isSleeping) std::cout << "Cat " + name + ": Meow!" << std::endl;
    else std::cout << "Cat " + name + " is currently fast asleep" << endl;;
}

void Cat::eat() const 
{
    if(!isSleeping) cout << "Cat " + name + " is sleeping." << endl;
    else std::cout << "Cat " + name + " is currently fast asleep" << endl;;
}

void Cat::sleep() 
{
    std::cout << "Cat " + name + " is sleeping." << std::endl;
    isSleeping = true;
}

Tail::Tail() // Tail has neither name nor age: Tail(string n, int a) -> Tail()
{}

//int Cat::eat = eat(); No such method ever declared