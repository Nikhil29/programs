#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int mysockfd = socket(AF_INET, SOCK_STREAM, 0), clientfd;
	struct sockaddr_in servaddr;
	char output[20];
	int n,temp,i,j;
	if(mysockfd<0)
	{
		printf("socket failed\n");
		return -1;
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5000);
	// inet_pton(AF_INET, "227.0.0.1", &servaddr.sin_addr);
	temp = bind(mysockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if(temp<0)
	{
		printf("bind failed\n");
		return -1;
	}
	else
	{
		printf("bind successful\n");
	}
	temp = listen(mysockfd, 1);
	if(temp<0)
	{
		printf("listen failed\n");
		return -1;
	}
	else
	{
		printf("listen successful\n");
	}
	struct sockaddr_in client;
	int clilen=sizeof(client);
	clientfd = accept(mysockfd, (struct sockaddr *)&client, &clilen);
	if(clientfd<0)
	{
		printf("accept failed\n");
		return -1;
	}
	else
	{
		printf("accept successful\n");
	}
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
	printf("end\n");
	return 0;
}