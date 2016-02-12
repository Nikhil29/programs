#include<bits/stdc++.h>
using namespace std;

int linearsearch(int array[],int start, int end, int search)
{
	int i;
	for(i=start;i<=end;i++){
		if(array[i]==search)
			break;
	}
	if(i<=end)
		return i;
	else
		return -1;
}

int main()
{
	int array[1000],n,search,i;
	
	//input of array
	printf("Enter the number of integers in array\n");
	scanf("%d",&n);
	printf("Enter the elements of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	
	//get query and output the result
	while(1){
		printf("Press 0 to stop. Enter the element you want search:\n");
		scanf("%d",&search);
		if(search==0)
			break;

		i = linearsearch(array,0,n-1,search);
		
		if(i==-1)
			printf("Element %d not found\n",search);
		else
			printf("Element %d found at %d index\n",search,i);
	}
	return 0;
}