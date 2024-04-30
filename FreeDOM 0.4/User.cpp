#include "User.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

User::User(string log, string p, float bal) {
	login = log;
	pass = p;
	balance = bal;
}
User::User() {

}
