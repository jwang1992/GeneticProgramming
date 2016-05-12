/*
 * Container.h
 *
 *  Created on: Mar 17, 2016
 *      Author: JAC_WANG
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

using namespace std;
class Container{ //mostly all pure virtual functions which force the derived classes to have an implementation
public:
	virtual ~Container() {};
	virtual void display() const = 0;
};



#endif /* CONTAINER_H_ */
