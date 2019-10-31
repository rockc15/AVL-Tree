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
	// (4 pts for working) write a method that prints out the linked list


	void push(string c);
	// (4 pts for working)
	// pushes a new node (with rating r and c comments) onto the end of the linked
	// list
	// (remember to reset the last pointer) – I called this from the
	// insertInOrder() method.



	void addFirst(string c);
	//(3 pts for working)
	//adds the very first node (made from r and c) to an empty list
	// I called this from insertInOrder

	void getScore();


	};

	#endif /* LL_HPP_ */

