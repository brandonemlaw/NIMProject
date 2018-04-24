#include "NIMController.h"


NIMController & NIMController::getNIMController()
{
	if (myNIMController == NULL)
	{
		myNIMController = new NIMController();
	}
	return *myNIMController;
}

NIMController::NIMController()
{
	s = connectsock("", "", "udp");	// Create a socket  (Don't need to designate a host or port for UDP)
}
