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

	string word; // instead of int data, now the data is both the rating
	// and the accompanying comments – think of when you rate
	// a book or a song, and then are asked to share comments
	//about the book. Both are the data in this node.
	NodeL *next;
	NodeL(); // this constructor takes no input. It and asks the user to input a
	// rating, then reads the rating into the rating field, and
	// then asks the user to input their comments, and reads in the
	// comments into the comments field.

	NodeL(string c);
	// this constructor takes as input an integer and a string, and
	// initializes the rating field to the integer, and the comment
	// field to the string.

	~NodeL();

	void printNode();
};
#endif /* NODEL_HPP_ */

