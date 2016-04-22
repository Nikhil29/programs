// To encrypt the text using columnar Technique

#include<bits/stdc++.h>
using namespace std;

// Encrypt Text using columnar cipher
char* columnarEncrypt(char input[],int noCol, char key[]){
	int i, j, inputLen=strlen(input), outputIndex, keyIndex=-1, prevKey=-1, minKey, noRow;
	int colMatrix[inputLen+1][noCol];
	char *output=(char *)calloc(sizeof(char),(inputLen+1));
	memset(colMatrix, 0, sizeof(int)*(inputLen+1)*noCol);

	// fill the matrix with input
	for(i=0;i<inputLen;i++){
		colMatrix[i/noCol][i%noCol]=input[i];
	}
	noRow=i/noCol+1;
	for(j=i%noCol;j<noCol;j++){
		colMatrix[noRow-1][j]='z';
	}

	// fill the output array
	outputIndex=0;
	for(i=0;i<noCol;i++){
		minKey=1000;
		for(j=0;j<noCol;j++){
			if(key[j]<=prevKey)
				continue;
			if(key[j]<minKey){
				minKey=key[j];
				keyIndex=j;
			}
		}
		prevKey=minKey;
		for(j=0;j<noRow;j++){
			output[outputIndex]=colMatrix[j][keyIndex];
			outputIndex++;
		}
	}
	output[outputIndex]='\0';
	return output;
}

// Decrypt Text using columnar cipher
char* columnarDecrypt(char input[],int noCol, char key[]){
	int i, j, inputLen=strlen(input), inputIndex, keyIndex=-1, prevKey=-1, minKey, noRow;
	int colMatrix[inputLen+1][noCol];
	noRow=inputLen/noCol;
	char *output=(char *)calloc(sizeof(char),(noRow*noCol)+1);
	memset(colMatrix, 0, sizeof(int)*(inputLen+1)*noCol);

	// fill the matrix
	inputIndex=0;
	for(i=0;i<noCol;i++){
		minKey=1000;
		for(j=0;j<noCol;j++){
			if(key[j]<=prevKey)
				continue;
			if(key[j]<minKey){
				minKey=key[j];
				keyIndex=j;
			}
		}
		prevKey=minKey;
		for(j=0;j<noRow;j++){
			colMatrix[j][keyIndex]=input[inputIndex];
			inputIndex++;
		}
	}

	// fill the output matrix
	for(i=0;i<noRow*noCol;i++){
		output[i]=colMatrix[i/noCol][i%noCol];
	}
	output[i]='\0';
	return output;
}

int main(){
	int noCol;
	char input[1000],*encryptText,*decryptText,key[1000];

	// input
	printf("Enter the number of columns: ");
	scanf("%d",&noCol);
	printf("Enter the key string of length as no of colums: ");
	scanf("%s", key);
	if(strlen(key)!=noCol){
		printf("Key length is not equal to number of columns\n");
		return 0;
	}
	printf("Enter the text to be encrypted: ");
	scanf("%s",input);

	// Using encryption and decryption function
	encryptText=columnarEncrypt(input, noCol, key);
	printf("Encrypted Text: %s\n",encryptText);

	decryptText=columnarDecrypt(encryptText, noCol, key);
	printf("Decrypted Text: %s\n",decryptText);

	// free the allocated dynamic memory
	free(encryptText);
	free(decryptText);
	return 0;
}