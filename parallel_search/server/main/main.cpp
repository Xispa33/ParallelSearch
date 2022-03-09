#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include "search_engine.h"

#define PORT 8080

static void USR_FCT__RunServer()
{
    int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	char *hello = "Hello from server";
	
	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	
	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR , &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );
	
	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&address,
								sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
					(socklen_t*)&addrlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}

    /* MODIFY HERE */
    BasicSearchEngine search_engine;

    valread = read(new_socket, buffer, 1024);
    printf("[SERVER]: Pattern received = %s\n", buffer);
    search_engine.SEARCH_ENGINE__Search((string) buffer);
    //send(new_socket , hello , strlen(hello) , 0 );
    printf("[SERVER]: Search results sent\n");
}


int main()
{
    USR_FCT__RunServer();
    //BasicSearchEngine search_engine;
    //search_engine.SEARCH_ENGINE__Search("AB");
    /*
	//WordsList word_list;
    SearchEngine search_engine;
    search_engine.SEARCH_ENGINE__Search("AB");
	//cout << word_list.toto << endl;
    */
    std::cout << "1 + 1 = 2" << std::endl;
    return 0;
}