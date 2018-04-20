//GUIHandlers.cpp
#include <bitset>
#include "GUIHandlers.h"

	
	//Is called by the GUI to populate a list of servers
extern "C" __declspec(dllexport) void __stdcall GUI_getServerList(char serverList[], int length)
	{
		char test[5000] = "Test1\nTest2\nBilly\nBob\nJoe\n";
		strcpy_s(serverList, 5000, test);
	}

	//Is called by the GUI to challenge a certain server
extern "C" __declspec(dllexport) bool __stdcall GUI_challengeServer(char serverName[]) {
		bool success = false;
		return success;
	}

	//Is called by the GUI to set the player name
extern "C" __declspec(dllexport) bool __stdcall GUI_setMyName(char* name[]) {
		bool success = false;
		return success;
	}

	//Is called by the GUI to check whose turn it is
extern "C" __declspec(dllexport) bool __stdcall GUI_isMyTurn() {
		bool result = false;
		return result;
	}

	//Is called by the GUI to send a message
extern "C" __declspec(dllexport) bool __stdcall GUI_sendMessage(char* message[]) {
		bool result = false;
		return result;
	}

	//Is called by the GUI to check for and get the next new message
	//NULL indicates no new messages
extern "C" __declspec(dllexport) bool __stdcall GUI_getMessage(char* message[], int length) {
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
