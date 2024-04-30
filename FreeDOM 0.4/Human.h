#pragma once
#include <string>
#include <iostream>

using namespace std;

class Human
{
protected:
	string login;
	string pass;
	float balance;
	int index;
public:
	//getters
	string getLogin();
	string getPass();
	float getBalance();
	int getIndex();

	//setters
	void setLogin(string log);
	void setPass(string p);
	void setBalance(float bal);
};

