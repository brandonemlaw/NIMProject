//GUIHandlers.cpp
#include <bitset>
#include "GUIHandlers.h"

NIMController* NIMController::myNIMController = NULL;

	//Is called by the GUI to populate a list of servers
extern "C" __declspec(dllexport) void __stdcall GUI_getServerList(char serverList[])
	{
	//TODO: NOTICE::::: socket cannot be created!!!????
	
		//Define the result
		//char result[SERVER_LIST_LENGTH] = "";

		//Get the controller
		NIMController& c = NIMController::getNIMController();

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

	//Is called by the GUI to challenge a certain server
extern "C" __declspec(dllexport) bool __stdcall GUI_challengeServer(int answer) {
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
 __declspec(dllexport) bool __stdcall GUI_setMyName(char* name[]) {
		bool success = false;
		return success;
	}

	//Is called by the GUI to check whose turn it is
extern "C" __declspec(dllexport) bool __stdcall GUI_isMyTurn() {
		bool result = false;
		return result;
	}

	//Is called by the GUI to send a message
__declspec(dllexport) bool __stdcall GUI_sendMessage(char* message[]) {
		bool result = false;
		return result;
	}

	//Is called by the GUI to check for and get the next new message
	//NULL indicates no new messages
__declspec(dllexport) bool __stdcall GUI_getMessage(char* message[], int length) {
		bool success = false;
		return success;
	}

	//Is called by the GUI to get a copy of the board
extern "C" __declspec(dllexport) BoardReturn __stdcall GUI_getBoard() {
		BoardReturn result;

//		std::cout << "Waiting for your opponent's move..." << std::endl << std::endl;
//
//		//Get the controller
//		NIMController& c = NIMController::getNIMController();
//
//
//		//Get opponent's move & display board
//		int status = wait(c.s, WAIT_TIME, 0);
//		if (status > 0) {
//			/****
//			Task 2: (i) Insert code inside this IF statement that will accept a null-terminated C-string from your
//			opponent that represents their move.  Convert that string to an integer and then
//			(ii) call a function that will update the game board (see above) using your opponent's move, and
//			(iii) call a function that will display the updated board on your screen.
//			****/
//			//i - get C-string and convert to integer
//			char moveString[MAX_RECV_BUF + 2];
//			char myRemoteIP[v4AddressSize + 2];
//			strcpy_s(myRemoteIP, v4AddressSize, c.host.c_str());
//
//			char myRemotePort[portNumberSize];
//			strcpy_s(myRemotePort, portNumberSize, c.port.c_str());
//
//			int bytesRecieved = UDP_recv(c.s, moveString, MAX_SEND_BUF, myRemoteIP, myRemotePort);
//			int move = atoi(moveString);
//
//
///*
//			//ii - update the game board with opponent move
//			int remotePlayer = O_PLAYER;
//			if (localPlayer == O_PLAYER)
//			{
//				remotePlayer = X_PLAYER;
//			}
//			updateBoard(board, move, remotePlayer);
//
//			//iii - display the board
//			displayBoard(board);
//
//
//		}
//		else {
//			winner = ABORT;
//		}*/

		return result;
	}

extern "C" __declspec(dllexport) BoardReturn __stdcall GUI_getInitialBoard()
{
	BoardReturn result;

	//Get the controller
	NIMController& c = NIMController::getNIMController();

	result.row1 = c.board[0].to_ullong;
	result.row2 = c.board[1].to_ullong;
	result.row3 = c.board[2].to_ullong;
	result.row4 = c.board[3].to_ullong;
	result.row5 = c.board[4].to_ullong;
	result.row6 = c.board[5].to_ullong;
	result.row7 = c.board[6].to_ullong;
	result.row8 = c.board[7].to_ullong;
	result.row9 = c.board[8].to_ullong;

	return result;
}

	//Is called by the GUI to make a move for the current user
extern "C" __declspec(dllexport) bool __stdcall GUI_makeMove(int row, int number) {
		bool success = false;
		return success;
	}
