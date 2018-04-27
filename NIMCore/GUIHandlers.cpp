//GUIHandlers.cpp
#include <bitset>
#include "GUIHandlers.h"

NIMController* NIMController::myNIMController = NULL;

	//Is called by the GUI to populate a list of servers
extern "C" __declspec(dllexport) void __stdcall GUI_getServerList(char serverList[])
	{
		//Get the controller
		NIMController& c = NIMController::getNIMController();
		c.setToServer(false);

		//Prepare the variables
		char broadcastAddress[v4AddressSize];
		char myIPAddress[v4AddressSize];
		int status = getIPAddressInfo(myIPAddress, broadcastAddress);
		if (status == 0) {
			//Get the servers info
			int numServers = getServers(c.s, broadcastAddress, NIM_UDPPORT, c.serverArray);

			//Get the information for display
			std::string temp = "";
			for (int i = 0; i < numServers; i++)
			{
				temp += c.serverArray[i].name;
				temp += "\n";
			}
			strcpy_s(serverList, SERVER_LIST_LENGTH, temp.c_str());
		}
		else
		{
			strcpy_s(serverList, SERVER_LIST_LENGTH, "Test\nTest2\nTest3\n");
		}


	}

//Is called by the GUI to accept a client connection
extern "C" __declspec(dllexport) signed int __stdcall GUI_acceptClient()
{
	//Get the controller
	NIMController& c = NIMController::getNIMController();

	c.sendPacketToOpponent(NIM_ACCEPT);
	std::string ack = c.getPacketFromOpponent();
	if (ack == NIM_GREAT)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//Is called by the GUI to wait for a client connection
extern "C" __declspec(dllexport) void __stdcall GUI_getClient(char clientName[])
{
	//Get the controller
	NIMController& c = NIMController::getNIMController();
	c.setToServer(true);

	char buffer[MAX_RECV_BUF];
	std::string host;
	std::string port;
	char responseStr[MAX_SEND_BUF];

	std::string playerName = c.playerName;

	int len = UDP_recv(c.s, buffer, sizeof(buffer) - 1, (char*)host.c_str(), (char*)port.c_str());
	std::cout << timestamp() << " - Received: " << buffer << std::endl;

	bool finished = false;
	while (!finished) {
		if (strcmp(buffer, NIM_QUERY) == 0) {
			// Respond to name query
			strcpy_s(responseStr, NIM_NAME);
			strcat_s(responseStr, playerName.c_str());
			UDP_send(c.s, responseStr, strlen(responseStr) + 1, (char*)host.c_str(), (char*)port.c_str());
			std::cout << timestamp() << " - Sending: " << responseStr << std::endl;

		}
		else if (strncmp(buffer, NIM_CHALLENGE, strlen(NIM_CHALLENGE)) == 0) {
			// Received a challenge  
			char *startOfName = strstr(buffer, NIM_CHALLENGE);
			if (startOfName != NULL) {
				std::cout << std::endl << "You have been challenged by " << startOfName + strlen(NIM_CHALLENGE) << std::endl;
			}

			//Return Client Name
			c.host = host;
			c.port = port;
			strcpy_s(clientName, MAX_RECV_BUF, startOfName + strlen(NIM_CHALLENGE));
			//int winner = playNIM(c.s, (char*)playerName.c_str(), (char*)host.c_str(), (char*)port.c_str(), O_PLAYER);
			finished = true;
		}

		if (!finished) {
			char previousBuffer[MAX_RECV_BUF];		strcpy_s(previousBuffer, buffer);
			std::string previousHost;				previousHost = host;
			std::string previousPort;				previousPort = port;

			// Check for duplicate datagrams (can happen if broadcast enters from multiple ethernet connections)
			bool newDatagram = false;
			int status = wait(c.s, 1, 0);	// We'll wait a second to see if we receive another datagram
			while (!newDatagram && status > 0) {
				len = UDP_recv(c.s, buffer, sizeof(buffer) - 1, (char*)host.c_str(), (char*)port.c_str());
				std::cout << timestamp() << " - Received: " << buffer << std::endl;
				if (strcmp(buffer, previousBuffer) == 0 &&		// If this datagram is identical to previous one, ignore it.
					host == previousHost &&
					port == previousPort) {
					status = wait(c.s, 1, 0);			// Wait another second (still more copies?)
				}
				else {
					newDatagram = true;		// if not identical to previous one, keep it!
				}
			}

			// If we waited one (or more seconds) and received no new datagrams, wait for one now.
			if (!newDatagram) {
				len = UDP_recv(c.s, buffer, sizeof(buffer) - 1, (char*)host.c_str(), (char*)port.c_str());
				std::cout << timestamp() << " - Received: " << buffer << std::endl;
			}
		}
	}
}


	//Is called by the GUI to challenge a certain server
extern "C" __declspec(dllexport) signed int __stdcall GUI_challengeServer(int answer) {
		bool success = false;

		//Get the controller
		NIMController& c = NIMController::getNIMController();

		// Extract the opponent's info from the server[] array
		std::string serverName;
		serverName = c.serverArray[answer].name;	
		c.host = c.serverArray[answer].host;
		c.port = c.serverArray[answer].port;

		// Append playerName to the TicTacToe_CHALLENGE string & send a challenge to host:port
		char buffer[MAX_SEND_BUF];
		strcpy_s(buffer, NIM_CHALLENGE);
		strcat_s(buffer, c.playerName.c_str());
		int len = UDP_send(c.s, buffer, strlen(buffer) + 1, c.host.c_str(), c.port.c_str());

		//Wait for a response from the host
		int challengeAccepted = -1;
		std::string result = c.getPacketFromOpponent();
		//if they accepted
		if (result == NIM_ACCEPT)
		{
			challengeAccepted = 1;

		}
		else
		{
			challengeAccepted = 0;
		}

		

		//if challenge is accepted, send great
		if (challengeAccepted == 1)
		{
			char buffer3[MAX_SEND_BUF];
			strcpy_s(buffer3, NIM_GREAT);
			int len2 = UDP_send(c.s, buffer3, strlen(buffer3) + 1, c.host.c_str(), c.port.c_str());

			//wait for initial board
			c.getInitialBoard();
		}

		return challengeAccepted;
	}

	//Is called by the GUI to set the player name
 __declspec(dllexport) signed int __stdcall GUI_setMyName(char name[]) {
		bool success = false;

		//Get the controller
		NIMController& c = NIMController::getNIMController();

		//Set the name
		c.playerName = name;

		return success;
	}

	//Is called by the GUI to check whose turn it is
extern "C" __declspec(dllexport) signed int __stdcall GUI_isMyTurn() {
		//Get the controller
		NIMController& c = NIMController::getNIMController();
	
		return c.isOurTurn;
	}

	//Is called by the GUI to send a message
extern "C" __declspec(dllexport) signed int __stdcall GUI_sendMessage(char message[]) {
	//Get the controller
	NIMController& c = NIMController::getNIMController();

	std::string m(message);
	m = "C" + m;
	c.sendPacketToOpponent(m);

	return 1;
}

	//Is called by the GUI to check for and get the next new message
	//NULL indicates no new messages
extern "C" __declspec(dllexport) int __stdcall GUI_getMessage(char message[]) {
	
		//Get the controller
		NIMController& c = NIMController::getNIMController();

		//copy message
		strcpy_s(message, MAX_RECV_BUF, c.message.c_str());
		c.message = "";

		return 1;
	}

	//Is called by the GUI to get a copy of the board
extern "C" __declspec(dllexport) BoardReturn __stdcall GUI_getBoard() {
		BoardReturn result;

		//Get the controller
		NIMController& c = NIMController::getNIMController();

		//If it's not our turn, get a move
		if (!c.isOurTurn)
		{
			//get a message
			std::string message = c.getPacketFromOpponent();

			//if the message is a move
			if (isdigit(message[0]))
			{
				int row = (message[0] - 48) - 1; //adjust for string value

				//if the move is valid
				unsigned long stonesToRemove = (message[1] - 48) * 10 + (message[2] - 48);
				if (stonesToRemove <= c.board[row].to_ullong() && stonesToRemove > 0)
				{
					//execute the move
					c.removeRocks(row, stonesToRemove);
				}
				else
				{
					c.forfeit = true;
				}
			}
			else if (message[0] == 'C')
			{
				c.message = message.substr(1);
			}
			else
			{
				c.forfeit = true;
			}
		}

		//return the board
		result.row1 = c.board[0].to_ullong();
		result.row2 = c.board[1].to_ullong();
		result.row3 = c.board[2].to_ullong();
		result.row4 = c.board[3].to_ullong();
		result.row5 = c.board[4].to_ullong();
		result.row6 = c.board[5].to_ullong();
		result.row7 = c.board[6].to_ullong();
		result.row8 = c.board[7].to_ullong();
		result.row9 = c.board[8].to_ullong();

		return result;
	}

extern "C" __declspec(dllexport) BoardReturn __stdcall GUI_getInitialBoard()
{
	BoardReturn result;

	//Get the controller
	NIMController& c = NIMController::getNIMController();

	result.row1 = c.board[0].to_ullong();
	result.row2 = c.board[1].to_ullong();
	result.row3 = c.board[2].to_ullong();
	result.row4 = c.board[3].to_ullong();
	result.row5 = c.board[4].to_ullong();
	result.row6 = c.board[5].to_ullong();
	result.row7 = c.board[6].to_ullong();
	result.row8 = c.board[7].to_ullong();
	result.row9 = c.board[8].to_ullong();

	return result;
}


extern "C" __declspec(dllexport) BoardReturn __stdcall GUI_getAIMoveBoard()
{
	BoardReturn result;

	//Get the controller
	NIMController& c = NIMController::getNIMController();

	//get the message from the AI
	std::string message = c.selectAIMove();

	//send the message
	c.sendPacketToOpponent(message);

	//update the board
	int row = (message[0] - 48) - 1; //adjust for string value

	//if the move is valid
	unsigned long stonesToRemove = (message[1] - 48) * 10 + (message[2] - 48);
	if (stonesToRemove <= c.board[row].to_ullong() && stonesToRemove > 0)
	{
		//execute the move
		c.removeRocks(row, stonesToRemove);
	}



	result.row1 = c.board[0].to_ullong();
	result.row2 = c.board[1].to_ullong();
	result.row3 = c.board[2].to_ullong();
	result.row4 = c.board[3].to_ullong();
	result.row5 = c.board[4].to_ullong();
	result.row6 = c.board[5].to_ullong();
	result.row7 = c.board[6].to_ullong();
	result.row8 = c.board[7].to_ullong();
	result.row9 = c.board[8].to_ullong();

	return result;
}

	//Is called by the GUI to make a move for the current user
extern "C" __declspec(dllexport) bool __stdcall GUI_makeMove(int row, int number) {
		bool success = false;

		//Get the controller
		NIMController& c = NIMController::getNIMController();

		//if it's our turn
		if (c.isOurTurn)
		{
			//convert int correctly
			std::stringstream message;
			message << row + 1;
			message << std::setfill('0') << std::setw(2);
			message << number;
			c.sendPacketToOpponent(message.str());
			c.removeRocks(row, number);
		}

		return success;
	}

extern "C" __declspec(dllexport) signed int __stdcall GUI_gameStatus() {
	//Get the controller
	NIMController& c = NIMController::getNIMController();
	
	if (c.forfeit)
	{
		return 1;
	}

	bool gameOver = true;

	for (int i = 0; i < 8; i++)
	{
		if (c.board[i].to_ullong() != 0)
		{
			gameOver = false;
		}
	}

	if (!gameOver)
	{
		return 0;
	}
	else
	{
		if (!c.isOurTurn)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
}

extern "C" __declspec(dllexport) void  __stdcall GUI_forfeit() 
{
	//Get the controller
	NIMController& c = NIMController::getNIMController();

	c.sendPacketToOpponent("F");
}



