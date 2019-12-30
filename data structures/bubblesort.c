#include<stdio.h>
void bubblesort(int *a,int n)
    {
    int i,j,k,l,p;
    for(i=0;i<n;i++)
        {
        for(j=0;j<n-i;j++)
            {
            if(a[j]>a[j+1])
                {
                l=a[j];
                a[j]=a[j+1];
                a[j+1]=l;
            }
        }
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
    bubblesort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}