#include<stdio.h>
void main()
{
FILE *f1,*f2;
int key;
char c;
f1=fopen("ciphertext.txt","r");
f2=fopen("file2.txt","w");
printf("enter the value of key");
scanf("%d",&key);
while((fscanf(f1,"%c",&c))!=EOF)
{
if((c>=97)&&(c<123))
{
c=c+key;
if(c>122)
{
c=c-123;
c=c+97;
}
fprintf(f2,"%c",c);
}
else if((c>=65)&&(c<91))
{
c=c+key;
if(c>90)
{
c=c-91;
c=c+65;
}
fprintf(f2,"%c",c);
}
}

fclose(f1);
fclose(f2);


}



