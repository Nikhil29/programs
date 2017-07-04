#include<bits/stdc++.h>
using namespace std;

class midSquareRandomNumber{
	int seed;

public: 
	midSquareRandomNumber(){
		seed = time(NULL);
	}
	midSquareRandomNumber(int seed){
		this->seed = seed;
	}

	void srand(int seed){
		this->seed = seed;		
	}

	int rand(){
		seed = (((long long int)seed*seed) / 100) % 10000;
		return seed;
	}
};

class residueRandomNumber{
	int seed, a, b, mod;

public: 
	residueRandomNumber(){
		seed = time(NULL);
		a = 1103515245;
		b = 12345;
		mod = 32768;
	}
	residueRandomNumber(int seed, int a, int b, int modValue){
		this->seed = seed;
		this->a = a;
		this->b = b;
		this->mod = modValue;
	}

	void srand(int seed){
		this->seed = seed;		
	}

	int rand(){
		seed = ((long long int)a*seed + b) % mod;
		return seed;
	}
};

class arithmeticRandomNumber{
	int seed, seed2, mod;

public: 
	arithmeticRandomNumber(){
		seed = time(NULL) % 32768;
		seed2 = (time(NULL) * 1103515245 + 12345) % 32768;
		mod = 32768;
	}
	arithmeticRandomNumber(int seed, int seed2, int modValue){
		this->seed = seed;
		this->seed2 = seed2;
		this->mod = modValue;
	}

	void srand(int seed, int seed2){
		this->seed = seed;
		this->seed2 = seed2;		
	}

	int rand(){
		int temp;
		temp = (seed + seed2) % mod;
		seed2 = seed;
		seed = temp;
		return seed;
	}
};

int main(){
	int option, modValue, result, a, b, seed, seed2, run, type;

	printf("\nPress 1 to use Mid Square Method\nPress 2 to use Residue Method\nPress 3 to use Arithmetic Generator\n");
	scanf("%d", &option);

	switch(option){
		case 1:
			{
				midSquareRandomNumber mid = midSquareRandomNumber();
				printf("Enter the 4 digit number as seed or press -1 for time as seed\n");
				scanf("%d", &seed);
				if(seed != -1)
					mid.srand(seed);
				
				run = 0;
				while(run==0){
					result = mid.rand();
					printf("Next Random Number is %d\n", result);
					printf("Press 0 for next random Number: ");
					scanf("%d", &run);
				}
				break;
			}

		case 2:
			{
				printf("Enter the type of residue method:\n1 for additive\n2 for multiplicative\n3 for mixed\n");
				scanf("%d", &type);
				switch(type){
					case 1:
						a=1;
						printf("Enter the values of b: ");
						scanf("%d", &b);
						printf("Enter the value of modulus: ");
						scanf("%d", &modValue);
						break;
					case 2:
						b=0;
						printf("Enter the values of a: ");
						scanf("%d", &a);
						printf("Enter the value of modulus: ");
						scanf("%d", &modValue);
						break;
					case 3:	
						printf("Enter the values of a & b: ");
						scanf("%d%d", &a, &b);
						printf("Enter the value of modulus: ");
						scanf("%d", &modValue);
						break;
					default:
						printf("Invalid Input\n");
				}


				if(type==1||type==2||type==3){
					printf("Enter the seed: ");
					scanf("%d", &seed);

					residueRandomNumber res = residueRandomNumber(seed, a, b, modValue);
					
					run = 0;
					while(run==0){
						result = res.rand();
						printf("Next Random Number is %d\n", result);
						printf("Press 0 for next random Number: ");
						scanf("%d", &run);
					}
				}
				break;
			}

		case 3:
			{
				printf("Enter the 2 seed values\n");
				scanf("%d %d", &seed, &seed2);
				printf("Enter the value of modulus: ");
				scanf("%d", &modValue);
				
				arithmeticRandomNumber ari = arithmeticRandomNumber(seed, seed2, modValue);

				run = 0;
				while(run==0){
					result = ari.rand();
					printf("Next Random Number is %d\n", result);
					printf("Press 0 for next random Number: ");
					scanf("%d", &run);
				}
				break;
			}
	}
	return 0;
}