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
	users.push_back(User("Tima", "1234", 23.5));
	cout << users[0].getLogin();
	return users;
}
