/*
 * Population.h
 *
 *  Created on: Apr 7, 2016
 *      Author: Jack
 */

#ifndef POPULATION_H_
#define POPULATION_H_

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Population{
private:
	vector<T> pop;
	vector<T> parentPop;
	vector<T> offspringPop;
	vector<T> combinedPop;
	T fittestEver;
	int fittestGeneration;
	int maxParentPopulation;
	int maxPopulation;
	int maxOffspringPopulation;
	int maxCombinedPopulation;
	int generationCounter;
public:
	Population();
	void initialize(int);
	void add_individual(T);
	void select_parents(int);
	void gen_offspring();
	void joint_pool();
	bool check(float);
	T& operator[] (const int);
};
template <class T>
Population <T>::Population()
{
	maxPopulation = 0;
	maxParentPopulation = 0;
	maxOffspringPopulation = 0;
	maxCombinedPopulation = 0;
	generationCounter = 0;
	fittestGeneration = 0;
}
template <class T>
void Population <T>::initialize(int maxPopulation)
{
	this->maxPopulation = maxPopulation;
	this->maxOffspringPopulation = maxPopulation * 10;
	for(int i = 0; i < maxPopulation; i++)
	{
		T TtoBePushed;
		pop.push_back(TtoBePushed);
	}
	sort(pop.begin(),pop.end());
}
template <class T>
void Population<T>::add_individual(T individualX)
{
	this->maxPopulation++;
	this->maxOffspringPopulation = this->maxPopulation * 10;
	pop.push_back(individualX);
}
template <class T>
void Population <T>::select_parents(int numberOfParents)
{
	maxParentPopulation = numberOfParents;
	for(int i = 0; i < numberOfParents; i++)
	{
		int firstInd = rand() % (maxPopulation);
		T firstElement = pop[firstInd];
		pop.erase(pop.begin() + firstInd);
		int secondInd = rand() % (maxPopulation - 1);
		T secondElement = pop[secondInd];
		pop.erase(pop.begin() + secondInd);
		int thirdInd = rand() % (maxPopulation - 2);
		T thirdElement = pop[thirdInd];
		pop.push_back(firstElement);
		pop.push_back(secondElement);
		pop.push_back(thirdElement);
		if(firstElement == secondElement && firstElement == thirdElement)
		{
			int randomSelect = rand() % 3;
			if(randomSelect == 0)
			{
				parentPop.push_back(firstElement);
			}
			else if(randomSelect == 1)
			{
				parentPop.push_back(secondElement);
			}
			else
			{
				parentPop.push_back(thirdElement);
			}
		}
		else if(firstElement == secondElement)
		{
			int randomSelect = rand() % 2;
			if(randomSelect == 0)
			{
				parentPop.push_back(firstElement);
			}
			else
			{
				parentPop.push_back(secondElement);
			}
		}
		else if(firstElement == thirdElement)
		{
			int randomSelect = rand() % 2;
			if(randomSelect == 0)
			{
				parentPop.push_back(firstElement);
			}
			else
			{
				parentPop.push_back(thirdElement);
			}
		}
		else if(thirdElement == secondElement)
		{
			int randomSelect = rand() % 2;
			if(randomSelect == 0)
			{
				parentPop.push_back(thirdElement);
			}
			else
			{
				parentPop.push_back(secondElement);
			}
		}
		else if(firstElement < secondElement && firstElement < thirdElement)
		{
			parentPop.push_back(firstElement);
		}
		else if(secondElement < thirdElement)
		{
			parentPop.push_back(secondElement);
		}
		else
		{
			parentPop.push_back(thirdElement);
		}
	}
}
template <class T>
void Population<T>::gen_offspring()
{
	for(int i = 0; i < (this->maxOffspringPopulation/2) ; i++)
	{
		int firstInd = rand() % maxParentPopulation;
		int secondInd = rand() % (maxParentPopulation - 1);
		T offspring_1;
		T offspring_2;
		T individual_1 = parentPop[firstInd];
		parentPop.erase(parentPop.begin() + firstInd);
		T individual_2 = parentPop[secondInd];
		parentPop.push_back(individual_1);
		offspring_1 = individual_1 * individual_2;
		offspring_2 = individual_1 * individual_2;
		offspringPop.push_back(offspring_1);
		offspringPop.push_back(offspring_2);
	}
}
template <class T>
void Population<T>::joint_pool()
{
	maxCombinedPopulation = maxParentPopulation + maxOffspringPopulation;
	combinedPop = offspringPop;
	for(int i = 0; i < maxParentPopulation; i++)
	{
		combinedPop.push_back(parentPop[i]);
	}
	sort(combinedPop.begin(),combinedPop.end());

	pop.clear();
	for(int i = 0; i < maxPopulation; i++)
	{
		pop.push_back(combinedPop[i]);
	}
	parentPop.clear();
	combinedPop.clear();
	offspringPop.clear();
}
template <class T>
bool Population<T>::check(float desiredFitness)
{
	generationCounter++;
	if(generationCounter == 1)
	{
		fittestEver = pop[0];
		fittestGeneration = 1;
	}
	if(fittestEver > pop[0])
	{
		fittestEver = pop[0];
		fittestGeneration = generationCounter;
	}
	cout << "Generation " << generationCounter;
	cout << ". Most fit: " << pop[0];
	cout << "Least fit: " << pop[maxPopulation - 1];
	if(generationCounter >= 1000)
	{
		cout << "\nFittest ever: "<< fittestEver;
		cout << "From generation " << fittestGeneration<< endl;;
		return false;
	}
	for(int i = 0; i < maxPopulation; i++)
	{
		if(pop[i] <= desiredFitness)
		{
			return false;
		}
	}
	return true;
}
template <class T>
T& Population<T>::operator[](const int nIndex)
{
	return pop[nIndex];
}
#endif /* POPULATION_H_ */
