// To encrypt the text using multiplicative cipher Technique

#include<bits/stdc++.h>
using namespace std;

// gcd function
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

// extended eulcidean
pair<int,int> extendedeuclidean(int r1,int r2,int s1,int s2,int t1,int t2){
	if(r2==0){
		pair<int,int> x;
		x.first = s1;
		x.second = t1;
		return x;
	}
	return extendedeuclidean(r2, r1%r2, s2, s1-r1/r2*s2, t2, t1-r1/r2*t2);
}

// multiplicative inverse returns -1 if it doesnot exist
int multiplicativeInverse(int a,int n){
	int inverse;
	if(gcd(n,a)==1){
		inverse=(extendedeuclidean(a,n,1,0,0,1).first)%n;
		if(inverse<0){
			inverse=inverse+n;
		}
		return inverse;
	}
	else{
		return -1;
	}
}

// Encrypt using multiplicative cipher
char* multiplicativeCipherEncrypt(char input[], int key){
	int i,inputLen=strlen(input);
	char *output=(char *)malloc((inputLen+1)*sizeof(char));
	
	// encryption
	for(i=0;i<inputLen;i++){
		output[i]=((input[i]-97)*key)%26+97;
	}
	output[i]='\0';
	return output;
}

// Decrypt Text using multiplicative cipher
char* multiplicativeCipherDecrypt(char input[],int key){
	int i, inputLen=strlen(input), keyInverse;
	char *output=(char *)malloc((inputLen+1)*sizeof(char));

	// find the inverse key
	keyInverse=multiplicativeInverse(key, 26);

	// decryption
	for(i=0;i<inputLen;i++){
		output[i]=((input[i]-97)*keyInverse)%26+97;
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
	if(gcd(key, 26)!=1){
		printf("key cannot be used for encryption\n");
		return 0;
	}

	// encryption and decryption function
	encryptText=multiplicativeCipherEncrypt(input,key);
	printf("Encrypted Text: %s\n",encryptText);

	decryptText=multiplicativeCipherDecrypt(encryptText,key);
	printf("Decrypted Text: %s\n",decryptText);

	// free the allocated dynamic memory
	free(encryptText);
	free(decryptText);
	return 0;
}