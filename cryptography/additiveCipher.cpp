// To encrypt the text using additive cipher Technique

#include<bits/stdc++.h>
using namespace std;

// Encrypt using additive cipher
char* additiveCipherEncrypt(char input[], int key){
	int i,inputLen=strlen(input);
	char *output=(char *)malloc((inputLen+1)*sizeof(char));
	
	for(i=0;i<inputLen;i++){
		output[i]=(input[i]-97+key)%26+97;
	}
	output[i]='\0';
	return output;
}

// Decrypt Text using additive cipher
char* additiveCipherDecrypt(char input[],int key){
	int i,inputLen=strlen(input);
	char *output=(char *)malloc((inputLen+1)*sizeof(char));

	for(i=0;i<inputLen;i++){
		output[i]=(input[i]-97-key+26)%26+97;
	}
	output[i]='\0';
	return output;
}

int main(){
	int key;
	char input[1000],*encryptText,*decryptText;

	// input
	printf("Enter the text to be encrypted: ");
	scanf("%s",input);
	printf("Enter the key for encryption: ");
	scanf("%d",&key);

	// encryption and decryption function
	encryptText=additiveCipherEncrypt(input,key);
	printf("Encrypted Text: %s\n",encryptText);

	decryptText=additiveCipherDecrypt(encryptText,key);
	printf("Decrypted Text: %s\n",decryptText);

	// free the allocated dynamic memory
	free(encryptText);
	free(decryptText);
	return 0;
}