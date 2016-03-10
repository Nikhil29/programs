// decryption for the text stegnography

#include<bits/stdc++.h>
using namespace std;
int main()
{
	// text to be decrypted as a file
	FILE *stegnofile=fopen("stegnographyoutput","r");
	
	char c,output[10000],top=0;
	int ans,count=0;
	
	//if single space b/w words then bit is 1 else bit in 0
	c = fgetc(stegnofile);
	while(c!=EOF)
	{
		if(c==' ')
		{
			c = fgetc(stegnofile);
			if(c==' ')
			{
				ans=ans*2+1;
			}
			else
			{
				ans=ans*2;
			}
			count=(count+1)%8;
			if(count==0)
			{
				output[top]=(char)ans;
				top++;
				ans=0;
			}
		}
		c = fgetc(stegnofile);
	}
	output[top]='\0';
	
	printf("Hidden Text: %s\n",output);
	return 0;
}