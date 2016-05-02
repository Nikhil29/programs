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
	int msgQue, temp;
	msg rcvMsg;
	struct msqid_ds myqueue;

	// create the msg queue
	msgQue = msgget(MSG_KEY, IPC_CREAT | 0666);
	if(msgQue==-1){
		perror("Msq Queue failed");
		return -1;
	}

	// receive the message
	if(msgrcv(msgQue, &rcvMsg, MAX_LEN, 0, 0) < 0){
		perror("Message Receiving failed");
		return -1;
	}

	// print the message
	printf("Message Received: %s\n", rcvMsg.mtext);

	// print data about queue
	msgctl(msgQue, IPC_STAT, &myqueue);
	printf("PID of Last Sent Message: %d\n", myqueue.msg_lspid);
	printf("PID of Last Received Message: %d\n", myqueue.msg_lrpid);
	printf("Current No of messages in queue: %lu\n", myqueue.msg_qnum);
	printf("Time of last change: %ld\n", myqueue.msg_ctime);
	return 0;
}