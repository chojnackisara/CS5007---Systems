// Note: I recommend implementing the tcpserver.c first.
//
// Compile with: gcc tcpclient.c -o tcpclient
//
// Implement tcp client below.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PROMPT "client>"
#define BUFFERSIZE 128

int main() {

	int client_socket;

	if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
	}

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(3001);
	server_address.sin_addr.s_addr = htons(INADDR_ANY);

	int connection_status;

	if ((connection_status = connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address))) < 0) {
		printf("%d Connection unsuccessful\n", connection_status);
		close(client_socket);
		exit(0);
	}
	else {
		printf("Connected successfully\n");
	}

	char name[32];
	printf("What is your username?\n");
	fgets(name, 32, stdin);

	//Send username to server
	send(client_socket, &name, strlen(name), 0);

	char server_response[256];
	recv(client_socket, &server_response, sizeof(server_response), 0);
	
	printf("The server sent the data: %s\n", server_response);

	char clientCommand[BUFFERSIZE];

	//Prompt user the user for commands and send them to server until client enteres 'exit'
	while(1) {

		printf(PROMPT);
		fgets(clientCommand, BUFFERSIZE, stdin);	
		if (strcmp(clientCommand, "exit\n") == 0) {
			close(client_socket);
			return 0;
		}
		send(client_socket, &clientCommand, strlen(clientCommand), 0);
	}
	


}
