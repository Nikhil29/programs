#include<stdio.h>
int move(int n,int s,int d)
    {
    printf("move disk %d from tower %d to tower %d\n",n,s,d);
    return 0;
}
int towerofhanoi(int n,int s,int d,int i)
    {
    if(n==0)
        return 0;
    towerofhanoi(n-1,s,i,d);
    move(n,s,d);
    towerofhanoi(n-1,i,d,s);
    return 0;
}
int main()
    {
    int i,j,k,n;
    printf("Enter the no. of disks in tower of hanoi\n");
    scanf("%d",&n);
    printf("Enter the source tower and destination tower from 1,2,3\n");
    scanf("%d%d",&i,&j);
    k=6-i-j;
    towerofhanoi(n,i,j,k);
    return 0;
}