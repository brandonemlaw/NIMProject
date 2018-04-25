#pragma once

//GUI Handlers.h

#include "NIMController.h"

const int SERVER_LIST_LENGTH = 10000;

struct BoardReturn
{
	unsigned long long row1 = 0;
	unsigned long long row2 = 0;
	unsigned long long row3 = 0;
	unsigned long long row4 = 0;
	unsigned long long row5 = 0;
	unsigned long long row6 = 0;
	unsigned long long row7 = 0;
	unsigned long long row8 = 0;
	unsigned long long row9 = 0;
};


extern "C" __declspec(dllexport) void __stdcall GUI_getServerList(char serverList[]);
extern "C" __declspec(dllexport) bool __stdcall GUI_challengeServer(int answer);
extern "C" __declspec(dllexport) bool __stdcall GUI_setMyName(char name[]);
extern "C" __declspec(dllexport) bool __stdcall GUI_isMyTurn();
extern "C" __declspec(dllexport) bool __stdcall GUI_sendMessage(char message[]);
extern "C" __declspec(dllexport) bool __stdcall GUI_getMessage(char message[], int length);
extern "C" __declspec(dllexport) BoardReturn __stdcall GUI_getBoard();
extern "C" __declspec(dllexport) BoardReturn __stdcall GUI_getInitialBoard();
extern "C" __declspec(dllexport) bool __stdcall GUI_makeMove(int row, int number);