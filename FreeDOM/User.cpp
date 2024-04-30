#include "User.h"
#include <string>
#include <iostream>

User::User(string log, string p, float bal) {
	login = log;
	pass = p;
	balance = bal;
}
float User::getBalance() {
	return balance;
}
void User::setBalance(float bal) {
	balance = bal;
}