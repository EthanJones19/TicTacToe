#include <iostream>

//Creates the map in 2 dimensions
const char* MAP[3][3];

//Creates blank spaces
const char* BLANK = "[ _ ]";

//Creates player's icons
const char* PLAYERONE = "[ X ]";
const char* PLAYERTWO = "[ O ]";

//Creates input
int INPUT;

//Creates if one of the players win
bool player1win = false;
bool player2win = false;

//Creates board that is full
bool boardfull = false;

//Creates player's turn
bool playerturn = true;

//Creates a temp check
bool tempcheck = false;

//Starts the program
void start()
{
    //Creates a map grid with blanks when started
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            MAP[x][y] = BLANK;
        }
    }
}

//check all vertical win conditions
void verticalWin()
{
    //first row
    if (MAP[0][0] == MAP[0][1] && MAP[0][1] == MAP[0][2])
    {
        if (MAP[0][0] == PLAYERONE)
        {
            player1win = true;
        }
        if (MAP[0][0] == PLAYERTWO)
        {
            player2win = true;
        }
    }
    //second row
    else if ((MAP[1][0] == MAP[1][1] && MAP[1][1] == MAP[1][2]))
    {
        if (MAP[1][0] == PLAYERONE)
        {
            player1win = true;
        }
        if (MAP[1][0] == PLAYERTWO)
        {
            player2win = true;
        }
    }
    //third row
    else if (MAP[2][0] == MAP[2][1] && MAP[2][1] == MAP[2][2])
    {
        if (MAP[2][0] == PLAYERONE)
        {
            player1win = true;
        }
        if (MAP[2][0] == PLAYERTWO)
        {
            player2win = true;
        }
    }

}

//check all horizontal win conditions
void horizontalWIN()
{

    //first column
    if (MAP[0][0] == MAP[1][0] && MAP[1][0] == MAP[2][0])
    {
        if (MAP[0][0] == PLAYERONE)
        {
            player1win = true;
        }
        if (MAP[0][0] == PLAYERTWO)
        {
            player2win = true;
        }
    }
    //secound column
    else if ((MAP[0][1] == MAP[1][1] && MAP[1][1] == MAP[2][1]))
    {
        if (MAP[0][1] == PLAYERONE)
        {
            player1win = true;
        }
        if (MAP[0][1] == PLAYERTWO)
        {
            player2win = true;
        }
    }
    //third column
    else if (MAP[0][2] == MAP[1][2] && MAP[1][2] == MAP[2][2])
    {
        if (MAP[0][2] == PLAYERONE)
        {
            player1win = true;
        }
        if (MAP[0][2] == PLAYERTWO)
        {
            player2win = true;
        }
    }
}

//check all diagonal win conditions
void diagonalWin()
{
    //starting in 00
    if (MAP[0][0] == MAP[1][1] && MAP[1][1] == MAP[2][2])
    {
        if (MAP[0][0] == PLAYERONE)
        {
            player1win = true;
        }
        if (MAP[0][0] == PLAYERTWO)
        {
            player2win = true;
        }
    }
    //starting in 02
    else if ((MAP[2][0] == MAP[1][1] && MAP[1][1] == MAP[0][2]))
    {
        if (MAP[2][0] == PLAYERONE)
        {
            player1win = true;
        }
        if (MAP[2][0] == PLAYERTWO)
        {
            player2win = true;
        }
    }
}

//Sets up a scan to check if the map is full
void fullCheck()
{
    tempcheck = false;
    //Scans the Map to look for blank tiles
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++) {
            //If a blank tile is found set check to true
            if (MAP[y][x] == BLANK)
            {
                tempcheck = true;
                break;
            }
            else
            {
                tempcheck = false;
            }
        }
        //Break Loop if blank tile is found
        if (tempcheck)
            break;
    }
    //Set board to true
    if (!tempcheck)
    {
        boardfull = true;
    }
}

//Prints the board
void printBoard()
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            std::cout << x << "," << y << MAP[x][y];
        }

        std::cout << "\n";
    }
}

//Checks the player's turn
void playerTurn()
{
    int ycord;
    int xcord;

    if (playerturn == true)
    {
        while (playerturn == true)
        {
            //Collects Y cord
            std::cout << "Player Ones turn please enter x Cord  " << std::endl;
            std::cin >> xcord;
            //Collects X cord
            std::cout << "Player Ones turn please enter y Cord  " << std::endl;
            std::cin >> ycord;
            //Check if space is avaliable and take turn if blank
            if (MAP[xcord][ycord] != PLAYERONE && MAP[xcord][ycord] != PLAYERTWO)
            {
                MAP[xcord][ycord] = PLAYERONE;
                playerturn = false;
            }
            //Space is occupied end turn
            else
            {
                std::cout << "Unavaliable space" << std::endl;
                system("pause");
            }
            //Switch to player 2s turn

        }

    }
    else
    {
        while (playerturn == false)
        {
            //Collects Y cord
            std::cout << "Player Twos turn please enter x Cord  " << std::endl;
            std::cin >> xcord;
            //Collects X cord
            std::cout << "Player Twos turn please enter y Cord  " << std::endl;
            std::cin >> ycord;
            //Check if space is avaliable and take turn if blank
            if (MAP[xcord][ycord] != PLAYERTWO && MAP[xcord][ycord] != PLAYERONE)
            {
                MAP[xcord][ycord] = PLAYERTWO;
                playerturn = true;
            }
            //Space is occupied end turn
            else
            {
                std::cout << "Unavaliable space" << std::endl;
                system("pause");
            }
            //Switch to player 2s turn

        }
    }
}

//Updates the program
void update()
{
    while (!player1win && !player2win && !boardfull)
    {
        printBoard();
        playerTurn();
        verticalWin();
        horizontalWIN();
        diagonalWin();
        fullCheck();
    }
    //Display end of game messages
    if (player1win)
    {
        std::cout << "player 1 won";
    }
    else if (player2win)
    {

        std::cout << "player 2 won";

    }
    else
    {
        std::cout << "board is full draw";
    }

}

//Main program
int main()
{
    start();
    update();
}