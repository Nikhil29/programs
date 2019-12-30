#include<stdio.h>
int binarysearch(int *a,int i,int j,int s)
    {
    int k=(i+j)/2,l;
    if(i>=j)
        return -1;
    if(a[k]==s)
        return k;
    else if(a[k]>s)
        {
        l=binarysearch(a,i,k-1,s);
        return l;
    }
    else
        {
        l=binarysearch(a,k+1,j,s);
        return l;
    }
}
int main()
    {
    int n,*a,i,s;
    printf("enter the no. of elements in array\n");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    printf("enter the elements of sorted array\n");
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
    }
    printf("enter the element to be searched\n");
    scanf("%d",&s);
    i=binarysearch(a,0,n-1,s);
    printf("%d\n",i);
    return 0;
}
