#include<bits/stdc++.h>
using namespace std;

//print function to display array
int print(int array[],int start,int end){
	int i;
	for(i=start;i<=end;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}

//returns the copy of array elemets
int* copy(int array[],int start,int end){
	int i,*copy_arr=(int *)malloc(sizeof(int)*(end-start+1));
	for(i=start;i<=end;i++){
		copy_arr[i-start]=array[i];
	}
	return copy_arr;
}

//merge the 2 sorted arrays
int merge(int array[],int start,int end,int firsthalf[],int secondhalf[]){

	int i=0,j=0,mid=(start+end)/2,sizefirst=mid-start+1,sizesecond=end-mid;
	int k=0,size=end-start;

	while(k!=size){
		if(i==sizefirst||j==sizesecond)
			break;
		if(firsthalf[i]>secondhalf[j]){
			array[start+k]=secondhalf[j];
			j++;
		}
		else{
			array[start+k]=firsthalf[i];
			i++;
		}
		k++;
	}

	while(i<sizefirst){
		array[start+k]=firsthalf[i];
		i++;
		k++;
	}
	
	while(j<sizesecond){
		array[start+k]=secondhalf[j];
		j++;
		k++;
	}
	return 0;
}

//main merge sort function
int mergesort(int array[],int start,int end){
	if(start>=end)
		return 0;
	int mid;
	mid=(start+end)/2;

	//sort the 2 sub-arrays
	mergesort(array,start,mid);
	mergesort(array,mid+1,end);

	//create the copy of 2 subarrays
	int *firsthalf=copy(array,start,mid);
	int *secondhalf=copy(array,mid+1,end);

	// merge them in the main array
	merge(array,start,end,firsthalf,secondhalf);

	//free the malloc memory allocated for copies.
	free(firsthalf);
	free(secondhalf);
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
	mergesort(array,0,n-1);

	//output array
	printf("Sorted Array: ");
	print(array,0,n-1);
	printf("\n");
	return 0;
}