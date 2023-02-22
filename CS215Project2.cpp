#include "Nim.h"
/*
 *Course: CS215 - 05
 *Project: Project 2
 *Purpose: It demonstrates the game of Nim played between a computer and a computer user.
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
    for (int i = 1; pow(2, i) - 1 <= pileSize; i++)
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
        int notSmart = rand() % (pileSize / 2) + 1;
        pileSize = pileSize - notSmart;
        cout << "Computer plays: \nThe computer takes " << notSmart << " marbles." << endl << endl;
    }


}



void Nim::player_play()
{
    //integer variable to store users choice
    int userPlay;

    //boolean variable for do while loop
    bool teller = true;

    //do while to continuously take input until user inputs a valid input
    do
    {
        //output statements to match sample output given
        cout << "Your play... you may take 1 to " << (pileSize / 2) << endl;
        cout << "You take: ";
        cin >> userPlay;

        //checks to see if the user has inputted an integer or not
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid! Please try again... " << endl;

        }
        //checks to see if the integer inputted by user is a valid move in Nim
        else if (userPlay > pileSize / 2 || userPlay < 1)
        {
            //checks to see if the user has inputted an integer or not
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Oops, you picked too many or not enough. " << endl;
            cout << "Please try again... " << endl;
        }
        //when integer is a valid move the loop will end in this else statement
        else
        {
            cout << "You will take " << userPlay << " marbles" << endl;
            pileSize = pileSize - userPlay;
            teller = false;
        }

    } while (teller);
    cin.clear();
    cin.ignore(256, '\n');

}

void Nim::print() const
{
    //prints how many marbles are in the pile
    cout << "\nThere are " << pileSize << " marbles in the pile" << endl;
    //for loop is used to displau the marbles
    for (int i = 0; i < pileSize; i++)
    {
        cout << setw(10) << " * " << endl;
    }

}

