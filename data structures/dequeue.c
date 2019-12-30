#include<stdio.h>
int enquer(int a[],int *front,int *rear,int x)
    {
    if((*front==*rear+1)||(*front==0&&*rear==9))
        {
        printf("queue full\n");
        return -1;
    }
    *rear=*rear+1;
    if(*rear==10)
        *rear=0;
    if(*front==-1)
      {
        *front=0;
        *rear=0;
    }
    a[*rear]=x;
    return 0;
}
int enquef(int a[],int *front,int *rear,int x)
    {
    if((*front==*rear+1)||(*front==0&&*rear==9))
        {
        printf("queue full\n");
        return -1;
    }
    if(*front==-1)
      {
        *front=0;
        *rear=9;
    }
    *front=*front-1;
    if(*front==-1)
        *front=9;
    a[*front]=x;
    return 0;
}
int dequef(int a[],int *front,int *rear)
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
int dequer(int a[],int *front,int *rear)
    {
    int x;
    if(*front==-1)
        {
        printf("queue empty\n");
        return -1;
    }
    x=a[*rear];
    if(*front==*rear)
        {
        *front=-1;
        *rear=-1;
        return x;
    }
    *rear=*rear-1;
    if(*rear==-1)
        *rear=9;
    return x;
}
int main()
    {
    int a[10],front=-1,rear=-1;
    printf("%d\n",dequer(a,&front,&rear));
    enquef(a,&front,&rear,9); 
    enquef(a,&front,&rear,5); 
    enquef(a,&front,&rear,1); 
    enquer(a,&front,&rear,-5);
    enquer(a,&front,&rear,1); 
    enquef(a,&front,&rear,-2);
    printf("%d\n",dequer(a,&front,&rear)); 
    enquef(a,&front,&rear,4); 
    enquef(a,&front,&rear,1); 
    enquer(a,&front,&rear,1); 
    enquef(a,&front,&rear,1); 
    enquer(a,&front,&rear,3); 
    enquef(a,&front,&rear,1); 
    printf("%d\n",dequer(a,&front,&rear));
    enquef(a,&front,&rear,2);
    printf("%d\n",dequef(a,&front,&rear));
    enquer(a,&front,&rear,1);
    printf("%d\n",dequer(a,&front,&rear));
    enquer(a,&front,&rear,1);
    printf("%d\n",dequef(a,&front,&rear));
    printf("%d\n",dequer(a,&front,&rear));
    printf("%d\n",dequer(a,&front,&rear));
    printf("%d\n",dequef(a,&front,&rear));
    printf("%d\n",dequer(a,&front,&rear));
    printf("%d\n",dequer(a,&front,&rear));
    printf("%d\n",dequef(a,&front,&rear));
    printf("%d\n",dequef(a,&front,&rear));
    printf("%d\n",dequef(a,&front,&rear));
    printf("%d\n",dequer(a,&front,&rear));
    printf("%d\n",dequef(a,&front,&rear));
    return 0;
}