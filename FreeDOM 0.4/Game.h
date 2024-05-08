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
	string devName;
public:
	Game(string name, string about, float price, int index, string devName);
	Game();
	//getters
	string getName();
	string getAbout();
	float getPrice();
	int getIndex();
	string getDevName();
	//setters
	void setName(string name);
	void setAbout(string about);
	void setPrice(float price);
	void setDevName(string devName);
};

