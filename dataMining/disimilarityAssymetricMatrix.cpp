#include<bits/stdc++.h>
using namespace std;

int main(){
	int noObj, noAttr, disMatch, bothZero;
	
	printf("Enter the number of objects: ");
	scanf("%d", &noObj);

	printf("Enter the number of attributes: ");
	scanf("%d", &noAttr);

	int obj[noObj][noAttr];
	float dis[noObj][noObj];
	
	printf("Enter the attributes of objects:\n");
	for(int i = 0; i < noObj; i++){
		for(int j = 0;j < noAttr; j++){
			scanf("%d", &obj[i][j]);
		}
	}

	for(int i = 0; i < noObj; i++){
		for (int j = 0; j < noObj; j++){
			disMatch=0;
			bothZero=0;
			for(int k = 0; k < noAttr; k++){
				if(obj[i][k]!=obj[j][k])
					disMatch++;
				if(obj[i][k]==0&&obj[j][k]==0)
					bothZero++;
			}
			dis[i][j] = 1.00*disMatch/(noAttr-bothZero);
		}
	}

	printf("Dissimilarity Matrix:\n");
	for (int i = 0; i < noObj; ++i){
		for (int j = 0; j < noObj; ++j){
			printf("%.2f ", dis[i][j]);
		}
		printf("\n");
	}
}