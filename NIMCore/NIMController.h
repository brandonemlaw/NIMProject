#pragma once

//   This function defines as class that serves as the main system
#include "NIM.h"
#include <iostream>
#include <string>
#include <bitset>
#include <WinSock2.h>
#include <time.h>
#include <random>
#include <sstream>

class NIMController
{
public:

	static NIMController* myNIMController;
	static NIMController& getNIMController();

	SOCKET s;

	std::string playerName;
	ServerStruct serverArray[MAX_SERVERS];

	std::string host;
	std::string port;
	std::string message;
	std::bitset<5> board[9];
	bool forfeit = false;

	bool isOurTurn;


	std::string getPacketFromOpponent();
	bool sendPacketToOpponent(std::string data);

	void removeRocks(int row, int number);

	void initializeBoardHost();
	bool getInitialBoard();
	std::string selectAIMove();

	void setToServer(bool server);


private:
	NIMController();
	~NIMController();

};

