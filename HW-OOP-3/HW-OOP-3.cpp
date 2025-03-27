#include <iostream>
#include <string>
#include "Animal.h"

using namespace std;

int main() {
    Dog d("Fido", 3);
    Cat c("Fluffy", 5);
    Dog d1("Barky", 3);

    Mammal* arr[] = { &d, &c, &d1 };

    // should woof, meow, woof
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        arr[i]->makeSound();
    }

    // should eat in dog, cat, dog order
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        arr[i]->eat();
    }

    // should be woof, meow, woof
    cout << endl;
    for (int i = 0; i < 3; i++) 
    {
        arr[i]->makeSound();
    }

    // should sleep in dog, cat, dog order
    cout << endl;
    for (int i = 0; i < 3; i++) 
    {
        arr[i]->sleep();
    }

    // shoudn't do anything as they're sleeping
    cout << endl;
    for (int i = 0; i < 3; i++) 
    {
        arr[i]->makeSound();
    }

    // shoudn't eat actually, as they are sleeping
    cout << endl;
    for (int i = 0; i < 3; i++) 
    {
        arr[i]->eat();
    }

    // Class Mammal does not have an instance of wagTail method and thus this method cannot be called through base class
    // ! - Можно через dynamic cast, но Барбара Лисков где-то будет очень сильно ругаться
    // shouldn't wag tails, they are sleeping, but some of them do not wag tail at all
    /*for (int i = 0; i < 3; i++) 
    {
        is(arr[i] is )
        arr[i]->wagTail();
    }*/

    // do they really need to sleep forever? :'( - Sadge

    // Hah, that's stange :)
    //Tail t("Taily", 2);
    //t.makeSound(); - Tail is just a part of the dog and cannot exist on its own
    // (Except for medical purposes)
}