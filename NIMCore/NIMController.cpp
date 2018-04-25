#include "NIMController.h"


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

std::string NIMController::getPacketFromOpponent()
{
	int status = wait(s, WAIT_TIME, 0);
	if (status > 0) {

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
	}
	else
	{
		return "";
	}

}

bool NIMController::getInitialBoard()
{
	std::string result = getPacketFromOpponent();

	int numberOfPiles = (int)result[0] - 48;
	if (numberOfPiles > 9 || numberOfPiles < 1)
	{
		return false;
	}

	for (int i = 1; i <= numberOfPiles * 2 && i <= 9; i+=2)
	{
		unsigned long long value = (result[i] - 48) * 10 + (result[i + 1] - 48);
		board[i / 2] ^= value;
	}

	return true;
}



NIMController::NIMController()
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		std::cout << "Unable to initialize Windows Socket library." << std::endl;
	}

	s = connectsock("", "", "udp");	// Create a socket  (Don't need to designate a host or port for UDP)
	playerName = "TheBigBadWolf";

}
