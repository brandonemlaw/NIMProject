#include <iostream>
#include <string>
#include <bitset>

using namespace std;

void makeMove(char*);
void setupBoard();
string getMove();
void makeAIMove();

void main() {

	bool gameover = false;
	string move;
	char * cmove = new char[3];


	setupBoard();

	while (!gameover) {
		move = getMove();
		strcpy_s(cmove, 3, move.c_str());
		makeMove();
	}
}

void setupBoard() {
	int numRows;
	int numStones;

	cout << "how many rows?";
	cin >> numRows;
	bitset<20> board[9];

	for (int i = 0; i < numRows; i++) {
		cout << "how many stones in row " << i << "? ";
		cin >> numStones;
		for (int j = 0; j < numStones; j++) {
			board[i].set(j, true);
		}
	}
}

string getMove() {
	string move;
	string in;
	cout << "row? ";
	cin >> move;
	cout << "number to remove? ";
	cin >> in;
	move += "in";
	return move;
}

void makeMove(char * move) {
	char row = move[0];
	int remove = (atoi(move) % 100);

}

void makeAIMove() {
	bitset<20> board[20];
	int numRows;
	bitset<20> nimSum;
	bool noMove = false;

	for (int i = 0; i < numRows; i++) {
		nimSum ^= board[i];
	}

	for (int i = 0; i < numRows && noMove; i++) {
		bitset<20> target = nimSum ^ board[i];
		if (target < board[i]) {

		}
	}
}