#include <iostream>
#include <stdexcept>
#include "Player.h"
#include <ctime>

using namespace std;

Player::Player(int width, int height, int xPos, int health){
	this->width = width;
	this->height = height;
	this->xPos = xPos;
	this->health = health;
	alive = true;
}

Player::Player(){}

int Player::getHeight(){
	return height;
}

int Player::getWidth(){
	return width;
}

int Player::getPos(){
	return xPos;
}

int Player::getHealth(){
	return health;
}

void Player::setHealth(int newHealth){
	health = newHealth;
}

bool Player::isAlive(){
	return alive;
}