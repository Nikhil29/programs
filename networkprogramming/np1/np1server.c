#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	struct sockaddr_in servaddr;
	char output[20];
	int n, temp, i, j, mysockfd, clientfd;
	struct sockaddr_in client;
	int clilen=sizeof(client);

	// create socket at server
	mysockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(mysockfd<0)
	{
		perror("Socket failed");
		return -1;
	}

	// create the server address
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5000);
	// inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
	
	// bind the server address to the socket
	temp = bind(mysockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if(temp<0)
	{
		perror("Bind failed");
		return -1;
	}
	else
	{
		printf("Bind successful\n");
	}

	// listen to the requests with at max 2 requests
	temp = listen(mysockfd, 2);
	if(temp<0)
	{
		perror("Listen failed");
		return -1;
	}
	else
	{
		printf("Listen successful\n");
	}

	// accept the clients request
	clientfd = accept(mysockfd, (struct sockaddr *)&client, (unsigned int *)&clilen);
	if(clientfd<0)
	{
		perror("Accept failed");
		return -1;
	}
	else
	{
		printf("Accept successful\n");
	}

	// communicate with client
	while(1)
	{
		if((n=read(clientfd,output,20-1))==0)
			break;
		if(n>0)
		{
			output[n]='\0';
			printf("%s\n",output);
		}
	}
	printf("Client Disconnected\n");
	return 0;
}