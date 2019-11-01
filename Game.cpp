//Casey Rock
//10/31/2019
//this file contains the game class

#include <iostream>
#include "BSTY.hpp"
#include "Game.hpp"
#include "LL.hpp"
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

//constructor for the game class
Game::Game(){
	readTreeFromFile("usanoswears.txt");

	numletters = 0;
	numright = 0;
	totalwords = 0;
	wordlist = new LL();
}

//constructor for the game class takes in a game file and reads
//the words into the AVL tree then sets the number of words, number of right
//words and totalwords to 0. Then creates a new linked list on the heap.
Game::Game(string filen){
	readTreeFromFile(filen);

	numletters = 0;
	numright = 0;
	totalwords = 0;
 	wordlist = new LL();
}

//starts the game. Asks for the users for a number representing the amount of
//letters they want. Then it askes the user to insert words.
//The inserted words are then pushed onto the linked list, and checked to see
//if they are in the AVL tree. After all the words are inserted, the games
//calculates their total scored based on the number of right words and wrong
//words.
void Game::startGame() {
	cout << "How many letters do you want?" << endl;
	cin >> numletters;
	currletters = getLetters(numletters);
	cout << "Your letters are: " << endl;
	for (int i = 0; i < numletters; i++) {
		cout << currletters[i] << " ";
	}
	cout << endl;
	cout << "Start generating words: " << endl;
	getWords();
	wordlist->printLL();
	cout << endl;
	checkWordsForScore();
	int score = numright * 5 - (totalwords-numright) * 10;
	cout << "Number of valid words: " << numright << " Invalid words: " << (totalwords - numright) << endl;
	cout << "Final Score is: "  << score << endl;
}

//gets the users input and pushs the word onto a linked list
void Game::getWords() {
	string s;

	cin >> s;
	while (s != "-1") {
		wordlist->push(s);
		cin >> s;
		cout << endl;
	}
}


//gets n letters where n is the number of letters the user
//specified in the game
char * Game::getLetters(int x) {
	char vowel[5] = {'a','e','i','o','u'};
	char conso[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
	char *curr = new char[x];
 	int v = rand() %(x-2) + 1;

	for (int i = 0; i < v; i++) {
		int y = rand() %5;
		curr[i] = vowel[y];
	}
	for (int i = v; i < x; i++) {
		int y = rand() %21;
		curr[i] = conso[y];
	}
	for (int i = 0; i < x; i++) {
		cout << curr[i] << endl;
	}
	return curr;
}

//checks to see if the word the user inputs is in the AVL Tree
bool Game::checkWLetters(string s) {
	char tempchar[numletters];
	for (int i = 0; i < numletters; i++) {
		tempchar[i] = currletters[i];
	}
	for (int i = 0; i < s.size(); i++) {
		int j = 0;
		while ((j < numletters) && (s[i] != tempchar[j] )) {
			j++;
		}
		if (j == numletters) {
			return false;
		}
		tempchar[j] = '1';
	}
	if (dict->find(s)== NULL){
		return false;
	}
	return true;
}

//checks to see if the word is valid or invalied then updates the numbers
//that are right and numbers that are wrong
void Game:: checkWordsForScore() {
	NodeL *tmp = wordlist->first;
	while (tmp != NULL) {
		if (checkWLetters(tmp->word) ) {
			cout << tmp->word << " is okay " << endl;

			numright++;
		}
		else {
			cout << tmp->word << " is invalid " << endl;
		}
		totalwords++;
		tmp = tmp->next;
	}
}

//reads the file into the AVL Tree
void Game::readTreeFromFile (string dictfile) {
	dict = new BSTY();
	ifstream file(dictfile.c_str());
	string word;
	while (!file.eof()) {
		file >> word;
		if (!file.eof()) {
			dict->insertit(word);
		}
	}
	return;
}





