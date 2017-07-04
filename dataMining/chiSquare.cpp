#include<bits/stdc++.h>
using namespace std;

int main(){
	int noClassA, noClassB;

	printf("Enter the no of classes of A: ");
	scanf("%d",&noClassA);
	printf("Enter the no of classes of B: ");
	scanf("%d",&noClassB);

	float obsmat[noClassA][noClassB], totalA[noClassA], totalB[noClassB], expmat[noClassA][noClassB], total=0, ans;

	printf("Enter the observed values\n");
	for(int i=0;i<noClassA;i++){
		for(int j=0;j<noClassB;j++){
			scanf("%f",&obsmat[i][j]);
			total +=obsmat[i][j];
		}
	}

	for(int i=0;i<noClassA;i++){
		totalA[i]=0;
		for(int j=0;j<noClassB;j++){
			totalA[i] += obsmat[i][j];
		}
	}

	for(int j=0;j<noClassB;j++){
		totalB[j]=0;
		for(int i=0;i<noClassA;i++){
			totalB[j] += obsmat[i][j];
		}
	}

	for(int i=0;i<noClassA;i++){
		for(int j=0;j<noClassB;j++){
			expmat[i][j]=totalA[i]*totalB[j]/total;
		}
	}

	ans=0;
	for(int i=0;i<noClassA;i++){
		for(int j=0;j<noClassB;j++){
			ans += (obsmat[i][j]-expmat[i][j])*(obsmat[i][j]-expmat[i][j])/expmat[i][j];
		}
	}

	printf("%f\n", ans);
	return 0;
}