#include<bits/stdc++.h>
using namespace std;

int binarysearch(int array[],int start, int end, int search)
{
	if(start>end)
		return -1;

	int mid=(start+end)/2;
	
	if(array[mid]==search)
		return mid;
	else if(array[mid]>search)
		return binarysearch(array, start, mid-1, search);
	else
		return binarysearch(array, mid+1, end, search);
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

	//sort if the array is not sorted
	sort(array, array+n);
	
	//input query and display output
	while(1){
		printf("Press 0 to stop. Enter the element you want search:\n");
		scanf("%d",&search);
		if(search==0)
			break;

		i = binarysearch(array,0,n-1,search);
		
		if(i==-1)
			printf("Element %d not found\n",search);
		else
			printf("Element %d found at %d index\n",search,i);
	}
	return 0;
}