#include<bits/stdc++.h>
using namespace std;
#define MAX_NO_OF_DIGITS 5

int radixsort(int array[],int start,int end){
	int i,j,digit_place=1,k,size,temp;

	while(digit_place<=MAX_NO_OF_DIGITS){
		vector<int> digit[10];

		// insert the element according to its value at digit_place.
		for(i=start;i<=end;i++){
			temp=int(((array[i]%(int)(pow(10,digit_place)))/pow(10,digit_place-1)));
			digit[temp].push_back(array[i]);
		} 

		// update the array according to the sorting based on digit_place digit 
		k=start;
		for(i=0;i<10;i++){
			size=digit[i].size();
			for(j=0;j<size;j++){
				array[k]=digit[i][j];
				k++;
			}
		}
		digit_place++;
	}
	return 0;
}

int main()
{
	int n,i,temp,array[1000];

	// input
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}

	// sort
	radixsort(array,0,n-1);
	
	// print sorted array
	printf("Sorted Array: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}