#include <iostream>
#include <stdexcept>
#include "World.h"
#include "Player.h"
#include "Shot.h"
#include <vector>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;


World::World(int numPlayers, int width, int height, int playerWidth, int playerHeight, double gravity){
	this->numPlayers = numPlayers;
	this->width = width;
	this->height = height;
	this->playerHeight = playerHeight;
	this->playerWidth = playerWidth;
	this->gravity = gravity;
	this->currentShot = NULL;
}

void World::init(){
	players = new Player*[numPlayers];
	srand(time(NULL));
	int randHeight = (rand() % 10) + 3;
	land[0] = randHeight;

	for(int i = 0 ; i < numPlayers ; i++){
		loop:
		int tempRand = rand() % width;
		for(int j = 0 ; j < i; j++){
			if(tempRand < players[j]->getPos() + 5 && tempRand > players[j]->getPos() - 5)
				goto loop;
		}
		players[i] = new Player(playerWidth, playerHeight, tempRand, 1);
		int currentRand = tempRand;
	}

	for(int i = 1; i < width ; i++){
		int tempRand = (rand() % 3);
		if(tempRand == 0){
			land[i] = land[i-1];
		}else if(tempRand == 1){
			land[i] = land[i-1]+1;
		}else{
			land[i] = land[i-1]-1;
		}
		if (land[i] < 1 || land[i] > 13)
			i--;
	}
}
	
void World::print(){
	for(int i = height ; i > 0 ; i--){
		for(int j = 0; j < width ; j++){
			for(int k = 0 ; k < numPlayers ; k++){
				if(players[k]->getPos() + playerWidth >= j && j >= players[k]->getPos() && i >= land[players[k]->getPos()]+1 && i <= land[players[k]->getPos()]+playerHeight+1 && players[k]->isAlive()){
					if(currentPlayer == k)
						cout << "&";
					else
						cout << "@";
					goto jloop;
				}
			}

			if(currentShot != NULL){
				int compare = currentShot->getYForX(j,gravity);
				if(i == compare && i > land[j] && (currentShot->angle < 90 || j < currentShot->x) && (currentShot->angle > 90 || j > currentShot->x)){
					cout << "*";
					goto jloop;
				}
			}


			if(i == land[j]){
				cout << "T";
			}
			else
				cout << " ";
		jloop:;
		}
		cout << endl;
	}

	std::cout << std::string(width, '*') << std::endl;
	
}

void World::reset(){
	for(int i = 0 ; i < width ; i++){
		land[i] = NULL;
	}
}

int World::getPlayerLocation(Player p){
		return p.getPos();
}

int World::getAltitude(int x){
	return land[x];
}

void World::doShot(Player *p, int velocity, int angle){
	currentShot = new Shot(p->getPos(),land[p->getPos()]+2,velocity,angle,1);

	for(int x = 0 ; x < width ; x++){
		int y = currentShot->getYForX(x,gravity);
		for(int j = 0 ; j < numPlayers ; j++){
			Player* tempP = players[j];
			if(tempP != p && tempP->isAlive() && tempP->getPos() <= x && x <= tempP->getPos() + playerWidth && y >= land[x] && y <= land[x]+playerHeight+1 && (currentShot->angle < 90 || x < currentShot->x) && (currentShot->angle > 90 || x > currentShot->x))
				tempP->alive = false;
		}
	}
}