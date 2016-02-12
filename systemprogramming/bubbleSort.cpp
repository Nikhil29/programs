#include<bits/stdc++.h>
using namespace std;

int bubblesort(int array[],int start,int end)
{
	int i,j,temp;
	for(i=start;i<=end;i++)
	{
		for(j=start;j<end-i;j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	return 0;
}

int main()
{
	int n,i,temp,array[1000];

	//input
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}

	//sort
	bubblesort(array,0,n-1);
	
	//print output array
	printf("Sorted Array: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}