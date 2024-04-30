#pragma once
#include <string>
#include <iostream>

using namespace std;

class Human
{
protected:
	string login;
	string pass;
public:
	//getters
	string getLogin();
	string getPass();

	//setters
	void setLogin(string log);
	void setPass(string p);

};

