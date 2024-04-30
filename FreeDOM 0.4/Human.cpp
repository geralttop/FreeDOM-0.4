#include "Human.h"
#include <string>

string Human::getLogin() {
	return login;
}
string Human::getPass() {
	return pass;
}
float Human::getBalance() {
	return balance;
}

//setters
void Human::setLogin(string log) {
	login = log;
}
void Human::setPass(string p) {
	pass = p;
}
void Human::setBalance(float bal) {
	balance = bal;
}