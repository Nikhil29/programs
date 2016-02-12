#include<bits/stdc++.h>
using namespace std;
int main()
{
	FILE *input=fopen("stegnographyinput","r");
	FILE *output=fopen("stegnographyoutput","w");
	char hidden[1000],a[1000];
	int temp,binary[8],i,j;
	printf("Enter the text that you wish to hide\n");
	scanf("%[^'\n']s",hidden);
	// gets(hidden);
	for(j=0;hidden[j]!='\0';j++)
	{
		// printf("%c",hidden[i]);
		temp=(int)hidden[j];
		// printf("%d ",temp);
		for(i=0;i<8;i++)
		{
			binary[i]=temp%2;
			temp=temp/2;
		}
		for(i=7;i>=0;i--)
		{
			fscanf(input,"%s",a);
			fprintf(output,"%s",a);
			if(binary[i]==0)
			{
				fprintf(output," ");
			}
			else
			{
				fprintf(output,"  ");
			}
		}
	}
	while(fscanf(input,"%s",a)!=-1)
	{
		fprintf(output,"%s ",a);
	}
	fclose(input);
	fclose(output);
	printf("Text Stegnography completed\n");
	return 0;
}