#include<stdio.h>
int main()
{
	int key,check;
	char c;
	printf("Enter the key\n");
	scanf("%d",&key);
	FILE *input=fopen("cipherinput","r");
	FILE *output=fopen("cipheroutput","w");
	while(1)
	{
		check=fscanf(input,"%c",&c);
		if(check==-1)
			break;
		if(c==' ')
		{
			fprintf(output," ");
		}
		if(c>=97&&c<=122)
		{
			c=c-97;
			c=c+key;
			c=c%26;
			c=c+97;
			fprintf(output,"%c",c);
		}
		else if(c>=65&&c<=90)
		{
			c=c-65;
			c=c+key;
			c=c%26;
			c=c+65;
			fprintf(output,"%c",c);	
		}
	}
	return 0;
}
