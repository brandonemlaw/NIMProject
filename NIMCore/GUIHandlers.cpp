//GUIHandlers.cpp
#include <bitset>
#include "GUIHandlers.h"
extern "C"
{
	
	//Is called by the GUI to populate a list of servers
	__declspec(dllexport) void __stdcall GUI_getServerList(char* serverList[], int length)
	{
		5;
	}

	//Is called by the GUI to challenge a certain server
	__declspec(dllexport) bool __stdcall GUI_challengeServer(char* serverName[]) {
		bool success = false;
		return success;
	}

	//Is called by the GUI to set the player name
	__declspec(dllexport) bool __stdcall GUI_setMyName(char* name[]) {
		bool success = false;
		return success;
	}

	//Is called by the GUI to check whose turn it is
	__declspec(dllexport) bool __stdcall GUI_isMyTurn() {
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
	__declspec(dllexport) BoardReturn __stdcall GUI_getBoard() {
		BoardReturn result;
		return result;
	}

	//Is called by the GUI to make a move for the current user
	__declspec(dllexport) bool __stdcall GUI_makeMove(int row, int number) {
		bool success = false;
		return success;
	}
}