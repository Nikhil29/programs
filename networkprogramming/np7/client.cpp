#include<bits/stdc++.h>
using namespace std;
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#define MAXLINE 200

int main(){
	struct sockaddr_in servaddr;
	char rcvline[MAXLINE];
	int n, mysockfd;
	
	// make socket
	mysockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(mysockfd<0){
		perror("Socket failed");
		return -1;
	}

	// get the server address
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5001);
	
	// connect with the server
	if(connect(mysockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
		perror("Connection failed");
		return -1;
	}
	else{
		printf("Connection Successful\n");
	}

	// get date/time to server
	printf("Current Date & Time: ");
	while((n=read(mysockfd, rcvline, MAXLINE-1)) > 0){
		rcvline[n]='\0';
		printf("%s",rcvline);
	}
	printf("\n");
	printf("Disconnecting from client\n");
	return 0;
}