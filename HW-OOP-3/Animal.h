#pragma once
#ifndef ANIMAL_H
#define ANIM0L_H
#include <string>

class Animal 
{
protected:
	std::string name;
	int age;

public:
	Animal(std::string n, int a);
	virtual void makeSound() const; //Methods are made const as they do not change data values
	virtual void eat() const;
	virtual void sleep(); // Except for that one
};

class Mammal : protected Animal {
protected:
	bool isSleeping; //invalid bool member name: getSleeping -> isSleeping

public:
	Mammal(std::string n, int a);
	virtual void makeSound() const;	//
	virtual void eat() const;		// Three method created as virtual so that derived classes are able to overload them
	virtual void sleep();		    // Enabling late binding
};

class Tail //: public Dog - Tail is a part of a dog but not its 'special case'
{
public:
	Tail();
};

class Dog : public Mammal 
{
private:
	Tail tail; // Tail is a part of the dog and has to be here supporting the composition relationship
	bool isTailWagging;

public:
	Dog(std::string n, int a);
	void makeSound() const override; // Methods are made const again for the same reason as above
	void eat() const override;
	void sleep() override;
	void fetch();
	void wagTail();
};

class Cat : public Mammal 
{
private:
	int numberOfLives; // Как жестоко

public:
	Cat(std::string n, int a);
	void makeSound() const override; // Methods are made const again for the same reason as above
	void eat() const override;
	void sleep() override;
};


#endif