#include<stdio.h>
int enque(int a[],int *front,int *rear,int x)
    {
    if(*rear==999)
        {
        printf("queue full\n");
        return -1;
    }
    *rear=*rear+1;
    if(*front==-1)
        *front=0;
    a[*rear]=x;
    return 0;
}
int deque(int a[],int *front,int *rear)
    {
    int x;
    if(*front==*rear+1||*front==-1)
        {
        printf("queue empty\n");
        return -1;
    }
    x=a[*front];
    *front=*front+1;
    return x;
}
int main()
    {
    int a[1000],front=-1,rear=-1;
    enque(a,&front,&rear,5);
    printf("%d\n",deque(a,&front,&rear));
    enque(a,&front,&rear,4);
    enque(a,&front,&rear,3);
    printf("%d\n",deque(a,&front,&rear));
    enque(a,&front,&rear,2);
    printf("%d\n",deque(a,&front,&rear));
    enque(a,&front,&rear,1);
    printf("%d\n",deque(a,&front,&rear));
    printf("%d\n",deque(a,&front,&rear));
    printf("%d\n",deque(a,&front,&rear));
    return 0;
}