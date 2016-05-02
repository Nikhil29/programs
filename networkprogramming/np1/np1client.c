#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#define MAXLINE 20
int main()
{
	struct sockaddr_in servaddr;
	char sendline[MAXLINE];
	int n, temp, mysockfd;
	
	// make socket
	mysockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(mysockfd<0)
	{
		perror("Socket failed");
		return -1;
	}

	// get the server address
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5000);
	// inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
	
	// connect with the server
	temp = connect(mysockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if(temp<0)
	{
		perror("Connection failed");
		return -1;
	}
	else
	{
		printf("Connection Successful\n");
	}

	// input data to send to server
	printf("Enter the data to be send: \n");
	while(fgets(sendline,MAXLINE,stdin)!=NULL)
	{
		write(mysockfd,sendline,strlen(sendline));
		printf("Line send\n");
		printf("Enter the data to be send: \n");
	}
	exit(0);
	return 0;
}