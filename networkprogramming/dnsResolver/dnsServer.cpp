#include<stdio.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<netinet/in.h>
int main(int argc, char* argv[])
{
	struct hostent* host;
	struct in_addr h_addr;
	
	if(argc!=2){
		printf("Requires 1 argument\n");
	}
	
	// get the host
	if((host=gethostbyname(argv[1]))==NULL){
		printf("Nslookup Failed for %s\n",argv[1]);
	}

	// convert ip address from network byte order to dotted decimal notation 
	h_addr.s_addr = *((unsigned long*)host->h_addr_list[0]);
	printf("Ip Address: %s\n", inet_ntoa(h_addr));

	// print the details
	printf("Host Name: %s\n",host->h_name);
	printf("Address Length: %d\n",host->h_length);
	printf("Address Type: %d\n",host->h_addrtype);
	printf("List of Address: %s\n",inet_ntoa(h_addr_list[0]));
	return 0;
}