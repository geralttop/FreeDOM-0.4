#include "Dev.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

Dev::Dev(string log, string p, float bal, string cNum) {
	login = log;
	pass = p;
	balance = bal;
	cardNum = cNum;
}
Dev::Dev() {

}