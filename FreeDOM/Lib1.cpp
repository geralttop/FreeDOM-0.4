#include "Lib1.h"
#include "User.h"
#include <vector>
#include <fstream>
using namespace std;

void test()
{
	cout << "Hello world";
}

vector<User> ttt() {
	vector<User> users;
	ifstream fin;
	fin.open("DataUsers");
	
	while (fin.read((char*)&users[0], sizeof(User))) {
		cout << users[0].getLogin() << users[0].getPass() << users[0].getBalance();
	}
	
	fin.close();
	return users;
}
