#include "Human.h"
#include <string>

string Human::getLogin() {
	return login;
}
string Human::getPass() {
	return pass;
}

//setters
void Human::setLogin(string log) {
	login = log;
}
void Human::setPass(string p) {
	pass = p;
}