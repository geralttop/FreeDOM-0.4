#include "User.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

User::User(string log, string p, float bal, int index) {
	login = log;
	pass = p;
	balance = bal;
	this->index = index;
}
User::User() {

}
