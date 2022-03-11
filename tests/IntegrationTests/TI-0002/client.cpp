#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <random>
#include <chrono>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "engine.h"

#define PORT 8080

static int USR_FCT__RunClient();

static int USR_FCT__RunClient()
{
    int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char *hello = "AB";
    //string hello = "";
	char buffer[1024] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}

    //cout << "[CLIENT]: PATTERN TO SEARCH: ";
    //cin >> hello;
    //scanf("%s", hello);
    //printf("\n%s", hello);
    send(sock , hello , strlen(hello) , 0 );
	//printf("Hello message sent\n");

    //valread = read( sock , buffer, 1024);
	printf("[CLIENT]: Result received:\n%s\n",buffer );
    
}

int main(int argc, char const *argv[])
{
    (void) USR_FCT__RunClient();
	return 0;
}
