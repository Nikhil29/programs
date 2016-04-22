// to run a command on server using udp

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
	int mysockfd;
	unsigned int serverSize; 
	char sendData[MAXLINE],recvData[MAXLINE];
	struct sockaddr_in serverAddress;
	
	// socket at client
	mysockfd=socket(AF_INET, SOCK_DGRAM, 0);
	
	// address of the server where data needs to be sent
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(5000);

	// get the command from client to be executed
	printf("Enter the command: ");
	fgets(sendData,MAXLINE,stdin);

	// send the data to server to execute an instruction
	serverSize=sizeof(serverAddress);
	sendto(mysockfd, sendData, sizeof(sendData), 0, (struct sockaddr *)&serverAddress, serverSize);
	printf("Command sent: %s\n",sendData);

	// get the result of the executed command from server
	recvfrom(mysockfd, recvData, MAXLINE, 0, (struct sockaddr *)&serverAddress, &serverSize);
	printf("Command executed with status: %s\n",recvData);
	return 0;
}