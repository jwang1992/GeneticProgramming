/*
 * main.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: Jack
 */

#include <iostream>
#include "IndividualXY.h"
#include "IndividualABCD.h"
#include "Population.h"
#include <string>
#include "string.h"
using namespace std;

int main(){
	srand(time(NULL));
	while(1)
	{
		cout << "Welcome to Genetic Algorithm!" << endl;
		cout << "Please choose a population to work with by pressing 1 or 2." << endl;
		cout << "1. XY for Ackley's function\n2. ABCD for Mean Squared Error\n3. Exit" << endl;
		string choice;
		getline(cin,choice);
		while(choice != "1" && choice != "2" && choice != "3")
		{
			cout << "Invalid choice. Please re-enter your selection." << endl;
			getline(cin,choice);
		}
		if(choice == "1")
		{
			string junk;
			cout << "You have selected Ackley's function." << endl;
			cout << "The program will optimize x and y according to the following equation." << endl;
			cout << "fitness = ((-20) * exp(-0.2*sqrt(0.5*(pow(x,2) + pow(y,2))))) - exp(0.5*(cos(2*pi*x) + cos(2*pi*y))) + exp(1) + 20" << endl;
			cout << "Population: 1000. Parents: 100. Children: 10000. Number of generations: 1000" << endl;
			cout << "Press enter to continue." << endl;
			getline(cin,junk);
			Population<IndividualXY> pop1;
			pop1.initialize(1000);
			while(pop1.check(0))
			{
				pop1.select_parents(100);
				pop1.gen_offspring();
				pop1.joint_pool();
			}
			break;
		}
		else if(choice == "2")
		{
			string junk;
			cout << "You have selected Mean Squared Error." << endl;
			cout << "The program will optimize a, b, c and d according to the following equation." << endl;
			cout << "equation: 20x^3 - 13 x^2 + 19x + 2" << endl;
			cout << "Population: 1000. Parents: 100. Children: 10000. Number of generations: 1000" << endl;
			cout << "Press enter to continue." << endl;
			getline(cin,junk);
			Population<IndividualABCD> pop1;
			pop1.initialize(1000);
			while(pop1.check(0))
			{
				pop1.select_parents(100);
				pop1.gen_offspring();
				pop1.joint_pool();
			}
			break;
		}
		else
		{
			break;
		}
	}
}


