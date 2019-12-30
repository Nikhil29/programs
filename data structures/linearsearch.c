#include<stdio.h>
int linearsearch(int *a,int i,int j,int s)
    {
    int k;
    for(k=i;k<=j;k++)
        {
        if(s==a[k])
            break;
    }
    if(k==j+1)
        return -1;
    else
        return k;
}
int main()
    {
    int n,*a,i,s;
    printf("enter the no. of elements in array\n");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    printf("enter the elements of array\n");
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
    }
    printf("enter the element to be searched\n");
    scanf("%d",&s);
    i=linearsearch(a,0,n-1,s);
    printf("%d\n",i);
    return 0;
}