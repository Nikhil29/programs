#include<bits/stdc++.h>
using namespace std;
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#define MAXLEN 200

void reverseString(char input[], char output[]){
	int i=0, len=strlen(input);
	while(len--){
		output[i]=input[len];
		i++;
	}
	output[i]='\0';
}

int main()
{
	struct sockaddr_in servaddr, client;
	char sendData[MAXLEN], rcvData[MAXLEN];
	int n, temp, mysockfd, clientfd;
	int clilen=sizeof(client);

	// create socket at server
	mysockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(mysockfd<0){
		perror("Socket failed");
		return -1;
	}

	// create the server address
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5001);
	
	// bind the server address to the socket
	if(bind(mysockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
		perror("Bind failed");
		return -1;
	}
	else{
		printf("Bind successful\n");
	}

	// listen to the requests with at max 2 requests
	if(listen(mysockfd, 2) < 0){
		perror("Listen failed");
		return -1;
	}
	else{
		printf("Listen successful\n");
	}
	while(1){
		// accept the clients request
		clientfd = accept(mysockfd, (struct sockaddr *)&client, (unsigned int *)&clilen);
		if(clientfd<0){
			perror("Accept failed");
			return -1;
		}
		else{
			printf("Accept successful\n");
		}

		// get string from client
		n=read(clientfd, rcvData, MAXLEN-1);
		if(n<0){
			perror("Read error in server");
			return -1;
		}
		rcvData[n]='\0';

		// reverse the string
		reverseString(rcvData, sendData);

		// send reversed string to client
		write(clientfd, sendData, strlen(sendData));
		printf("Reversed String => %s sent to client.\n", sendData);

		printf("Client Disconnected\n");
		close(clientfd);
	}
	return 0;
}