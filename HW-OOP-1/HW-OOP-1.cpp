#include <iostream>
#include <string>
#include "color.hpp"
using namespace std;

class BoardGame
{
private:
	string name;
	double time; // in minutes
	int players;
	string developer;
	double price;
public:
	BoardGame(string name, double time, int players, string developer, double price) : name(name), time(time), players(players), developer(developer), price(price) {}
	BoardGame()
	{
		name = "[Not announced]";
		time = 0;
		players = 0;
		developer = "[Unknown]";
		price = 0;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setTime(double time)
	{
		this->time = time;
	}
	void setPlayers(int players)
	{
		this->players = players;
	}
	void setDeveloper(string developer)
	{
		this->developer = developer;
	}
	void setPrice(double price)
	{
		this->price = price;
	}
	void output()
	{
		cout << dye::aqua("Name: ") << name << endl;
		cout << dye::aqua("Time: ") << time << " minutes" << endl;
		cout << dye::aqua("Players: ") << players << endl;
		cout << dye::aqua("Developer: ") << developer << endl;
		cout << dye::aqua("Price: ") << price << " USD" << endl;
	}
};

int main()
{
	BoardGame game1 = BoardGame("Monopoly", 60, 4, "Hasbro", 20);
	BoardGame game2 = BoardGame();
	BoardGame game3 = BoardGame("Munchkin", 90, 6, "Steve Jackson Games", 25);

	cout << dye::red("----- Before -----") << endl;
	game1.output();
	cout << endl;
	game2.output();
	cout << endl;
	game3.output();

	game2.setName("Fallen London");
	game2.setTime(360);
	game2.setDeveloper("Failbetter Games");
	game2.setPlayers(4);
	game2.setPrice(60);

	game1.setTime(90);
	game3.setDeveloper("Steve Jackson");


	cout << dye::green("\n\n----- After -----") << endl;
	game1.output();
	cout << endl;
	game2.output();
	cout << endl;
	game3.output();
}
