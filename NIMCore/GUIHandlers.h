#pragma once

//GUI Handlers.h

struct BoardReturn
{
	unsigned long long row1;
	unsigned long long row2;
	unsigned long long row3;
	unsigned long long row4;
	unsigned long long row5;
	unsigned long long row6;
	unsigned long long row7;
	unsigned long long row8;
	unsigned long long row9;
};


__declspec(dllexport) void __stdcall GUI_getServerList(char* serverList[], int length);
__declspec(dllexport) bool __stdcall GUI_challengeServer(char* serverName[]);
__declspec(dllexport) bool __stdcall GUI_setMyName(char* name[]);
__declspec(dllexport) bool __stdcall GUI_isMyTurn();
__declspec(dllexport) bool __stdcall GUI_sendMessage(char* message[]);
__declspec(dllexport) bool __stdcall GUI_getMessage(char* message[], int length);
__declspec(dllexport) BoardReturn __stdcall GUI_getBoard();
__declspec(dllexport) bool __stdcall GUI_makeMove(int row, int number);