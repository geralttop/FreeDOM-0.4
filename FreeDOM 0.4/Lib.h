#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include "User.h"
#include "Dev.h"
#include "Game.h"

std::string cinSum();
std::string cinPassword();
std::string cinUsDevName();
std::string cinCardNum();

std::vector<User> writingUsers();
std::vector<Dev> writingDevs();
std::vector<Game> writingDevGames(std::string devName);
std::vector<Game> writngAllGames();
std::vector<std::string> writingUseGames(std::string UsName);
std::vector<Game> writingUseGamesData(User user);

void GoToXY(short x, short y);
void ConsoleCursorVisible(bool show, short size);
void bankRequest();

void BigText(int x, int y, int x1, std::string text);
void SignInUs(bool isUser);
void SignInUp(bool isUser);
bool validatePassword(const std::string& password);
bool validateLogin(const std::string& login);
bool validateCardNumber(const std::string& cardNumber);
bool validateGameName(const std::string& name);
void SignUpUs(bool isUser);
void SignUpDev();

void topUp(User currentUser);
void writeOff(Dev currentDev);
void UsCabinet(User currentUser);
void BuyGame(Game game, std::string UsName);
void PageList(Game game, bool isUser, std::string UsName);
void FindGame(std::vector<Game> games, bool isUser, std::string UsName);
void GamesList(std::vector<Game> games, bool isUser, std::string UsName, bool isFind);
void addGame(std::string DevName);
void DevCabinet(Dev currentDev);
void AboutApp();
void firstWin();