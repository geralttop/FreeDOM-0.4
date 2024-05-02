#include "Game.h"
#include <string>

Game::Game(string name, string about, float price, int index) {
	this->name = name;
	this->about = about;
	this->price = price;
	this->index = index;
}

Game::Game() {
}

string Game::getName() {
	return name;
}
string Game::getAbout() {
	return about;
}
float Game::getPrice() {
	return price;
}
int Game::getIndex() {
	return index;
}
//setters
void Game::setName(string name) {
	this->name = name;
}
void Game::setAbout(string about) {
	this->about = about;
}
void Game::setPrice(float price) {
	this->price = price;
}