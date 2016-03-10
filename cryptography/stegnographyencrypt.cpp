// encryption for the text stegnography

#include<bits/stdc++.h>
using namespace std;
int main()
{
	// Input/Output files
	FILE *input=fopen("stegnographyinput","r");
	FILE *output=fopen("stegnographyoutput","w");
	
	char hidden[1000],a[1000];
	int temp,binary[8],i,j;
	
	// input text to be hidden
	printf("Enter the text that you wish to hide:  ");
	scanf("%[^'\n']s",hidden);
	
	//algo
	for(j=0;hidden[j]!='\0';j++)
	{
		// convert the character to bit form
		temp=(int)hidden[j];
		for(i=0;i<8;i++)
		{
			binary[i]=temp%2;
			temp=temp/2;
		}

		// if bit is 1 then 2 spaces else 1 space after the word
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

	//print output to file
	while(fscanf(input,"%s",a)!=-1)
	{
		fprintf(output,"%s ",a);
	}
	printf("Text Stegnography completed\n");
	
	//close the files
	fclose(input);
	fclose(output);
	return 0;
}