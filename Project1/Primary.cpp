#include <stdlib.h>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <istream>
#include <string>
#include "World.h"
#include "Player.h"



using namespace std;

int main(int c, char *v[]){

start:

	cout << "How many players do you have?" << endl;
	string input = "";
	int numPlayers = 0;
	getline(cin,input);
	stringstream myStream(input);
	if(!(myStream >> numPlayers)){
		cout << "Invalid number" << endl;
		goto start;
	}
	World* world = new World(numPlayers,80,30,2,2,10);
	world->init();
	while(true){
	forloops:
	for (int i = 0 ; i < numPlayers ; i++){
		if(!world->players[i]->isAlive())
			continue;
		world->currentPlayer = i;
		world->print();
		angle:
		cout << "Player " << i+1 << ": Enter an angle between 0 and 180 (0 is east, 180 is west):" << endl;
		string input2 = "";
		int angle = 0;
		getline(cin,input2);
		stringstream myStream2(input2);
		if(!(myStream2 >> angle) || angle < 0 || angle > 180){
			cout << "Invalid number" << endl;
			goto angle;
		}
		cout << "You entered " << angle << endl;
	
		velocity:
		cout << "Player " << i+1 << ": Enter a velocity between 0 and 100:" << endl;
		string input3 = "";
		int velocity = 0;
		getline(cin,input3);
		stringstream myStream3(input3);
		if(!(myStream3 >> velocity) || velocity < 0 || velocity > 100){
			cout << "Invalid number" << endl;
			goto velocity;
		}
		cout << "You entered " << velocity << endl;

		world->doShot(world->players[i],velocity,angle);

	}
	int winner = -1;
	for(int j = 0 ; j < numPlayers ; j++){
		if(world->players[j]->alive && winner < 0)
			winner = j;
		else if(world->players[j]->alive)
			goto forloops;
	}
	world->print();
	cout << "Player " << winner + 1 << " WINS!" << endl;
	again:
	cout << "Play again? 0 for no, 1 for yes" << endl;
	string input4 = "";
		int again = 0;
		getline(cin,input4);
		stringstream myStream4(input4);
		if(!(myStream4 >> again) || again < 0 || again > 1){
			cout << "Invalid number" << endl;
			goto again;
		}
	if(again == 0)
		return 0;
	else
		goto start;
	}
	
}
