// Compile with: gcc tcpserver.c -o tcpserver
//
// Implement tcp server below.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <signal.h>

#include <sys/types.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>

static int server_socket;

void sigint_handler(int sig){

	write(1,"Terminating through signal handler\n",35);
	close(server_socket);
	exit(0);
}

int main() {

	signal(SIGINT, sigint_handler);
		
	if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
	}

	struct sockaddr_in server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(3001);
	server_address.sin_addr.s_addr = htons(INADDR_ANY);

	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	printf("Server bind()\n");

	while(1) {
		
		listen(server_socket, 27);

		int client_socket;
		client_socket = accept(server_socket, NULL, NULL);
	
		printf("Client has joined: %d\n", client_socket);
		char username[32];
		recv(client_socket, &username, strlen(username), 0);

		char server_message[256] = "You have reached the server";
		
		strcat(server_message, username);		

		send(client_socket, server_message, strlen(server_message), 0);
		
		char command[128];
		while (strcmp(command, "exit") != 0) {
			memset(command, 0, sizeof(command));
			recv(client_socket, &command, strlen(command), 0);
			printf("%s", command);
			if (strcmp(command, "exit") != 0) {
				system(command);
			}
			else {
				break;
			}			

		}

		close(client_socket);
	}

	
	
	return 0;
}
