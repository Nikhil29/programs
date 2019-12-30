#include<stdio.h>
int push(int a[],int *top,int x)
    {
    if(*top==999)
        {
        printf("stack full\n");
        return -1;
    }
    *top=*top+1;
    a[*top]=x;
    return 0;
}
int pop(int a[],int *top)
    {
    if(*top==-1)
        {
        printf("stack empty\n");
        return -1;
    }
    int u=a[*top];
    *top=*top-1;
    return u;
}
int main()
    {
    int a[1000],top=-1,x,y=1;
    while(y)
    {
    printf("press 1 to push an element\n press 2 to pop an element\n");
    scanf("%d",&y);
    switch(y)
        {
        case 1:
        {
            printf("enter the value to be added to stack\n");
            scanf("%d",&x);
            push(a,&top,x);
            break;
        }
        case 2:
        {
            x=pop(a,&top);
            printf("the element is %d\n",x);
            break;
        }
    }
    }
    return 0;
}