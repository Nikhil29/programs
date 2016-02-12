#include<bits/stdc++.h>
using namespace std;
int main()
{
	FILE *input = fopen("charactersinput.txt", "r");
	char temp, search;
	int ans=0;
	printf("Enter the character\n");
	scanf("%c",&search);
	while((temp=fgetc(input))!=EOF)
	{
		if(temp==search)
			ans++;
	}
	printf("Character %c occured %d times\n",search,ans);
	return 0;
}