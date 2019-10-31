/*
 * NodeL.cpp
 *
 *  Created on: Sep 27, 2019
 *      Author: casey
 */


#include "NodeL.hpp"

//constructor for the NodeL class. Ask the user for input on the
//rating and the commnets
NodeL::NodeL(){
	string com;

	cin >> com;
	cout << endl;


	word = com;

	next = NULL;
}

//constructor for the NodeL class sets the rating and word to the
//parameters
NodeL::NodeL( string word){
	this->word = word;

	next = NULL;
}

//destructor for the NodeL class
NodeL::~NodeL(){
	cout << "deleting node " << word << endl;
}

//prints the rating and word for a NodeL
void NodeL::printNode(){
	cout << word<< ", " ;
}
