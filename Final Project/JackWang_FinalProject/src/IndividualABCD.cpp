/*
 * IndividualABCD.cpp
 *
 *  Created on: Apr 10, 2016
 *      Author: Jack
 */

#include "IndividualABCD.h"

IndividualABCD::IndividualABCD()
{
	a = ((float)rand()/(float)(RAND_MAX)) * 200 - 100; //genome range from -100 to 100
	b = ((float)rand()/(float)(RAND_MAX)) * 200 - 100;
	c = ((float)rand()/(float)(RAND_MAX)) * 200 - 100;
	d = ((float)rand()/(float)(RAND_MAX)) * 200 - 100;
	numberOfPoints = 21;
	fitness = 0;
	for(int i = 0; i < numberOfPoints; i++)
	{
		x.push_back(i-10);
	}
	for(int i = 0; i < numberOfPoints; i++) ///equation: 20x^3 - 13 x^2 + 19x + 2
	{
		float theoretical_Y = 20*(pow(x[i],3)) - 13*(pow(x[i],2)) + 19*x[i] + 2; //calculating the fitness
		float experimental_Y = a*(pow(x[i],3)) + b*(pow(x[i],2)) + c*x[i] + d;
		fitness = fitness + pow((theoretical_Y - experimental_Y),2);
	}
	fitness = fitness/numberOfPoints;
}
IndividualABCD::IndividualABCD(float a, float b, float c, float d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	numberOfPoints = 21;
	fitness = 0;
	for(int i = 0; i < numberOfPoints; i++)
	{
		x.push_back(i-10);
	}
	for(int i = 0; i < numberOfPoints; i++) ///equation: 20x^3 - 13 x^2 + 19x + 2
	{
		float theoretical_Y = 20*(pow(x[i],3)) - 13*(pow(x[i],2)) + 19*x[i] + 2; //calculating the fitness
		float experimental_Y = a*(pow(x[i],3)) + b*(pow(x[i],2)) + c*x[i] + d;
		fitness = fitness + pow((theoretical_Y - experimental_Y),2);
	}
	fitness = fitness/numberOfPoints;
}
void IndividualABCD::display() const
{
	cout << setprecision(10) << "A value: " << a << ". B value: " << b << ". C value: " << c << ". D value: " << d << ". Fitness: " << fitness << endl;
}
bool IndividualABCD::operator >(const IndividualABCD&x) const
{
	if(this->fitness > x.fitness)
	{
		return true;
	}
	return false;
}
bool IndividualABCD::operator <(const IndividualABCD&x) const
{
	if(this->fitness < x.fitness)
	{
		return true;
	}
	return false;
}
bool IndividualABCD::operator ==(const IndividualABCD&x) const
{
	if(this->fitness == x.fitness)
	{
		return true;
	}
	return false;
}
bool IndividualABCD::operator <=(const float&desiredValue) const
{
	if(this->fitness <= desiredValue)
	{
		return true;
	}
	return false;
}
IndividualABCD IndividualABCD::operator* (const IndividualABCD&other) const
{
	float areaOfParents_A = abs(this->a - other.a); //calculating the crossover
	float areaOfParents_B = abs(this->b - other.b);
	float areaOfParents_C = abs(this->c - other.c);
	float areaOfParents_D = abs(this->d - other.d);
	float dFactor_A = ((float)rand()/(float)(RAND_MAX)) * 1.5 - 0.25; //make the area vary by -0.25 to 1.25 the original size
	float dFactor_B = ((float)rand()/(float)(RAND_MAX)) * 1.5 - 0.25;
	float dFactor_C = ((float)rand()/(float)(RAND_MAX)) * 1.5 - 0.25;
	float dFactor_D = ((float)rand()/(float)(RAND_MAX)) * 1.5 - 0.25;
	float averageOfParents_A = ((this->a + other.a) / 2);
	float averageOfParents_B = ((this->b + other.b) / 2);
	float averageOfParents_C = ((this->c + other.c) / 2);
	float averageOfParents_D = ((this->d + other.d) / 2);
	float newArea_A = areaOfParents_A * dFactor_A;
	float newArea_B = areaOfParents_B * dFactor_B;
	float newArea_C = areaOfParents_C * dFactor_C;
	float newArea_D = areaOfParents_D * dFactor_D;
	float lowerLimit_A = averageOfParents_A - (newArea_A/2);
	float lowerLimit_B = averageOfParents_B - (newArea_B/2);
	float lowerLimit_C = averageOfParents_C - (newArea_C/2);
	float lowerLimit_D = averageOfParents_D - (newArea_D/2);
	float offspring_A = ((float)rand()/(float)(RAND_MAX)) * newArea_A + lowerLimit_A; //child attributes depends on the possible area and a range defined by parents
	float offspring_B = ((float)rand()/(float)(RAND_MAX)) * newArea_B + lowerLimit_B;
	float offspring_C = ((float)rand()/(float)(RAND_MAX)) * newArea_C + lowerLimit_C;
	float offspring_D = ((float)rand()/(float)(RAND_MAX)) * newArea_D + lowerLimit_D;
	float mutate_area = 0.02; //mutation range from -0.01 to 0.01
	float mutate_lowerLimit_A = offspring_A - 0.01;
	float mutate_lowerLimit_B = offspring_B - 0.01;
	float mutate_lowerLimit_C = offspring_C - 0.01;
	float mutate_lowerLimit_D = offspring_D - 0.01;
	offspring_A = ((float)rand()/(float)(RAND_MAX)) * mutate_area + mutate_lowerLimit_A;
	offspring_B = ((float)rand()/(float)(RAND_MAX)) * mutate_area + mutate_lowerLimit_B;
	offspring_C = ((float)rand()/(float)(RAND_MAX)) * mutate_area + mutate_lowerLimit_C;
	offspring_D = ((float)rand()/(float)(RAND_MAX)) * mutate_area + mutate_lowerLimit_D;
	IndividualABCD offspring(offspring_A,offspring_B,offspring_C,offspring_D);
	return offspring;
}
