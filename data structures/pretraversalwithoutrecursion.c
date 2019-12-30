#include<stdio.h>
struct link
    {
    int item;
    struct link *right;
    struct link *left;
};
struct link* createlink()
    {
    struct link *p;
    p=(struct link *)malloc(sizeof(struct link));
    p->item=0;
    p->right=NULL;
    p->left=NULL;
    return p;
}
struct link* createtree(int a[],int i,int argc)
    {
    if(i>=argc)
        {
        return NULL;
    }
    struct link *p;
    p=createlink();
    p->item=a[i];
    p->left=createtree(a,2*i,argc);
    p->right=createtree(a,2*i+1,argc);
    return p;
}
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
int pretraversal(struct link *p)
    {
    int a[1000],top=-1;
    push(a,&top,p);
    while(top!=-1)
        {
        p=pop(a,&top);
        printf("%d ",p->item);
        if(p->right!=NULL)
        push(a,&top,p->right);
        if(p->left!=NULL)
        push(a,&top,p->left);
    }
    return 0;
}
int main(int argc,char *argv[])
    {
    int i,a[1000];
    for(i=1;i<argc;i++)
        {
        a[i]=atoi(argv[i]);
    }
    struct link *p;
    p=createtree(a,1,argc);
    pretraversal(p);
    return 0;
}