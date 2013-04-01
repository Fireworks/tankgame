#ifndef __player__
#define __player__

#include <iostream>

using namespace std;

class Player{

public:
	Player(int width, int height, int xPos, int health);
	Player();
	int getWidth();
	int getHeight();
	int getPos();
	int getHealth();
	void setHealth(int newHealth);
	bool isAlive();

	int width;
	int height;
	int xPos;
	int health;
	bool alive;
};
#endif