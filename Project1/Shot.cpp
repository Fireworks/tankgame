#include <iostream>
#include <stdexcept>
#include "Shot.h"
#include <ctime>
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;

Shot::Shot(int x, int y, int velocity, int angle, int power){
	this->x = x;
	this->y = y;
	this->velocity = velocity;
	this->angle = angle;
	this->power = power;
}

int Shot::getYForX(int x, double gravity){
	
	//cout << x << " " << tan(angle*M_PI/180) << " " << gravity << " " << pow(x,2) << " " << (2*pow(velocity,2)) << " " << pow(cos(angle*M_PI/180),2) << endl;
	int y = this->y + (x-this->x) * tan(angle*M_PI/180) - (gravity * pow(x-this->x,2)) / ((2*pow(velocity,2) * pow(cos(angle*M_PI/180),2))); 
	return y;
}

int Shot::getPower(){
	return power;
}