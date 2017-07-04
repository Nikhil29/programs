#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	float meanA, meanB, stdDevA, stdDevB, karlPearson;

	printf("Enter the number of object: ");
	scanf("%d",&n);

	int a[n], b[n];
	printf("Enter the value of attributes of each object:\n");
	for(int i=0;i<n;i++){
		scanf("%d%d", &a[i], &b[i]);
	}

	meanA=0;
	meanB=0;
	for(int i=0;i<n;i++){
		meanA += a[i];
		meanB += b[i];
	}
	meanA /= n;
	meanB /= n;

	stdDevA=0;
	stdDevB=0;
	for(int i=0;i<n;i++){
		stdDevA += (a[i]-meanA)*(a[i]-meanA);
		stdDevB += (b[i]-meanB)*(b[i]-meanB);
	}
	stdDevA /= n;
	stdDevA = sqrt(stdDevA);
	stdDevB /= n;
	stdDevB = sqrt(stdDevB);

	karlPearson=0;
	for(int i=0;i<n;i++){
		karlPearson += (a[i]-meanA)*(b[i]-meanB);
	}
	karlPearson /= n;
	karlPearson /= stdDevA;
	karlPearson /= stdDevB;

	printf("Karl Pearson is %f\n", karlPearson);
	return 0;
}