#include "NIMController.h"


NIMController & NIMController::getNIMController()
{
	if (myNIMController == NULL)
	{
		myNIMController = new NIMController();
	}
	return *myNIMController;
}

NIMController::~NIMController()
{
	WSACleanup();
}

NIMController::NIMController()
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		std::cout << "Unable to initialize Windows Socket library." << std::endl;
	}

	s = connectsock("", "", "udp");	// Create a socket  (Don't need to designate a host or port for UDP)


}
