#include<stdio.h>
struct link
    {
    int item;
    struct link *node;
};
struct link* createlink()
    {
    struct link *p;
    p=(struct link *)malloc(sizeof(struct link));
    p->item=0;
    p->node=NULL;
    return p;
}
void insertelement(struct link *a,int x)
    {
    a->item=x;
}
void deletelink(struct link *a)
    {
    free(a);
}
void deletenextlink(struct link *a)
    {
    struct link *b;
    b=a->node;
    a->node=a->node->node;
    free(b);
}
void addlink(struct link *p,int x)
    {
    struct link *a;
    a=createlink();
    a->item=x;
    if(p->node==NULL)
        {
        p->node=a;
    }
    else
        {
        a->node=p->node;
        p->node=a;
    }
}
int addlinkfromstart(struct link *start,int i,int x)
    {
    int j;
    struct link *t1;
    for(j=1;j<i&&start->node!=NULL;j++)
        {
        start=start->node;
    }
    t1=createlink();
    t1->node=start->node;
    start->node=t1;
    t1->item=x;
    return 0;
}
int addlinkfromlast(struct link *start,int i,int x)
    {
    int j;
    struct link *t1=start,*t2=start;
    for(j=1;j<i&&t1->node!=NULL;j++)
        {
        t1=t1->node;
    }
    for(j=0;t1->node!=NULL;j++)
        {
        t1=t1->node;
        t2=t2->node;
    }
    //printf("%d\n",t2->item);
    t1=createlink();
    t1->node=t2->node;
    t2->node=t1;
    t1->item=x;
    return 0;
}
struct link* middlelink(struct link *start)
    {
    int i;
    struct link *t1=start,*t2=start;
    for(i=0;t1->node!=NULL;i++)
        {
        t1=t1->node;
        if(i%2==1)
            t2=t2->node;
    }
    return t2;
}
struct link* reverselist(struct link *start)
    {
    struct link *t2=start,*t1=NULL,*t3=start->node;
    int i;
    while(t3!=NULL)
        {
        t2->node=t1;
        t1=t2;
        t2=t3;
        t3=t3->node;
    }
    t2->node=t1;
    return t2;
}
int checkloop(struct link *start)
    {
    int i;
    struct link *t2=start;
    for(i=0;start->node!=NULL;i++)
        {
        start=start->node;
        if(i%2==1)
            t2=t2->node;
        if(start==t2)
            break;
    }
    if(start->node==NULL)
        return 0;
    else
        return 1;
}
struct link* loopstart(struct link *start)
    {
    int i;
    struct link *t1=start,*t2=start;
    for(i=0;t1->node!=NULL;i++)
        {
        t1=t1->node;
        if(i%2==1)
            t2=t2->node;
        if(t1==t2)
            break;
    }
    if(t1->node==NULL)
        return NULL;
    else
        {
        t2=start;t1=t1->node;
        while(t1!=t2)
            {
            t1=t1->node;
            t2=t2->node;
        }
        return t1;
    }
}
int main()
    {
    struct link *m,*x,*t1;
    m=createlink();
    insertelement(m,1);
    addlink(m,2);
    addlink(m->node,4);
    addlinkfromlast(m,3,3);
    addlinkfromstart(m,3,10);
    //deletenextlink(m->node);
    x=middlelink(m);
    m=reverselist(m);
    m->node->node->node->node->node=m->node->node->node;
    int i=0;
    x=loopstart(m);
    for(t1=m;t1!=NULL&&i<10;t1=t1->node)
        {
        printf("%d ",t1->item);
        i++;
    }
    printf("\n");
    if(x!=NULL)
    printf("%d ",x->item);
    return 0;
}