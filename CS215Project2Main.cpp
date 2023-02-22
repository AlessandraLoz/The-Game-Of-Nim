#include "Nim.h"
/*
 *Course: CS215 - 05
 *Project: Project 2
 *Purpose: It demonstrates the game of Nim played between a computer and a computer user.
 *Author:  Alessandra Lozano
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Nim.h"

using namespace std;


int main()
{
    int seed = static_cast<int>(time(0));
    srand(seed);

    // Generate the initial size of pile (of marbles)
    // at the range of [PILE_MIN, PILE_MAX]
    // for testing purpose only: we set the initial size of pile to a constant PILE_MAX
    int pileSize = rand() % PILE_MAX/2 + PILE_MIN;

    // create a Nim object with initial pile size = pileSize
    Nim NimGame(pileSize);

    //turning int into a boolean variable that is random every time
    int smart = rand() % 2;

    cout << "**********************************************************************" << endl;
    cout << "*                  The game of Nim                                   *" << endl;
    cout << "*       Players alternate taking at least one but at                 *" << endl;
    cout << "*       most half of the marbles in the pile.                        *" << endl;
    cout << "*       The player who takes the last marble loses.                  *" << endl;
    cout << "*       It is written by Yi Pike                                     *" << endl;
    cout << "*       I hope you beat the computer:)                               *" << endl;
    cout << "*       No matter what, have a great day.                            *" << endl;
    cout << "**********************************************************************" << endl;

    //turning int into a boolean variable that is random every time
    int ALESSANDRA_turn = rand() % 2;

    if (!ALESSANDRA_turn)
    {
        cout << "The computer will play first " << endl;
    }
    else
    {
        cout << "You will play first " << endl;
    }
    if (smart)
    {
        cout << "The computer will play smart " << endl;
    }
    else
    {
        cout << "The computer will not play smart " << endl;
    }

    while (NimGame.getPileSize() > 1)
    {
        NimGame.print();
        if (ALESSANDRA_turn) //it is PIKE's turn to play
        {
            NimGame.player_play();
        }
        else   // it is SUPER's turn to play
        {
            NimGame.computer_play(smart);
        }

        ALESSANDRA_turn = !ALESSANDRA_turn;
    }

    //check the which one has to take the last marble to lose the game
    if (ALESSANDRA_turn)  // PIKE's turn (for this program, this will never happen as long as PIKE is the first player!
    {
        cout << "You must take the last marble. You lose!" << endl;
    }
    else   // SUPER's turn
    {
        cout << "Computer must take the last marble. You win!" << endl;
    }
    return 0;
}