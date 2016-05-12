/*
 * IndividualXY.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: Jack
 */

#include "IndividualXY.h"

IndividualXY::IndividualXY()
{
	x = ((float)rand()/(float)(RAND_MAX)) * 200 - 100; //genome range from -100 to 100
	y = ((float)rand()/(float)(RAND_MAX)) * 200 - 100;
	fitness = ((-20) * exp(-0.2*sqrt(0.5*(pow(x,2) + pow(y,2))))) - exp(0.5*(cos(2*pi*x) + cos(2*pi*y))) + exp(1) + 20;
}
IndividualXY::IndividualXY(float x, float y)
{
	this->x = x;
	this->y = y;
	fitness = ((-20) * exp(-0.2*sqrt(0.5*(pow(x,2) + pow(y,2))))) - exp(0.5*(cos(2*pi*x) + cos(2*pi*y))) + exp(1) + 20;
}
float IndividualXY::getX() const
{
	return x;
}
float IndividualXY::getY() const
{
	return y;
}
float IndividualXY::getFitness() const
{
	return fitness;
}
void IndividualXY::setX(float x)
{
	this->x = x;
}
void IndividualXY::setY(float y)
{
	this->y = y;
}
void IndividualXY::display() const
{
	cout << setprecision(10)<< "X value: " << x << ". Y value: " << y << ". Fitness: " << fitness << endl;
}
bool IndividualXY::operator >(const IndividualXY&x) const
{
	if(this->fitness > x.fitness)
	{
		return true;
	}
	return false;
}
bool IndividualXY::operator <(const IndividualXY&x) const
{
	if(this->fitness < x.fitness)
	{
		return true;
	}
	return false;
}
bool IndividualXY::operator ==(const IndividualXY&x) const
{
	if(this->fitness == x.fitness)
	{
		return true;
	}
	return false;
}
bool IndividualXY::operator <=(const float&desiredValue) const
{
	if(this->fitness <= desiredValue)
	{
		return true;
	}
	return false;
}
IndividualXY IndividualXY::operator *(const IndividualXY&other) const
{
	float areaOfParents_X = abs(this->x - other.x); //calculate the crossover
	float areaOfParents_Y = abs(this->y - other.y);
	float dFactor_X = ((float)rand()/(float)(RAND_MAX)) * 1.5 - 0.25; //make the area vary by -0.25 to 1.25 the original size
	float dFactor_Y = ((float)rand()/(float)(RAND_MAX)) * 1.5 - 0.25;
	float averageOfParents_X = ((this->x + other.x) / 2);
	float averageOfParents_Y = ((this->y + other.y) / 2);
	float newArea_X = areaOfParents_X * dFactor_X;
	float newArea_Y = areaOfParents_Y * dFactor_Y;
	float lowerLimit_X = averageOfParents_X - (newArea_X/2);
	float lowerLimit_Y = averageOfParents_Y - (newArea_Y/2);
	float offspring_X = ((float)rand()/(float)(RAND_MAX)) * newArea_X + lowerLimit_X; //child attributes depends on the possible area and a range defined by parents
	float offspring_Y = ((float)rand()/(float)(RAND_MAX)) * newArea_Y + lowerLimit_Y;
	float mutate_area = 0.02; //mutation range of -0.01 to 0.01
	float mutate_lowerLimit_X = offspring_X - 0.01;
	float mutate_lowerLimit_Y = offspring_Y - 0.01;
	offspring_X = ((float)rand()/(float)(RAND_MAX)) * mutate_area + mutate_lowerLimit_X;
	offspring_Y = ((float)rand()/(float)(RAND_MAX)) * mutate_area + mutate_lowerLimit_Y;
	IndividualXY offspring(offspring_X,offspring_Y);
	return offspring;
}
