// execute command on server and return its status

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
	int mysockfd,status;
	unsigned int clientSize;
	struct sockaddr_in serverAddress, clientAddress;
	char recvData[MAXLINE], sendData[MAXLINE];

	// create socket file descriptor at server
	mysockfd=socket(AF_INET, SOCK_DGRAM, 0);

	// create the server address structure
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family=AF_INET;
	serverAddress.sin_port=htons(5000);

	// bind server i.e. our address to our socket
	bind(mysockfd, (struct sockaddr *)&serverAddress, (socklen_t)sizeof(serverAddress));

	// receive data from client
	clientSize=sizeof(clientAddress);
	recvfrom(mysockfd, recvData, sizeof(recvData), 0, (struct sockaddr *)&clientAddress, &clientSize);
	printf("Data receive: %s\n",recvData);

	// execute the command on server and return the status
	status=system(recvData);
	sprintf(sendData, "%d", status);

	// send data to client
	sendto(mysockfd, sendData, sizeof(sendData), 0, (struct sockaddr *)&clientAddress, clientSize);
	printf("Status send: %s\n",sendData);
	return 0;
}