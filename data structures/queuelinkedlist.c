#include<stdio.h>
struct link
    {
    int item;
    struct link *node;
};
struct link *rear=NULL,*front=NULL;
struct link* createlink()
    {
    struct link *p;
    p=(struct link *)malloc(sizeof(struct link));
    p->item=0;
    p->node=NULL;
    return p;
}
int enque(int x)
    {
    struct link *p;
    p=createlink();
    if(front==NULL)
        {
        rear=p;
        front=rear;
        front->item=x;
    }
    else
        {
        rear->node=p;
        rear=p;
        p->item=x;
    }
    return 0;
}
int deque()
    {
    int x,p;
    if(front!=NULL)
        {
        x=front->item;
        p=front->node;
        free(front);
        front=p;
        return x;
    }
    else
        {
        printf("stack empty\n");
        return -1;
    }
}
int main()
    {
    enque(1);
    printf("%d\n",deque());
    enque(3);
    enque(5);
    printf("%d\n",deque());
    enque(7);
    printf("%d\n",deque());
    printf("%d\n",deque());
    printf("%d\n",deque());
    printf("%d\n",deque());
    printf("%d\n",deque());
    return 0;
}