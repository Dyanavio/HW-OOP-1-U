#include <iostream>
#include <string>
#include "color.hpp"

using namespace std;

class Engine
{
protected:
	double power;
	string type;

public:
	Engine(int p, string t)
	{
		power = p;
		type = t;
	}
	Engine(const Engine& e)
	{
		power = e.power;
		type = e.type;
	}
	string getType()
	{
		return type;
	}
	double getPower()
	{
		return power;
	}
	void setPower(int p)
	{
		if (p > 0) power = p;
		else p = 0;
	}
	void setType(string t)
	{
		if (t != "") type = t;
		else type = "Default";
	}
};

class Vehicle
{
protected:
	Engine* engine;
	double maxSpeed;

public:
	Vehicle(Engine* e, double s)
	{
		engine = new Engine(*e);
		maxSpeed = s;
	}
	virtual string getDescription()
	{
		return "Vehicle with engine type: " + engine->getType();
	}
	virtual ~Vehicle() { delete engine; }
};

class Car : public Vehicle
{
private:
	int doors;

public:
	Car(Engine* e, double s, int d) : Vehicle(e, s)
	{
		doors = d;
	}
	string getDescription() override
	{
		return "Car (Engine: " + engine->getType() + " | Power: " + to_string(engine->getPower()) + " | Doors: " + to_string(doors) + ")";
	}
};

int main()
{
	Engine* engine = new Engine(900, "Hybrid");
	Vehicle* vehicle = new Vehicle(engine, 210);
	Car* car = new Car(engine, 180, 4);

	cout << dye::light_blue("Vehicle methods:") << endl;
	cout << vehicle->getDescription() << endl;

	cout << dye::light_aqua("Car methods:") << endl;
	cout << car->getDescription() << endl;

	delete vehicle;
	delete car;
	delete engine;
}