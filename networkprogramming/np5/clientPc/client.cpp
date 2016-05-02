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
	int mysockfd, len;
	unsigned int serverSize;
	char sendData[MAXLINE],recvData[MAXLINE],fileName[MAXLINE];
	struct sockaddr_in serverAddress;

	// socket at client
	mysockfd=socket(AF_INET, SOCK_DGRAM, 0);
	if(mysockfd==-1){
		perror("Socket client failed");
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
	if(sendto(mysockfd, fileName, strlen(fileName), 0, (struct sockaddr*)&serverAddress, (socklen_t)serverSize) < 0){
		perror("Sending failed");
		return -1;
	}

	// download the file
	FILE *download = fopen(fileName, "w");
	if(download==NULL){
		printf("File opening failed\n");
		return -1;
	}
	else{
		while(recvfrom(mysockfd, recvData, MAXLINE, 0, (struct sockaddr *)&serverAddress, (socklen_t *)&serverSize) > 0){
			fputs(recvData, download);
// here break should not be done but in udp it recvfrom cannot stop as it cannot find EOF
// break is done assuming file is less than MAXLINE size
			break;
		}
	}
	fclose(download);
	
	printf("File has been downloaded: %s\n",fileName);
	return 0;
}