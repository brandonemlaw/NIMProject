#include "NIMController.h"


void NIMController::setToServer(bool server)
{
	if (server)
	{
		closesocket(s);
		s = passivesock(NIM_UDPPORT, "udp");
	}
	else
	{
		closesocket(s);
		s = connectsock("", "", "udp");
	}


}


NIMController & NIMController::getNIMController()
{
	if (myNIMController == NULL)
	{
		myNIMController = new NIMController();
	}
	return *myNIMController;
}



NIMController::~NIMController()
{
	WSACleanup();
}

bool NIMController::sendPacketToOpponent(std::string data)
{
	char buffer[MAX_SEND_BUF];
	strcpy_s(buffer, data.c_str());
	int len = UDP_send(s, buffer, strlen(buffer) + 1, host.c_str(), port.c_str());
	
	if (len > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void NIMController::removeRocks(int row, int number)
{
	unsigned long long newNumber = board[row].to_ullong() - number;
	board[row] = std::bitset<5>(newNumber);

	isOurTurn = !isOurTurn;
}

std::string NIMController::getPacketFromOpponent()
{
	int status = wait(s, WAIT_TIME, 0);
	while (status > 0) {

		char buffer[MAX_RECV_BUF];
		char remoteHost[v4AddressSize] = "";
		char remotePort[portNumberSize] = "";
		int recieved = UDP_recv(s, buffer, MAX_RECV_BUF - 1, remoteHost, remotePort);

		if (recieved > 0)
		{
			if (strcmp(remoteHost, host.c_str()) == 0 && strcmp(remotePort, port.c_str()) == 0)
			{
				return std::string(buffer);
			}
		}

		status = wait(s, WAIT_TIME, 0);
		recieved = UDP_recv(s, buffer, MAX_RECV_BUF - 1, remoteHost, remotePort);
	}
	return "";

}



bool NIMController::getInitialBoard()
{
	std::string result = getPacketFromOpponent();

	int numberOfPiles = (int)result[0] - 48;
	if (numberOfPiles > 9 || numberOfPiles < 1)
	{
		return false;
	}

	//for each of the piles
	for (int i = 1; i <= numberOfPiles * 2; i+=2)
	{
		//get and set the number of stones
		unsigned long long numberOfStones = (result[i] - 48) * 10 + (result[i + 1] - 48);
		board[i / 2] = std::bitset<5>(numberOfStones);
	}

	//set to our turn
	isOurTurn = true;

	return true;
}



NIMController::NIMController()
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		std::cout << "Unable to initialize Windows Socket library." << std::endl;
	}

	//create a client socket
	s = connectsock("", "", "udp");	// Create a socket  (Don't need to designate a host or port for UDP)
	playerName = "TheBigBadWolf";

}


std::string NIMController::selectAIMove() 
{
	using std::bitset;
	int numRows = 0;
	for (int i = 1; i < 9; i++)
	{
		if (board[i].to_ullong() != 0)
		{
			numRows = i;
		}
	}

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
			_itoa_s(i + 1, moveRow, 10);
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
	std::string result(AIMove);

	return result;
}
