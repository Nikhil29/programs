#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#define MAXLINE 200
int integer_to_string(int x,char str[]){
	int i=0,n;
	char temp;
	while(x!=0){
		str[i]=x%10+48;
		x=x/10;
		i++;
	}
	str[i]='\0';
	n=i;
	n=strlen(str);
	for(i=0;i<n/2;i++){
		temp=str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=temp;
	}
	return 0;
}
int main()
{
	int mysockfd = socket(AF_INET, SOCK_STREAM, 0), clientfd,no_of_words;
	struct sockaddr_in servaddr;
	char receive_data[MAXLINE],send_data[MAXLINE];
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
		if((n=read(clientfd,receive_data,MAXLINE-1))==0)
			break;
		if(n>0)
		{
			receive_data[n]='\0';
			no_of_words=0;
			for(i=0;receive_data[i]!='\0';i++)
			{
				if(receive_data[i]==' ')
					no_of_words++;
			}
			no_of_words++;
			printf("%s %d\n",receive_data,no_of_words);
			integer_to_string(no_of_words,send_data);
			write(clientfd,send_data,strlen(send_data));
		}
	}
	printf("end\n");
	return 0;
}