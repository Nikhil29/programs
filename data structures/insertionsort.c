#include<stdio.h>
void insertionsort(int *a,int n)
    {
    int i,j,k,l;
    for(i=1;i<n;i++)
        {
        l=a[i];
        for(j=i-1;j>=0;j--)
            {
            if(l>a[j])
                {
                a[j+1]=l;
                break;
            }
            else
                {
                a[j+1]=a[j];
            }
        }
        if(j==-1)
            a[0]=l;
    }
}
int main()
    {
    int n,*a,i;
    printf("enter the no. of integers in array\n");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    printf("enter the elements of array\n");
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
    }
    insertionsort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}