#pragma once

//   This function defines as class that serves as the main system
#include "NIM.h"
#include <iostream>
#include <string>
#include <bitset>
#include <WinSock2.h>

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
	std::bitset<9> board;
	std::string getPacketFromOpponent();
	bool getInitialBoard();

private:
	NIMController();
	~NIMController();

};

