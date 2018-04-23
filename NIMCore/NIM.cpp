#include <iostream>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

void makeMove(char*);
void setupBoard();
string getMove();
char * selectAIMove(bitset<5> board[], int);

int main() {

	bool gameover = false;
	string move;
	char * cmove = new char[3];
	char * aimove = new char[3];

	bitset<5> board[9];
	board[0] = 1;
	board[1] = 4;
	board[2] = 2;
	
	aimove = selectAIMove(board, 3);

	cout << &aimove;
}

void setupBoard() {
	int numRows;
	int numStones;

	cout << "how many rows?";
	cin >> numRows;
	bitset<5> board[9];
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

char* selectAIMove(bitset<5> board[], int numRows) {

	bitset<5> nimSum;
	bool noMove = true;
	int moveAmount;
	char AIMove[4];
	char moveRow[2];
	char cmoveAmount[3] = { '0' };
	char temp[3];

	for (int i = 0; i < numRows; i++) {
		nimSum ^= board[i];
	}

	for (int i = 0; i < numRows && noMove; i++) {
		bitset<5> target = nimSum ^ board[i];
		if (target.to_ulong() < board[i].to_ulong()) {
			moveAmount = board[i].to_ulong() - target.to_ulong();
			noMove = false;
			_itoa_s(i+1,moveRow,10);
		}
	}
	_itoa_s(moveAmount, temp, 10);
	if (moveAmount < 10) {
		strncat_s(cmoveAmount, temp, 1);
	}
	else {
		strcpy_s(cmoveAmount, temp);
	}
	
	strcpy_s(AIMove, moveRow);
	strncat_s(AIMove, cmoveAmount, 2);

	return AIMove;
}