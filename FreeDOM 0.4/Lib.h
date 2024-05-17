#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include "User.h"
#include "Dev.h"
#include "Game.h"

void bankRequest();
string cinSum();
vector<Dev> writingDevs();
vector<User> writingUsers();
vector<Game> writingDevGames(string devName);
vector<Game> writngAllGames();
vector<string> writingUseGames(string UsName);
void SignInUs(bool isUser);
void SignInUp(bool isUser);
void SignUpUs(bool isUser);
void SignUpDev();
void firstWin();
void AboutApp();
void GamesList(vector<Game> games, bool isUser, string UsName, bool isFind);
void UsCabinet(User currentUser);
void topUp(User currentBalance);
void DevCabinet(Dev currenDev);
void addGame(string DevName);