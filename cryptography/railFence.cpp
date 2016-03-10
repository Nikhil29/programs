// To encrypt the text using RailFence Technique

#include<bits/stdc++.h>
using namespace std;

// Encrypt using Rail fence
char* railFenceEncrypt(char input[], int noRails){
	int i,j,dist[2],inputLen=strlen(input),distIndex,outputIndex;
	char *output=(char *)malloc((inputLen+1)*sizeof(char));
	
	outputIndex=0;
	for(i=0;i<noRails;i++){
		// find the distances of next character in a rail
		dist[0]=2*(noRails-i-1);
		dist[1]=2*(i);
		if(i==0||i==noRails-1){
			dist[0]=2*(noRails-1);
			dist[1]=2*(noRails-1);
		}

		// put the input string in the rails according to the distance space
		j=i;
		distIndex=0;
		while(j<inputLen){
			output[outputIndex]=input[j];
			outputIndex++;
			j=j+dist[distIndex];
			distIndex=(distIndex+1)%2;
		}
	}
	output[outputIndex]='\0';
	return output;
}

// Decrypt Text using RailFence
char* railFenceDecrypt(char input[],int noRails){
	int i,j,inputLen=strlen(input),inputIndex=0,dist[2],distIndex;
	char *output=(char *)malloc((inputLen+1)*sizeof(char));

	for(i=0;i<noRails;i++){
		// find the distances of next character in a rail
		dist[0]=2*(noRails-i-1);
		dist[1]=2*(i);
		if(i==0||i==noRails-1){
			dist[0]=2*(noRails-1);
			dist[1]=2*(noRails-1);
		}

		// get the output string by traversing the rails
		j=i;
		distIndex=0;
		while(j<inputLen){
			output[j]=input[inputIndex];
			inputIndex++;
			j=j+dist[distIndex];
			distIndex=(distIndex+1)%2;
		}
	}
	output[inputIndex]='\0';
	return output;
}

// Encrypt Text using Rail fence in 2d
char* railFenceEncryptWith2d(char input[],int noRails){
	int i,j,inputLen=strlen(input),inputIndex,outputIndex;
	int railMatrix[noRails][inputLen+1];
	char *output=(char *)calloc(sizeof(char),(inputLen+1));
	memset(railMatrix, 0, sizeof(int)*(inputLen+1)*noRails);

	// put the input string in the 2d matrix
	inputIndex=0;
	while(inputIndex<inputLen){
		for(i=0;i<noRails&&inputIndex<inputLen;i++){
			railMatrix[i][inputIndex]=input[inputIndex];
			inputIndex++;
		}
		for(i=noRails-2;i>0&&inputIndex<inputLen;i--){
			railMatrix[i][inputIndex]=input[inputIndex];
			inputIndex++;
		}
	}

	// read the matrix row-wise to get the encrypted text
	outputIndex=0;
	for(i=0;i<noRails;i++){
		for(j=0;j<inputLen;j++){
			if(railMatrix[i][j]!=0){
				output[outputIndex]=railMatrix[i][j];
				outputIndex++;
			}
		}
	}
	output[outputIndex]='\0';
	return output;
}

// Decrypt Text using RailFence in 2d
char* railFenceDecryptWith2d(char input[],int noRails){
	int i,j,inputLen=strlen(input),inputIndex,outputIndex;
	int railMatrix[noRails][inputLen+1];
	char *output=(char *)calloc(sizeof(char),(inputLen+1));
	memset(railMatrix, 0, sizeof(int)*(inputLen+1)*noRails);

	// make the pattern i.e. mark the places where character will be written
	inputIndex=0;
	while(inputIndex<inputLen){
		for(i=0;i<noRails&&inputIndex<inputLen;i++){
			railMatrix[i][inputIndex]=1;
			inputIndex++;
		}
		for(i=noRails-2;i>0&&inputIndex<inputLen;i--){
			railMatrix[i][inputIndex]=1;
			inputIndex++;
		}
	}

	// put the text at the marked places in the matrix row-wise
	inputIndex=0;
	for(i=0;i<noRails;i++){
		for(j=0;j<inputLen;j++){
			if(railMatrix[i][j]!=0){
				railMatrix[i][j]=input[inputIndex];
				inputIndex++;
			}
		}
	}

	// read column-wise to get the decrypted text
	outputIndex=0;
	while(outputIndex<inputLen){
		for(i=0;i<noRails&&outputIndex<inputLen;i++){
			output[outputIndex]=railMatrix[i][outputIndex];
			outputIndex++;
		}
		for(i=noRails-2;i>0&&outputIndex<inputLen;i--){
			output[outputIndex]=railMatrix[i][outputIndex];
			outputIndex++;
		}
	}
	output[outputIndex]='\0';
	return output;
}

int main(){
	int noRails;
	char input[1000],*encryptText,*decryptText;

	// input
	printf("Enter the number of rails: ");
	scanf("%d",&noRails);
	printf("Enter the text to be encrypted: ");
	scanf("%s",input);

	// Using 1d array in encryption and decryption function
	encryptText=railFenceEncrypt(input,noRails);
	printf("Encrypted Text: %s\n",encryptText);

	decryptText=railFenceDecrypt(encryptText,noRails);
	printf("Decrypted Text: %s\n",decryptText);

	// free the allocated dynamic memory
	free(encryptText);
	free(decryptText);
	
	// Using 2d array in encryption and decryption function
	encryptText=railFenceEncryptWith2d(input,noRails);
	printf("Encrypted Text with 2d matrix: %s\n",encryptText);

	decryptText=railFenceDecryptWith2d(encryptText, noRails);
	printf("Decrypted Text with 2d matrix: %s\n",decryptText);

	// free the allocated dynamic memory
	free(encryptText);
	free(decryptText);
	return 0;
}