#include<bits/stdc++.h>
using namespace std;
#define MAXCLUS 1000

int main(){
	srand(time(NULL));

	// input the objects
	int noObj, noAttr, noClus, noIter;
	printf("Enter the number of objects: ");
	scanf("%d", &noObj);
	printf("Enter the number of attributes: ");
	scanf("%d", &noAttr);

	int obj[noObj][noAttr];
	printf("Enter the attributes of objects:\n");
	for(int i = 0; i < noObj; i++){
		for(int j = 0;j < noAttr; j++){
			scanf("%d", &obj[i][j]);
		}
	}

	printf("Enter the number of clusters: ");
	scanf("%d",&noClus);
	float centrClus[noClus][noAttr];
	// objects in each cluster
	vector<int> clus[MAXCLUS];

	printf("Enter the number of iterations: ");
	scanf("%d",&noIter);

	// random clusters
	for(int i=0;i<noClus;i++){
		int tempObj = rand()%noObj;
		for(int j=0;j<noAttr;j++){
			centrClus[i][j] = obj[tempObj][j];
		}
	}

	for(int t=0;t<noIter;t++){
		// clear the clusters
		for(int i=0;i<noClus;i++){
			clus[i].clear();
		}

		// put the objects in clusters
		for(int i=0;i<noObj;i++){
			float minDist = 1000000, dist;
			int clusIndex;
			for(int j=0;j<noClus;j++){

				// dist of obj[i] with clus[j]
				dist = 0;
				for(int k=0;k<noAttr;k++){
					dist += (obj[i][k]-centrClus[j][k])*(obj[i][k]-centrClus[j][k]);
				}

				// printf("%f\n", dist);
				if(dist<minDist){
					minDist = dist;
					clusIndex = j;
				}
			}
			clus[clusIndex].push_back(i);
		}

		// get the new cluster centers
		for(int i=0;i<noClus;i++){
			for(int k=0;k<noAttr;k++){
				float temp=0;
				for(int j=0;j<clus[i].size();j++){
					temp += obj[clus[i][j]][k];
				}
				if(clus[i].size()!=0)
					centrClus[i][k] = temp/clus[i].size();
			}
		}
	}

	// print the clusters
	printf("Center of clusters:\n");
	for(int i=0;i<noClus;i++){
		for(int j=0;j<noAttr;j++){
			printf("%f ", centrClus[i][j]);
		}
		printf("\n");
	}
	return 0;
}