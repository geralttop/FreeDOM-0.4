#pragma once
#include <string>
#include <iostream>

using namespace std;

class Game
{
private:
	string name;
	string about;
	double price;
	int index;
	string devName;
public:
	Game(string name, string about, double price, int index, string devName);
	Game();
	//getters
	string getName();
	string getAbout();
	double getPrice();
	int getIndex();
	string getDevName();
	//setters
	void setName(string name);
	void setAbout(string about);
	void setPrice(double price);
	void setDevName(string devName);
};

