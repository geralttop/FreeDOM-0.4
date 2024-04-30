#pragma once
#include "Human.h"
class User : public Human
{
private:
	float balance;
public:
	User(string log, string p, float bal);
	float getBalance();
	void setBalance(float bal);
};

