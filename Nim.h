#pragma once
/*
 * Course: CS215-00x
 * Project: Project 2
 * File: Nim.h
 * Purpose: it declares the class named Nim
 *
 */
#ifndef NIM_H
#define NIM_H

const int PILE_MAX = 50;
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);  //use code 232 in ASCII Table to represent marble
const int WIDTH = 10;   // for layout purpose

class Nim
{
public:
	//default constructor
	Nim();

	//constructor
	Nim(int iniSize);

	//set the current size of the pile 
	void setPileSize(int size);

	//get how many marbles on the pile
	int getPileSize() const;

	//if it is computer's turn to play
	//it is either under smart mode or non-smart mode
	void computer_play(bool smart);

	//if it is player's (the user's) turn to play
	//(comment it out in Lab9 only)
	//(you still need to define this member function in Project2)
	//void player_play();

	//display the current marbles on the pile
	void print() const;

private:
	int pileSize;	// represents how many marbles on the 
};
#endif	/* NIM_H */