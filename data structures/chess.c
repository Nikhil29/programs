#include<stdio.h>
int main()
    {
    int i,j,k,l;
    char a[100],b[100];
    printf("Enter the row and column of box in the chess board\n");
    scanf("%d%d",&i,&j);
    printf("Enter the color of this box and the other color in the chess board\n");
    scanf("%s%s",a,b);
    printf("Enter the row and column of the box whose color you wish to find\n");
    scanf("%d%d",&k,&l);
    if((i+j)%2==(k+l)%2)
        printf("The color is %s",a);
    else
        printf("The color is %s",b);
    return 0;
}