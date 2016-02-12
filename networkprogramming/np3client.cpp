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
int main()
{
	int mysockfd = socket(AF_INET, SOCK_STREAM, 0),no_of_words,len;
	struct sockaddr_in servaddr;
	char sendline[MAXLINE],receiveline[MAXLINE];
	int n,temp;
	if(mysockfd<0)
	{
		printf("socket failed\n");
		return -1;
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5000);
	// inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
	temp = connect(mysockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if(temp<0)
	{
		printf("connection failed\n");
		return -1;
	}
	else
	{
		printf("Connection Successful\n");
	}
	printf("Enter the data to be send\n");
	while(fgets(sendline,MAXLINE,stdin)!=NULL)
	{
		write(mysockfd,sendline,strlen(sendline));
		printf("line send\n");
		len=read(mysockfd,receiveline,MAXLINE-1);
		receiveline[len]='\0';
		printf("Frequency of words:\n%s",receiveline);
		printf("Enter the data to be send\n");
	}
	exit(0);
	return 0;
}