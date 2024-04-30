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
public:
	//getters
	string getLogin();
	string getPass();
	float getBalance();

	//setters
	void setLogin(string log);
	void setPass(string p);
	void setBalance(float bal);
};

