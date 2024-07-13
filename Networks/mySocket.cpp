#include <iostream>
#include <winsock.h>
#include <windows.h>

typedef struct WSAData {
  WORD           wVersion;
  WORD           wHighVersion;
#if ...
  unsigned short iMaxSockets;
#if ...
  unsigned short iMaxUdpDg;
#if ...
  char           *lpVendorInfo;
#if ...
  char           szDescription[WSADESCRIPTION_LEN + 1];
#if ...
  char           szSystemStatus[WSASYS_STATUS_LEN + 1];
#else
  char           szDescription[WSADESCRIPTION_LEN + 1];
#endif
#else
  char           szSystemStatus[WSASYS_STATUS_LEN + 1];
#endif
#else
  unsigned short iMaxSockets;
#endif
#else
  unsigned short iMaxUdpDg;
#endif
#else
  char           *lpVendorInfo;
#endif
} WSADATA;

WSADATA wsaData;
int wsaerr;

WORD wVersionRequested = MAKEWORD(2,2);
wsaerr = WSAStartup(wVersionRequested, &wsaData);


int main(){
    if (wsaData != 0){
        std::cout << "The Winsock dll not found!\n";
        return 0;
    }
    return 0;
}