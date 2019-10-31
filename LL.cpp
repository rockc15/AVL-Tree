/*
 * LL.cpp
 *
 *  Created on: Sep 27, 2019
 *      Author: casey
 */


#include "LL.hpp"

//constructor
LL::LL(){
	first = NULL;
	last = NULL;
	size = 0;
	score =0;
}

//destructor
LL::~LL(){
	NodeL * temp = first;
	NodeL * temp2;

	while(temp != NULL){
		temp2= temp->next;
		delete temp;
		temp = temp2;
	}
	cout << "deleting linked list" << endl;
}

//prints out the all the node in the linked list
void LL::printLL(){
	NodeL * temp = first;

	while(temp != NULL){
		temp->printNode();
		temp = temp->next;
	}
}


//pushed a node to the end of the list. Node makes a NodeL on the heap
void LL::push(string c){

	if(first == NULL){
		addFirst(c);
	}else{
		NodeL * temp = first;
		NodeL * node = new NodeL(c);
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = node;
		last = node;
		size++;
	}

}



//add the first elements in the list. Node makes a NodeL on the heap
void LL::addFirst(string c){
	NodeL * node = new NodeL(c);
	first = node;
	last = node;
	size = 1;
}


//fixme
void LL::getScore(){
	NodeL * temp = first;
	while(temp != NULL){
		//score += temp->wscore;
		temp = temp->next;
	}
}



