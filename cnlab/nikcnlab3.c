#include<stdio.h>
int main()
{
	char a;
	FILE *fp=fopen("./demo1.tr","r");
	while(fp.eof()!=0)
	fscanf(fp,"%c",&a);
	printf("%c",a);
	fclose(fp);
	return 0;
}
