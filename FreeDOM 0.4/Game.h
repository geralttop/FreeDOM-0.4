#pragma once
#include <string>
#include <iostream>

using namespace std;

class Game
{
private:
	string name;
	string about;
	float price;
	int index;
public:
	Game(string name, string about, float price, int index);
	Game();
	//getters
	string getName();
	string getAbout();
	float getPrice();
	int getIndex();
	//setters
	void setName(string name);
	void setAbout(string about);
	void setPrice(float price);
};

