#include<stdio.h>
int enque(int a[],int *front,int *rear,int x)
    {
    if((*front==*rear+1)||(*front==0&&*rear==9))
        {
        printf("stack full\n");
        return -1;
    }
    *rear=*rear+1;
    if(*rear==10)
        *rear=0;
    if(*front==-1)
        *front=0;
    a[*rear]=x;
    return 0;
}
int deque(int a[],int *front,int *rear)
    {
    int x;
    if(*front==-1)
        {
        printf("queue empty\n");
        return -1;
    }
    x=a[*front];
    if(*front==*rear)
        {
        *front=-1;
        *rear=-1;
        return x;
    }
    *front=*front+1;
    if(*front==10)
        *front=0;
    return x;
}
int main()
    {
    int a[10],front=-1,rear=-1;
    printf("%d\n",deque(a,&front,&rear));
    enque(a,&front,&rear,9);   
    enque(a,&front,&rear,5);
    enque(a,&front,&rear,1);
    enque(a,&front,&rear,-5);
    enque(a,&front,&rear,1);
    enque(a,&front,&rear,-2);
    printf("%d\n",deque(a,&front,&rear));
    enque(a,&front,&rear,4);
    enque(a,&front,&rear,1);
    enque(a,&front,&rear,1);
    enque(a,&front,&rear,1);
    enque(a,&front,&rear,3);
    enque(a,&front,&rear,1);
    printf("%d\n",deque(a,&front,&rear));
    enque(a,&front,&rear,2);
    printf("%d\n",deque(a,&front,&rear));
    enque(a,&front,&rear,1);
    printf("%d\n",deque(a,&front,&rear));
    enque(a,&front,&rear,1);
    printf("%d\n",deque(a,&front,&rear));
    printf("%d\n",deque(a,&front,&rear));
    printf("%d\n",deque(a,&front,&rear));
    printf("%d\n",deque(a,&front,&rear));
    printf("%d\n",deque(a,&front,&rear));
    printf("%d\n",deque(a,&front,&rear));
    printf("%d\n",deque(a,&front,&rear));
    printf("%d\n",deque(a,&front,&rear));
    printf("%d\n",deque(a,&front,&rear));
    printf("%d\n",deque(a,&front,&rear));
    printf("%d\n",deque(a,&front,&rear));
    return 0;
}