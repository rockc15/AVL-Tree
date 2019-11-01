/*
 * NodeL.hpp
 *
 *  Created on: Sep 27, 2019
 *      Author: casey
 */


#ifndef NODEL_HPP_
#define NODEL_HPP_
#include <iostream>

using namespace std;

class NodeL {
	friend class LL;

public:
	string word;
	NodeL *next;


	NodeL();

	NodeL(string c);

	~NodeL();

	void printNode();
};
#endif /* NODEL_HPP_ */

