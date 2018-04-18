//GUIHandlers.cpp
#include <bitset>

extern "C"
{
	//Is called by the GUI to get a list of servers
	__declspec(dllexport) char* __stdcall GUI_getServerList() {
		//TODO change number of result size
		char result[5000] = "Test\nTest2\nTest3";
		return result;
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
	__declspec(dllexport) char* __stdcall GUI_getMessage() {
		char* result = NULL;
		return result;
	}

	//Is called by the GUI to get a copy of the board
	__declspec(dllexport) unsigned long long* __stdcall GUI_getBoard() {
		unsigned long long result[9];
		return result;
	}

	//Is called by the GUI to make a move for the current user
	__declspec(dllexport) bool __stdcall GUI_makeMove(int row, int number) {
		bool success = false;
		return success;
	}
}