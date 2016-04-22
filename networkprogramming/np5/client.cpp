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
	unsigned int serverSize;
	char sendData[MAXLINE],recvData[MAXLINE],fileName[100];
	struct sockaddr_in serverAddress;

	// socket at client
	mysockfd=socket(AF_INET, SOCK_DGRAM, 0);
	if(mysockfd==-1){
		printf("socket client failed\n");
		exit(-1);
	}

	// server address
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(5000);

	// get the filename to be downloaded
	printf("Enter the file name to download: ");
	scanf("%s",fileName);

	// send the file name to the server
	serverSize=sizeof(serverAddress);
	sendto(mysockfd, fileName, strlen(fileName), 0, (struct sockaddr*)serverAddress, serverSize);

	// download the file

	return 0;
}