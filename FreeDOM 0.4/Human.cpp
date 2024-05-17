#include "Human.h"
#include <string>

string Human::getLogin() {
	return login;
}
string Human::getPass() {
	return pass;
}
double Human::getBalance() {
	return balance;
}
int Human::getIndex() {
	return index;
}

//setters
void Human::setLogin(string log) {
	login = log;
}
void Human::setPass(string p) {
	pass = p;
}
void Human::setBalance(double bal) {
	balance = bal;
}