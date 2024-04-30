#pragma once
#include "Human.h"
#include <vector>
class User : public Human
{
private:
	float balance;
public:
	User(string log, string p, float bal);
	User();
	float getBalance();
	void setBalance(float bal);
	static vector<User> writingUsers();
	void checkingLoginData(vector<User> users);
	void UsSignInUp(vector<User> users);
	bool validatePassword(const std::string& password);
	bool validateLogin(const std::string& login);
	void SignInUs(std::vector<User> users);
};