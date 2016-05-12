/*
 * IndividualABCD.h
 *
 *  Created on: Apr 9, 2016
 *      Author: Jack
 */

#ifndef INDIVIDUALABCD_H_
#define INDIVIDUALABCD_H_

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include "Container.h"
using namespace std;

class IndividualABCD:public Container{
private:
	float a;
	float b;
	float c;
	float d;
	float fitness;
	int numberOfPoints;
	vector<float> x;
public:
	IndividualABCD();
	IndividualABCD(float, float, float, float);
	~IndividualABCD() {};
	void display() const;
	bool operator> (const IndividualABCD &) const; //compare individual's fitness
	bool operator< (const IndividualABCD &) const;
	bool operator== (const IndividualABCD &) const;
	bool operator <= (const float &) const;
	IndividualABCD operator* (const IndividualABCD &) const; //to generate a cross-over and mutation at same time
	friend ostream& operator<< (ostream &out, const IndividualABCD& indABCD) //need friend function for the << overload
	{
		return out << setprecision(10)<< "A value: " << indABCD.a << ". B value: " << indABCD.b <<". C value: " << indABCD.c <<". D value: " << indABCD.d << ". Fitness: " << indABCD.fitness << endl;
	}
};



#endif /* INDIVIDUALABCD_H_ */
