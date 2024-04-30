#pragma once
#include "Human.h"
#include <vector>
class Dev : public Human
{
private:
	string cardNum;
public:
	Dev(string log, string p, float bal, string cNum);
	Dev();

	string getCardNum() {
		return cardNum;
	}

	void setCardNum(string cNum) {
		cardNum = cNum;
	}
};

