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
extern "C" __declspec(dllexport) bool __stdcall GUI_challengeServer(char serverName[]) {
		bool success = false;
		return success;
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
		return result;
	}

	//Is called by the GUI to make a move for the current user
extern "C" __declspec(dllexport) bool __stdcall GUI_makeMove(int row, int number) {
		bool success = false;
		return success;
	}
