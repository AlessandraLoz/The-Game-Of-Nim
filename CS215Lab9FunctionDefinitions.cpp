/*
 *Course: CS215 - 05
 *Project: Lab 9 (As part of Project 2)
 *Purpose: It demonstrates the game of Nim played between two computer players
 *         In combinatorial game theory, a two-player deterministic perfect information turn-based game
 *         is a first-player-win if with perfect play the first player to move can always force a win.
 *         This program also shows that the game of Nim is a first-player-win game using two computer players.
 *Author: Alessandra Lozano
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Nim.h"

using namespace std;

Nim::Nim()
{
    //initializing pile size
    pileSize = 0;
}

Nim::Nim(int iniSize)
{
    //checking to see if the size fits the ramge of minimum and max
    if (iniSize >= PILE_MIN && iniSize <= PILE_MAX)
    {
        //if the size is within the range PileSize is set to 
        //the passsed in size
        pileSize = iniSize;
    }
    else
    {
        // if not within range invalid will be displayed
        cout << "Invalid!";
        pileSize = 0;
    }
}

void Nim::setPileSize(int size)
{
    //setting pileSize the same way we did in the 
    //Nim constructor 
    if (size >= PILE_MIN && size <= PILE_MAX)
    {
        pileSize = size;
    }
    else
    {
        cout << "Invalid!";
        pileSize = 0;
    }
}

int Nim::getPileSize() const
{
    //returns the size of the pile at that given time
    return pileSize;
}

void Nim::computer_play(bool smart)
{
    //check is what we will take away from the pileSize in order to 
    //make the answer equal to a power of 2 minus one
    int check = 1;

    //for loop will check if pile size is a power of 2 minus one
    // to ensure whether the computer will play smart or not
     for (int i = 1; pow(2,i)-1 <= pileSize; i++)
     {
         if (pow(2, i) - 1 == pileSize)
        {
             smart = false;
             break;
        }
         check = pow(2, i) - 1;
     }

     //if smart the computer will take away the power of 2 minus one
    if (smart)
    {
       
        int takes = pileSize - check;
        pileSize = pileSize - takes;
        cout << "Computer plays: \nThe computer takes " << takes << " marbles." << endl << endl;
    }
    //when not smart a random integer half or below of pile size will be taken away
    else
    {
        int notSmart = rand() % (pileSize / 2) + 1 ;
        pileSize = pileSize - notSmart;
        cout << "Computer plays: \nThe computer takes " << notSmart << " marbles." << endl << endl;
    }

}


void Nim::print() const
{
    //prints how many marbles are in the pile
    cout << "There are " << pileSize << " marbles" << endl;
    //for loop is used to displau the marbles
    for (int i = 0; i < pileSize; i++)
    {
        cout << setw(10) << " * " << endl;
    }
   
}


