// to transfer file using udp

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
	struct sockaddr_in serverAddress, clientAddress;

	// socket file descriptor at server
	mysockfd=socket(AF_INET, SOCK_DGRAM, 0);
	if(mysockfd==-1){
		printf("socket at server failed\n");
		exit(EXIT_FAILURE);
	}

	// create server address
	serverAddress.sin_family=AF_INET;
	serverAddress.sin_port=htons(5000);

	// bind the server address with the server file descriptor
	bind(mysockfd, &serverAddress, (socklen_t)sizeof(serverAddress));

	

	return 0;
}