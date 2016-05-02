#include<bits/stdc++.h>
using namespace std;
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_KEY 34
#define MAX_LEN 100

typedef struct mymsgbuf{
    long mtype;
    char mtext[MAX_LEN];
}msg;

int main(int argc, char const *argv[])
{
	int msqQue, temp;
	msg sendMsg;

	// create the msg queue
	msqQue = msgget(MSG_KEY, IPC_CREAT | 0666);
	if(msqQue==-1){
		perror("Msq Queue failed");
		return -1;
	}

	// get the msg from user
	printf("Enter the message to send:\n");
	scanf("%[^\n]",sendMsg.mtext);

	// send the message
	if(msgsnd(msqQue, &sendMsg, strlen(sendMsg.mtext)+1, 0) < 0){
		perror("Message Sending failed");
		return -1;
	}
	printf("Message has been sent\n");
	return 0;
}