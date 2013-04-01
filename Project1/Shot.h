#ifndef __shot__
#define __shot__

#include <iostream>

using namespace std;

class Shot{

public:
	Shot(int x, int y, int velocity, int angle, int power);
	int getYForX(int x, double gravity);
	int getPower();

	int x;
	int y;
	int velocity;
	int angle;
	int power;
};
#endif