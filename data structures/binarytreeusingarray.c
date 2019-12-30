#include<stdio.h>
int pretraversal(int *a,int i,int argc)
    {
    if(i>=argc)
        return 0;
    printf("%d ",a[i]);
    pretraversal(a,2*i,argc);
    pretraversal(a,2*i+1,argc);
    return 0;
}
int intraversal(int *a,int i,int argc)
    {
    if(i>=argc)
        return 0;
    intraversal(a,2*i,argc);
    printf("%d ",a[i]);
    intraversal(a,2*i+1,argc);
    return 0;
}
int posttraversal(int *a,int i,int argc)
    {
    if(i>=argc)
        return 0;
    posttraversal(a,2*i,argc);
    posttraversal(a,2*i+1,argc);
    printf("%d ",a[i]);
    return 0;
}
int main(int argc,char *argv[])
    {
    int a[1000],i;
    for(i=1;i<argc;i++)
        {
        a[i]=atoi(argv[i]);
    }
    pretraversal(a,1,argc);
    printf("\n");
    posttraversal(a,1,argc);
    printf("\n");
    intraversal(a,1,argc);
    printf("\n");
    return 0;
}