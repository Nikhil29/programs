#include<stdio.h>
int mode(int *a,int n)
    {
    int i,j,k=0,m,mode=0;
    for(i=0;i<n;i++)
        {
        m=1;
        for(j=i+1;j<n;j++)
            {
            if(a[i]==a[j])
                m++;
        }
        if(m>k)
            {
            k=m;
            mode=a[i];
        }
    }
    return mode;
}
int main()
    {
    int n,*a,i,mod;
    printf("enter the no. of integers in array\n");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    printf("enter the elements of array\n");
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
    }
    mod=mode(a,n);
    printf("the mode is %d\n",mod);
    return 0;
}