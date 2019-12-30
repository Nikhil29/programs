#include<stdio.h>
float mean(int *a,int n)
    {
    int i;
    float k=0;
     for(i=0;i<n;i++)
         {
         k=k+a[i];
     }
    k=k/n;
    return k;
}
int main()
    {
    int n,*a,i;
    float m;
    printf("enter the no. of integers in array\n");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    printf("enter the elements of array\n");
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
    }
    m=mean(a,n);
    printf("the mean is %f\n",m);
    return 0;
}