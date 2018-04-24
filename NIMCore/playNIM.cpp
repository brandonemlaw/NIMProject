// playNIM.cpp
// This set of functions are used to actually play the game.
// Play starts with the function: playNIM() which is defined below

#include "NIM.h"
#include <WinSock2.h>
#include <iostream>
#include <string>
#include <time.h>
#include <random>

using namespace std;

void initializeBoardHost(char board[])
{
	srand(time(NULL));
	int numRows, numRocks, index;
	index = 0;
	numRows = (rand() % 7) + 3;
	for (int i = 0; i < numRows; i++)
	{
		numRocks = (rand() % 20) + 1;
		for (int j = 0; j < numRocks; j++)
		{
			board[index] = '*';
			index++;
		}
		board[index] = '\n';
		index++;
	}
}

void initializeBoardClient(char board[], string boardFromClient)
{
	int numRows, numRocks, index;
	string buffer;
	index = 0;
	numRows = boardFromClient[0] - '0';
	for (int i = 0; i < numRows; i++)
	{
		buffer = boardFromClient[i * 2 + 1] + boardFromClient[i * 2 + 2];
		numRocks = atoi(buffer.c_str());
		for (int j = 0; j < numRocks; j++)
		{
			board[index] = '*';
			index++;
		}
		board[index] = '\n';
		index++;
	}
}

void updateBoard(char board[], string move, int Player, string &boardFromClient)
{
	int boardRows, boardRocks, moveRow, moveRocks;
	boardRows = boardFromClient[0] - '0';
	moveRow = move[0] - '0';
	string buffer;
	if (moveRow > 0 || moveRow < boardRows)
	{
		buffer = boardFromClient[moveRow * 2 + 1] + boardFromClient[moveRow * 2 + 2];
		boardRocks = atoi(buffer.c_str());
		buffer = move[2] + move[3];
		moveRocks = atoi(buffer.c_str());
		if (moveRocks > 0 || moveRocks < boardRocks)
		{

		}
		else
		{
			cout << "Illegal move" << endl;
		}
	}
	else
		std::cout << "Problem with updateBoard function!" << std::endl;
}

void displayBoard(char board[], string &boardFromClient)
{
	int numRows, j;
	numRows = boardFromClient[0] - '0';
	for (int i = 1; i <= numRows; i++)
	{
		cout << "Row " << i << ":\t";
		//TODO: Compiler error: using unitialized variable j????
		//while (board[j] != '\n')
		{
			cout << '*';
			//j++;
		}
	}
}

int check4Win(char board[], string &boardFromClient)
{
	int winner = 0;
	int numRows;
	numRows = boardFromClient[0] - '0';

	for (int i = 1; i <= numRows; i++)
	{
		if (boardFromClient[i] != '\n')
		{
			winner = 0;
			break;
		}
		else
		{
			winner = 1;
		}
	}

	return winner;
}

string getMove(char board[], int Player)
{
	string move, row, numRocks;
	int rockNumber;
	char move_str[80];

	std::cout << "What row do you want to remove your rock(s) from?";
	cin >> row;
	cout << "How many rocks would you like to remove from the row?";
	cin >> rockNumber;
	if (rockNumber < 10)
	{
		//_itoa_s(rockNumber, numRocks, numRocks.length(), 10);
		numRocks = "0";
		numRocks += (rockNumber + '0');
	}
	move = row + numRocks;

	return move;
}

int playNIM(SOCKET s, std::string serverName, std::string remoteIP, std::string remotePort, int localPlayer)
{
	// This function plays the game and returns the value: winner.  This value 
	// will be one of the following values: noWinner, xWinner, oWinner, TIE, ABORT
	int winner = noWinner;
	char board[10];
	int opponent;
	int move;
	bool myMove;

	if (localPlayer == X_PLAYER) {
		std::cout << "Playing as X" << std::endl;
		opponent = O_PLAYER;
		myMove = true;
	}
	else {
		std::cout << "Playing as O" << std::endl;
		opponent = X_PLAYER;
		myMove = false;
	}

	//initializeBoard(board);
	//TODO: displayBoard needs 2 parameters, not 1
	//displayBoard(board);

	while (winner == noWinner) {
		if (myMove) {
			// Get my move & display board

			//TODO: cannot save string directly into int. That is a compiler error.
			//move = getMove(board, localPlayer);
			std::cout << "Board after your move:" << std::endl;
			//TODO: cannot put int directly into update board. This is also causing a compiler error.
			//updateBoard(board, move, localPlayer);
			//TODO: displayBoard needs 2 parameters, not 1
			//displayBoard(board);

			// Send move to opponent
			/****
			Task 1: "move" is an integer that was assigned a value (from 1 to 9) in the previous code segment.
			Add code here to convert "move" to a null-terminated C-string and send it to your opponent at remoteIP using remotePort.
			****/


		}
		else {
			std::cout << "Waiting for your opponent's move..." << std::endl << std::endl;
			//Get opponent's move & display board
			int status = wait(s, WAIT_TIME, 0);
			if (status > 0) {
				/****
				Task 2: (i) Insert code inside this IF statement that will accept a null-terminated C-string from your
				opponent that represents their move.  Convert that string to an integer and then
				(ii) call a function that will update the game board (see above) using your opponent's move, and
				(iii) call a function that will display the updated board on your screen.
				****/
			}
			else {
				winner = ABORT;
			}
		}
		myMove = !myMove;

		if (winner == ABORT) {
			std::cout << timestamp() << " - No response from opponent.  Aborting the game..." << std::endl;
		}
		else {
			//TODO: displayBoard needs 2 parameters, not 1
			//winner = check4Win(board);
		}

		if (winner == localPlayer)
			std::cout << "You WIN!" << std::endl;
		else if (winner == TIE)
			std::cout << "It's a tie." << std::endl;
		else if (winner == opponent)
			std::cout << "I'm sorry.  You lost" << std::endl;
	}

	return winner;
}
