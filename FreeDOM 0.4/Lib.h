#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include "User.h"

vector<User> writingUsers();
void SignInUs(bool isUser);
void SignInUp(bool isUser);
void SignUpUs();
void SignUpDev();
void firstWin();
void UsCabinet(User currentUser);
void topUp(User currentBalance);