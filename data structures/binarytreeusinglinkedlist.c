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
int intraversal(struct link *p)
    {
    if(p==NULL)
        return 0;
    intraversal(p->left);
    printf("%d ",p->item);
    intraversal(p->right);
    return 0;
}
int pretraversal(struct link *p)
    {
    if(p==NULL)
        return 0;
    printf("%d ",p->item);
    pretraversal(p->left);
    pretraversal(p->right);
    return 0;
}
int posttraversal(struct link *p)
    {
    if(p==NULL)
        return 0;
    posttraversal(p->left);
    posttraversal(p->right);
    printf("%d ",p->item);
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
    printf("\n");
    intraversal(p);
    printf("\n");
    posttraversal(p);
    printf("\n");
    return 0;
}