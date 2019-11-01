/*
 * SLL.hpp
 *
 *  Created on: Sep 27, 2019
 *      Author: casey
 */




#ifndef LL_HPP_
#define LL_HPP_
#include <stdlib.h>
#include <iostream>

#include "NodeL.hpp"
using namespace std;

class LL {
public:
	NodeL *first;
	NodeL *last;
	int size;
	int score;

	LL();
	~LL();
	void printLL();

	void push(string c);

	void addFirst(string c);

	void getScore();

	};

	#endif /* LL_HPP_ */

