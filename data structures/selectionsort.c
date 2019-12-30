#include<stdio.h>
void selectionsort(int *a,int n)
    {
    int i,j,k,l,p;
    for(i=0;i<n;i++)
        {
        for(j=i+1;j<n;j++)
            {
            if(a[j]<a[i])
                {
                l=a[i];
                a[i]=a[j];
                a[j]=l;
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
    selectionsort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}