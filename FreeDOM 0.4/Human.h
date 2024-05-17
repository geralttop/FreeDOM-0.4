#pragma once
#include <string>
#include <iostream>

using namespace std;

class Human
{
protected:
	string login;
	string pass;
	double balance;
	int index;
public:
	//getters
	string getLogin();
	string getPass();
	double getBalance();
	int getIndex();

	//setters
	void setLogin(string log);
	void setPass(string p);
	void setBalance(double bal);
};

