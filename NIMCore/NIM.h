// TicTacToe.h
//
// This header file establishes some constants that should be used in the TicTacToe project for COMP 311

#include <WinSock2.h>
#include <string>

static char NIM_UDPPORT[] = "29333";			// Port number used by TicTacToe servers

const char NIM_QUERY[10] = "Who?";
const char NIM_NAME[10] = "Name=";
const char NIM_CHALLENGE[10] = "Player=";
const char NIM_ACCEPT[10] = "YES";
const char NIM_GREAT[10] = "GREAT!";

const int MAX_WAIT = 100;


const int v4AddressSize = 16;
const int portNumberSize = 10;
const int MAX_INTERFACES = 20;
const int WAIT_TIME = 60;
const int MAX_SEND_BUF = 2048;
const int MAX_RECV_BUF = 2048;
const int MAX_SERVERS = 100;
const int X_PLAYER = 1;
const int O_PLAYER = 2;
const int ABORT = -1;
const int noWinner = 0;
const int xWinner = 1;
const int oWinner = 2;
const int TIE = 3;

static char board[10];

struct ServerStruct {
	std::string name;
	std::string host;
	std::string port;
};

SOCKET connectsock(const char*, const char*, const char*);
SOCKET passivesock(const char*, const char*);
int UDP_recv(SOCKET, char*, int, char*, char*);
int UDP_send(SOCKET, char*, int, const char*, const char*);
int wait(SOCKET, int, int);
char* timestamp();
int getServers(SOCKET, char*, char*, ServerStruct[]);
int playNIM(SOCKET, std::string, std::string, std::string, int);
int serverMain(int, char *argv[], std::string);
int clientMain(int, char *argv[], std::string);
int getIPAddressInfo(char*, char*);
