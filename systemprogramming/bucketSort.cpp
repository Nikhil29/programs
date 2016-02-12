#include<bits/stdc++.h>
using namespace std;
#define NO_OF_BUCKET 100000
#define BUCKET_SIZE 1000

int bucketsort(int array[],int start,int end){
	vector<int> buckets[NO_OF_BUCKET];
	int i,j,k,size;

	//push the elements of array to appropriate bucket
	for(i=start;i<=end;i++){
		buckets[array[i]/BUCKET_SIZE].push_back(array[i]);
	};

	//sort each bucket by inbuilt sort function
	for(i=0;i<NO_OF_BUCKET;i++){
		sort(buckets[i].begin(),buckets[i].end());
	}

	//update the array with sorted array
	k=start;
	for(i=0;i<NO_OF_BUCKET;i++){
		size=buckets[i].size();
		for(j=0;j<size;j++){
			array[k]=buckets[i][j];
			k++;
		}
	}

	return 0;
}

int main()
{
	int n,i,temp,array[1000];
	float arrayfloat[1000];

	//input
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&arrayfloat[i]);
		array[i]=arrayfloat[i]*10000;
	}

	//sort
	bucketsort(array,0,n-1);
	
	//print sorted array
	printf("Sorted Array: ");
	for(i=0;i<n;i++)
	{
		arrayfloat[i]=1.00*array[i]/10000;
		printf("%f ",arrayfloat[i]);
	}
	printf("\n");
	
	return 0;
}