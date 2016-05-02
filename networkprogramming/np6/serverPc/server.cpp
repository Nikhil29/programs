#include<bits/stdc++.h>
using namespace std;
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#define MAXLINE 200

int main(){
	int mysockfd, clientSize, clientfd;
	struct sockaddr_in serverAddress, clientAddress;
	char sendData[MAXLINE], fileName[MAXLINE];

	// socket file descriptor at server
	mysockfd=socket(AF_INET, SOCK_STREAM, 0);
	if(mysockfd==-1){
		perror("Socket Socket call failed\n");
		exit(EXIT_FAILURE);
	}

	// create server address
	serverAddress.sin_family=AF_INET;
	serverAddress.sin_port=htons(5000);

	// bind the server address with the server file descriptor
	if(bind(mysockfd, (struct sockaddr *)&serverAddress, (socklen_t)sizeof(serverAddress)) < 0){
		perror("Bind failed");
		return -1;
	}
	
	// listen to the client requests
	if(listen(mysockfd, 3)<0){
		perror("Listen Failed");
		return -1;
	}

	while(1){
		// accept a client connection
		if((clientfd=accept(mysockfd, (struct sockaddr *)&clientAddress, (socklen_t *)&clientSize)) < 0){
			perror("Accept Failed");
			return -1;
		}

		printf("New Client Connected\n");

		// receive the name of file
		if(recv(clientfd, fileName, MAXLINE, 0) < 0){
			perror("Receive failed");
		}
		printf("File requested by client: %s\n", fileName);

		// open the file and send it to client
		FILE *input = fopen(fileName, "r");
		if(input==NULL){
			printf("Requested file not available on server\n");
			strcpy(sendData, "File not available\n");
			send(clientfd, sendData, strlen(sendData)+1, 0);
			return -1;
		}
		else{
			while(fgets(sendData, MAXLINE, input)){
				write(clientfd, sendData, strlen(sendData));
			}
			printf("Requested File %s sent to client.\n",fileName);
		}

		// close the files and connection
		fclose(input);
		close(clientfd);
		printf("Client Disconnected\n\n");
	}
	return 0;
}