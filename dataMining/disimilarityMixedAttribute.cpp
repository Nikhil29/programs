#include<bits/stdc++.h>
using namespace std;

float mod(float x){
	if(x<0)
		return -x;
	return x;
}

float dissimilarityMixed(int i, int j, int noObj, int noAttr, int attr[], int obj[][1000]){
	float ans, delf, df, numerAns=0, denomAns=0, min, max, zi, zj;
	
	for(int f=0;f<noAttr;f++){
		// del f is 0 if an attribute value is not present depicted here by -1 or if attribute is asymetric binarty if attribute value for both objects is 0
		if((obj[i][f]==-1||obj[j][f]==-1)||(attr[f]==2&&obj[i][f]==0&&obj[j][f]==0)){
			delf=0;
		}
		else{
			delf=1;
		}

		switch(attr[f]){
			case 1:
				max=-100000;
				min=100000;
				for(int temp=0;temp<noObj;temp++){
					if(obj[temp][f]>max)
						max=obj[temp][f];
					if(obj[temp][f]<min)
						min=obj[temp][f];
				}

				df=mod(obj[i][f]-obj[j][f])/(max-min);
				break;

			case 2:
				if(obj[i][f]==obj[j][f])
					df=0;
				else
					df=1;
				break;
			case 3:
				if(obj[i][f]==obj[j][f])
					df=0;
				else
					df=1;
				break;
			case 4:
				max=-100000;
				for(int temp=0;temp<noObj;temp++){
					if(obj[temp][f]>max)
						max=obj[temp][f];
				}	

				zi = (obj[i][f]-1)/(max-1);
				zj = (obj[j][f]-1)/(max-1);

				df = mod(zi-zj)/(max-1);			
				break;
		}

		numerAns += delf*df;
		denomAns += delf;
	}

	ans = numerAns/denomAns;
	return ans ;
}

int main(){
	int noObj, noAttr;

	printf("Enter the number of objects: ");
	scanf("%d",&noObj);

	printf("Enter the number of Attributes: ");
	scanf("%d",&noAttr);

	int attr[noAttr], obj[noObj][1000];
	float dis[noObj][1000];

	printf("Enter the type for each Attribute\n");
	printf("\tEnter 1 for Numerical\n\tEnter 2 for Assymetric Binary\n\tEnter 3 for Nominal\n\tEnter 4 for Ordinal\n");
	for(int i=0;i<noAttr;i++){
		scanf("%d",&attr[i]);
	}

	printf("Enter the Attribute values for each object:\n");
	for (int i = 0; i < noObj; ++i){
		for(int j=0;j<noAttr;j++){
			scanf("%d",&obj[i][j]);
		}
	}

	for(int i=0;i<noObj;i++){
		for(int j=0;j<noObj;j++){
			dis[i][j] = dissimilarityMixed(i, j, noObj, noAttr, attr, obj);
		}
	}

	printf("Dissimilarity Matrix: \n");
	for (int i=0; i<noObj; ++i){
		for(int j=0; j<noObj; j++){
			printf("%f ", dis[i][j]);
		}
		printf("\n");
	}
	return 0;
}