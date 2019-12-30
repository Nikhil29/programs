#include<stdio.h>
struct dlink
    {
    int item;
    struct dlink *next;
    struct dlink *prev;
};
struct dlink* createdlink()
    {
    struct dlink *p;
    p=(struct dlink *)malloc(sizeof(struct dlink));
    p->item=0;
    p->next=NULL;
    p->prev=NULL;
    return p;
}
void insertelementd(struct dlink *a,int x)
    {
    a->item=x;
}
void deletedlink(struct dlink *a)
    {
    a->prev->next=a->next;
    a->next->prev=a->prev;
    free(a);
}
void adddlink(struct dlink *p,int x)
    {
    struct dlink *a;
    a=createdlink();
    a->item=x;
    if(p->next==NULL)
        {
        p->next=a;
        a->prev=p;
    }
    else
        {
        a->next=p->next;
        p->next=a;
        a->prev=p;
    }
}
int main()
    {
    struct dlink *m,*t1;
    m=createdlink();
    insertelementd(m,1);
    adddlink(m,2);
    adddlink(m->next,4);
    for(t1=m;t1!=NULL;t1=t1->next)
        {
        printf("%d ",t1->item);
    }
    return 0;
}