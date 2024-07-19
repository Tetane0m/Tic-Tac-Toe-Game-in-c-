/*
    ### Detailed Explanation of the Code:

    1. **Header and Namespace:**
        - Includes the necessary headers and declares the usage of the `std` namespace.

    2. **Function Prototypes:**
        - Declares the prototypes for functions that will be defined later.

    3. **Main Function:**
        - Initializes the game board and sets the game running flag.
        - Prompts the user to select their character and the computer's character.
        - Calls `drawBoard` to display the initial empty board.
        - Enters the main game loop which continues until the game is over.
        - Handles player and computer moves, drawing the board after each move.
        - Checks for a winner or tie after each move and breaks the loop if the game is over.

    4. **drawBoard Function:**
        - Draws the current state of the board.

    5. **playerMove Function:**
        - Prompts the player to enter their move.
        - Validates the move and updates the board.

    6. **computerMove Function:**
        - Randomly selects a move for the computer.
        - Ensures the move is valid (i.e., the chosen position is empty).

    7. **checkWinner Function:**
        - Checks all possible winning combinations (rows, columns, and diagonals).
        - Prints the result based on whether the player or computer has won.
        - Returns `true` if there is a winner.

    8. **checkTie Function:**
        - Checks if the board is full without a winner.
        - Prints a message if the game is a tie.
        - Returns `true` if there is a tie.

    project link : https://github.com/Tetane0m/Tic-Tac-Toe-Game-in-c-.git .
*/

#include <iostream>
#include <ctime>

using namespace std;

void drawTable(char *bord);
void userMove(char *bord, char playerCharacter);
void computerMove(char *bord, char computerCharacter);
bool checkWinner(char *bord, char playerCharacter);
bool checkTie(char *bord);

int main()
{
    bool running = true;
    char bord[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player;
    char computer;

    cout << "**************************\n";
    cout << "**     X - O /  Game !  **\n";
    cout << "**************************\n \n";

    cout << "** Inter Your character to play with : ";
    cin >> player;
    cout << "** Inter Computer character : ";
    cin >> computer;
    cout << '\n';
    drawTable(bord);

    while (running)
    {
        cout << "*********************\n \n";
        userMove(bord, player);
        drawTable(bord);
        if (checkWinner(bord, player))
        {
            running = false;
            break;
        }
        else if (checkTie(bord))
        {
            running = false;
            break;
        }

        cout << "*********************\n \n";
        computerMove(bord, computer);
        drawTable(bord);
        if (checkWinner(bord, player))
        {
            running = false;
            break;
        }
        else if (checkTie(bord))
        {
            running = false;
            break;
        }
    };

    cout << "Game over !! ";

    return 0;
}

void drawTable(char *bord)
{

    // first row drawing !!
    cout << "   " << "|" << "   " << "|" << "   \n";
    cout << " " << bord[0] << " " << "|" << " " << bord[1] << " " << "|" << " " << bord[2] << " \n";
    cout << "___" << "|" << "___" << "|" << "___\n";

    // second row drawing !!
    cout << "   " << "|" << "   " << "|" << "   \n";
    cout << " " << bord[3] << " " << "|" << " " << bord[4] << " " << "|" << " " << bord[5] << " \n";
    cout << "___" << "|" << "___" << "|" << "___\n";

    // third row drawing !!
    cout << "   " << "|" << "   " << "|" << "   \n";
    cout << " " << bord[6] << " " << "|" << " " << bord[7] << " " << "|" << " " << bord[8] << " \n";
    cout << "   " << "|" << "   " << "|" << "   \n \n";
}
void userMove(char *bord, char playerCharacter)
{
    int step;

    do
    {
        cout << "Inter step at range  ( 1 - 9 ) to mark it : ";
        cin >> step;
        step--;

        if (step > 9 || step < 0)
        {
            cout << "Out Of The Range ! \n";
        }
        else if (bord[step] == ' ')
        {
            bord[step] = playerCharacter;
            break;
        }
        else
        {
            cout << "This place where taken !! !\n";
        }

    } while (!step > 0 || !step, 8);
}
void computerMove(char *bord, char computerCharacter)
{

    int step;
    srand(time(0));

    while (true)
    {
        step = rand() % 9;
        if (bord[step] == ' ')
        {
            bord[step] = computerCharacter;
            break;
        }
    }
}
bool checkWinner(char *bord, char playerCharacter)
{

    // check rows !
    if ((bord[0] != ' ') && (bord[0] == bord[1]) && (bord[1] == bord[2]))
    {
        bord[0] == playerCharacter ? cout << "You Win ! \n" : cout << "You Lose ! \n";
    }
    else if ((bord[3] != ' ') && (bord[3] == bord[4]) && (bord[4] == bord[5]))
    {
        bord[3] == playerCharacter ? cout << "You Win ! \n" : cout << "You Lose ! \n";
    }
    else if ((bord[6] != ' ') && (bord[6] == bord[7]) && (bord[7] == bord[8]))
    {
        bord[6] == playerCharacter ? cout << "You Win ! \n" : cout << "You Lose ! \n";
    }
    // check columns !
    else if ((bord[0] != ' ') && (bord[0] == bord[3]) && (bord[3] == bord[6]))
    {
        bord[0] == playerCharacter ? cout << "You Win ! \n" : cout << "You Lose ! \n";
    }
    else if ((bord[1] != ' ') && (bord[1] == bord[4]) && (bord[4] == bord[7]))
    {
        bord[1] == playerCharacter ? cout << "You Win ! \n" : cout << "You Lose ! \n";
    }
    else if ((bord[2] != ' ') && (bord[2] == bord[5]) && (bord[5] == bord[8]))
    {
        bord[2] == playerCharacter ? cout << "You Win ! \n" : cout << "You Lose ! \n";
    }
    // check diagonals !
    else if ((bord[0] != ' ') && (bord[0] == bord[4]) && (bord[4] == bord[8]))
    {
        bord[0] == playerCharacter ? cout << "You Win ! \n" : cout << "You Lose ! \n";
    }
    else if ((bord[2] != ' ') && (bord[2] == bord[4]) && (bord[4] == bord[6]))
    {
        bord[2] == playerCharacter ? cout << "You Win ! \n" : cout << "You Lose ! \n";
    }
    else
    {
        return false;
    }

    return true;
}
bool checkTie(char *bord)
{
    for (int i = 0; i < 9; i++)
    {
        if (bord[i] == ' ')
        {
            return false;
        }
    }
    cout << "Its Tie !! \n";
    return true;
}
