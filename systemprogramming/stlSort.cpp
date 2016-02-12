#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,temp;
	vector<int> myvector;

	// input
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements of myvector\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		myvector.push_back(temp);
	}

	// sort
	sort(myvector.begin(), myvector.end());
	
	// output
	printf("Sorted myvector: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",myvector[i]);
	}
	printf("\n");
	return 0;
}