/*
 * IndividualXY.h
 *
 *  Created on: Apr 6, 2016
 *      Author: Jack
 */

#ifndef INDIVIDUALXY_H_
#define INDIVIDUALXY_H_
#define pi 3.1415926535897
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cmath>
#include <iomanip>
#include "Container.h"
using namespace std;

class IndividualXY:public Container{
private:
	float x;
	float y;
	float fitness;
public:
	IndividualXY();
	IndividualXY(float, float);
	~IndividualXY() {};
	float getX() const;
	float getY() const;
	float getFitness() const;
	void setX(float);
	void setY(float);
	void display() const;
	bool operator> (const IndividualXY &) const; //to compare the fitness of individuals
	bool operator< (const IndividualXY &) const;
	bool operator== (const IndividualXY &) const;
	bool operator <= (const float &) const; //to see if you reached the desired fitness
	IndividualXY operator* (const IndividualXY &) const; //overloaded version for crossover and mutation
	friend ostream& operator<< (ostream &out, const IndividualXY& indXY) //need friend function for the << overload
	{
		return out << setprecision(10)<< "X value: " << indXY.x << ". Y value: " << indXY.y << ". Fitness: " << indXY.fitness << endl;
	}
};



#endif /* INDIVIDUALXY_H_ */
