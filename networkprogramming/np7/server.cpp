#include<bits/stdc++.h>
using namespace std;
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#define MAXLEN 200

int main()
{
	struct sockaddr_in servaddr, client;
	char sendData[MAXLEN];
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

	// accept the clients request
	clientfd = accept(mysockfd, (struct sockaddr *)&client, (unsigned int *)&clilen);
	if(clientfd<0){
		perror("Accept failed");
		return -1;
	}
	else{
		printf("Accept successful\n");
	}

	// get current time
	time_t ct;
	ct = time(NULL);
	sprintf(sendData, "%s", ctime(&ct));

	// send time to client
	write(clientfd, sendData, strlen(sendData));
	printf("Current date & time => %s Sent\n",sendData);

	printf("Client Disconnected\n");
	close(clientfd);
	return 0;
}