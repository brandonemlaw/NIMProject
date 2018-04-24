#pragma once

//   This function defines as class that serves as the main system
#include "NIM.h"
#include <iostream>
#include <string>
#include <WinSock2.h>

class NIMController
{
public:

	static NIMController* myNIMController;
	static NIMController& getNIMController();

	SOCKET s;
	ServerStruct serverArray[MAX_SERVERS];


private:
	NIMController();


};

