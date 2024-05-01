#include "Dev.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

Dev::Dev(string log, string p, float bal, string cNum, int index) {
	login = log;
	pass = p;
	balance = bal;
	cardNum = cNum;
	this->index = index;
}
Dev::Dev() {

}