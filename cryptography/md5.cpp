#include <bits/stdc++.h>
using namespace std;

// this program doesnot add message length when doing padding

unsigned int pFunction(unsigned int b,unsigned int c,unsigned int d, int round){
	switch(round){
		case 1:
			return (b&c)|((!b)&d);
		case 2:
			return (b&c)|(c&(!d));
		case 3:
			return b^c^d;
		case 4:
			return c^(b|(!d));
		default:
			printf("Illegal round\n");
			return -1;
	}
}

unsigned int leftCircularShift(unsigned int x, int shift){
	return (x<<shift) + (x>>(32-shift));
}

bool* convertToBitWise(char message[], unsigned int bitMessageSize){
	int count=0,temp;
	bool *bitMessage=(bool *)malloc(bitMessageSize);
	for(int i=0;message[i]!='\0';i++){
		temp = message[i];
		for(int j=7;j>=0;j--){
			bitMessage[count+j]=temp%2;
			temp=temp/2;
		}
		count+=8;
	}
	return bitMessage;
}

unsigned int bitToUnsignedInt(bool *bitMessage){
	unsigned int temp=0;
	for(int i=0;i<32;i++){
		temp=temp*2+bitMessage[i];
	}
	return temp;
}

bool* doPadding(bool bitMessage[], unsigned int *bitMessageSize){
	int padddingSize=512-(*bitMessageSize+64)%512;
	bitMessage=(bool *)realloc(bitMessage, (*bitMessageSize)+padddingSize+64 );
	memset(bitMessage+(*bitMessageSize), 0, padddingSize);
	bitMessage[*bitMessageSize]=1;
	*bitMessageSize=(*bitMessageSize)+padddingSize+64;
	return bitMessage;
}

int main(){
	bool *bitMessage;
	char message[1000];
	unsigned int bitMessageSize, noOfMessageBlock;
	unsigned int A=0x67452301, B=0xefcdab89, C=0x98badcfe, D=0x10325476, a=0, b=0, c=0, d=0, temp;
	unsigned int shift[4][4]={{7,12,17,22},{5,9,14,20},{4,11,16,23},{6,10,15,21}};		
	unsigned int t[64];

	// initialise t array
	long long int maxUnsignedInt=(long long int)pow(2,32);
	for(int i=0;i<64;i++)
		t[i] = floor(maxUnsignedInt * fabs(sin(i + 1)));

	// get the input and convert in bit form
	printf("Enter the message: ");
	scanf("%s",message);
	bitMessageSize=strlen(message)*8;
	printf("Message Size in bits: %u\n", bitMessageSize);
	bitMessage=convertToBitWise(message, bitMessageSize);
	bitMessage=doPadding(bitMessage, &bitMessageSize);
	printf("Final Message Size after Padding: %u\n", bitMessageSize);

	// find the message digest
	noOfMessageBlock=bitMessageSize/512;
	for(int i=0;i<noOfMessageBlock;i++){
		//  initialise variable for this message block
		a=A;
		b=B;
		c=C;
		d=D;

		// 4 rounds
		for(int round=1;round<=4;round++){
			for(int iter=0;iter<16;iter++){
				temp=pFunction(b, c, d, round);
				temp+=a;
				temp+=bitToUnsignedInt(bitMessage+i*512+iter*32);
				temp+=t[(round-1)*16+iter];
				temp=leftCircularShift(temp, shift[round-1][iter%4]);
				temp+=b;
				a=d;
				d=c;
				c=b;
				b=temp;
			}
		}

		// update chaining variable for next message block
		A=A+a;
		B=B+b;
		C=C+c;
		D=D+d;
	}

	printf("Final Chaining Variables: \n");
	printf("\tA = %x\n\tB = %x\n\tC = %x\n\tD = %x\n",a,b,c,d);
	return 0;
}