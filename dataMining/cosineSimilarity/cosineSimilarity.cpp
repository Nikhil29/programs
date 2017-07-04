#include<bits/stdc++.h>
using namespace std;

int cosSimilarity(int n, int x[], int y[]){
	float cos=0, xnorm=0, ynorm=0;
	for(int i=0;i<n;i++){
		cos += x[i]*y[i];
	}

	for(int i=0;i<n;i++){
		xnorm += x[i]*x[i];
		ynorm += y[i]*y[i];
	}

	cos = cos/sqrt(xnorm)/sqrt(ynorm);
	printf("Cosine Similarity: %f\n", cos);
	return cos;
}

int main(){
	FILE *f1 = fopen("doc1", "r");
	FILE *f2 = fopen("doc2", "r");

	char doc1[100][100], doc2[100][100], final[100][100];
	int no1, no2;

	no1=0;
	while(1){
		if(fscanf(f1, "%s", doc1[no1])==-1)
			break;
		no1++;
	}

	no2=0;
	while(1){
		if(fscanf(f2, "%s", doc2[no2])==-1)
			break;
		no2++;
	}

	// int pos=0;
	// for(int i=0;i<min(no1, no2);i++){
	// 	if(strcmp(doc1[i], doc2[i])==0)
	// 		pos++;
	// }

	// printf("%f\n", 1.00*pos/min(no1, no2));

	int noFin=0;
	for(int i=0;i<no1;i++){
		int j;
		for(j=0;j<noFin;j++){
			if(strcmp(doc1[i], final[j])==0)
				break;
		}
		if(j==noFin)
			strcpy(final[noFin++], doc1[i]);
	}

	int freqDoc1[100], freqDoc2[100];
	for(int i=0;i<100;i++){
		freqDoc2[i]=0;
		freqDoc1[i]=0;
	}

	for(int i=0;i<no1;i++){
		for(int j=0;j<noFin;j++){
			if(strcmp(doc1[i], final[j])==0){
				freqDoc1[j]++;
				break;
			}
		}
	}	
	for(int i=0;i<no2;i++){
		for(int j=0;j<noFin;j++){
			if(strcmp(doc2[i], final[j])==0){
				freqDoc2[j]++;
				break;
			}
		}
	}	

	for(int i=0;i<noFin;i++){
		printf("%s => ", final[i]);
		printf("%d %d\n", freqDoc1[i], freqDoc2[i]);
	}

	cosSimilarity(noFin, freqDoc1, freqDoc2);
	return 0;
}