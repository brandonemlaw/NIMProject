#include "NIMController.h"

NIMController::NIMController()
{
	s = connectsock("", "", "udp");	// Create a socket  (Don't need to designate a host or port for UDP)
}
