#ifndef __world__
#define __world__

#include <iostream>
#include "Player.h"
#include "Shot.h"

using namespace std;

class World{

public:
	World(int numPlayers, int width, int height, int playerWidth, int playerHeight, double gravity);
	void init();
	void print();
	void reset();
	int getPlayerLocation(Player p);
	int getAltitude(int x);
	int getLastShotHeight(int x);
	void resetLastShot();
	int doShot(int playerIndex, int velocity, int angle);
	bool isDead(int playerIndex);

	int numPlayers;
	int width;
	int height;
	int playerWidth;
	int playerHeight;
	double gravity;
	
	int playerLocation;
	int altitude;
	int lastShotHeight;
	void doShot(Player* p, int velocity, int angle);
	//bool isDead;

	Player** players;
	int land[80];
	Shot* currentShot;

	int currentPlayer;
	bool shot;
};
#endif