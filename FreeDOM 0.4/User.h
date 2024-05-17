#pragma once
#include "Human.h"
#include <vector>
class User : public Human
{
private:

public:
	User(string log, string p, double bal, int index);
	User();
};