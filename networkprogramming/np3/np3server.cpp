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
	clientfd = accept(mysockfd, (struct sockaddr *)&client, (socklen_t *)&clilen);
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
			map<string,int> words;
			map<string,int>::iterator it;
			char substring[MAXLINE];
			int index=0;
			receive_data[n]='\0';
			no_of_words=0;
			for(i=0;receive_data[i]!='\0';i++)
			{
				if(receive_data[i]==' '){
					substring[index]='\0';
					it=words.find(substring);
					if(it==words.end()){
						words[substring]=1;
					}
					else{
						it->second++;
					}
					index=0;				
					no_of_words++;
				}
				else{
					substring[index]=receive_data[i];
					index++;
				}
				// while(receive_data[i]==' ')
				// 	i++;
				// i--;
			}
			index=0;
			for(it=words.begin();it!=words.end();it++){
				for(i=0;i<(it->first).length();i++){
					send_data[index]=(it->first)[i];
					index++;
				}
				send_data[index]=' ';
				index++;
				sprintf(substring,"%d\n",it->second);
				for(i=0;substring[i]!='\0';i++){
					send_data[index]=substring[i];
					index++;
				}
			}
			send_data[index]='\0';
			write(clientfd,send_data,strlen(send_data));
		}
	}
	printf("end\n");
	return 0;
}