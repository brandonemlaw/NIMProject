#pragma once

//GUI Handlers.h
__declspec(dllexport) char* __stdcall GUI_getServerList();
__declspec(dllexport) bool __stdcall GUI_challengeServer(char* serverName[]);
__declspec(dllexport) bool __stdcall GUI_setMyName(char* name[]);
__declspec(dllexport) bool __stdcall GUI_isMyTurn();
__declspec(dllexport) bool __stdcall GUI_sendMessage(char* message[]);
__declspec(dllexport) char* __stdcall GUI_getMessage();
__declspec(dllexport) unsigned long long* __stdcall GUI_getBoard();
__declspec(dllexport) bool __stdcall GUI_makeMove(int row, int number);