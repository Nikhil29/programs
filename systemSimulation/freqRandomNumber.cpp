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

int* freqMidSquareRandomGenerator(int seed, int modValue, int iter){
	int *freq = (int *)calloc(sizeof(int), modValue * sizeof(int));
	midSquareRandomNumber r = midSquareRandomNumber(seed);
	
	while(iter--){
		seed = r.rand() % modValue;
		freq[seed]++;
	}
	return freq;
}

int* freqResidueRandomGenerator(int a, int b, int modValue, int seed, int iter){
	int *freq = (int *)calloc(sizeof(int), modValue * sizeof(int));
	residueRandomNumber r = residueRandomNumber(seed, a, b, modValue);
	
	while(iter--){
		seed = r.rand();
		freq[seed]++;
		printf("%d\n", seed);
	}
	return freq;
}

int* freqArithmeticRandomGenerator(int modValue, int seed, int seed2, int iter){
	int *freq = (int *)calloc(sizeof(int), modValue * sizeof(int)), temp;
	arithmeticRandomNumber r =arithmeticRandomNumber(seed, seed2, modValue);
	
	while(iter--){
		seed = r.rand();
		freq[seed]++;
	}
	return freq;
}

int chiSquareForRandomNumber(int modValue, int iter, int freq[]){
	// find the chisquare
	// as all classes are of same interval length, thus the expected value will be 1/modValue
	// and observed value will be freq/iter for each class
	float chisquare = 0, expected, observed;
	for(int i=0; i<modValue; i++){
		expected = 1.00/modValue;
		observed = 1.00*freq[i]/iter;
		chisquare += (observed - expected)*(observed - expected)/(expected);
	}
	printf("Chi Square: %f\n", chisquare);

	// degree of freedom is no of classes-1
	// value from chart at degree of freedom
	int degOfFree = modValue-1;
	float val = 16.919;
	if(chisquare<val){
		printf("Chi Square Test: Acceptable\n");
		return 1;
	}
	else{
		printf("Chi Square Test: Not Acceptable\n");
		return 0;
	}
}

float positive(float x){
	if(x<0)
		return -1*x;
	return x;
}

int kolmogorovSmirmovTestForRandomNumber(int modValue, int iter, int freq[]){
	// Dcal = find the max of positive(cummulative(observed)-cummulative(expected))
	// Dexp = 1.36 / (n^0.5)
	// at significance level 0.05 => n > 35

	float Dcal = 0, Dexp, cumObserved=0, cumExpected=0;
	for(int i=0;i<modValue;i++){
		cumExpected += 1.00/modValue;
		cumObserved += 1.00*freq[i]/iter;
		if(positive(cumObserved - cumExpected) > Dcal)
			Dcal = positive(cumObserved - cumExpected);
	}

	Dexp = 1.36 / pow(35, 0.5);
	printf("Dcal = %f\nDexp = %f\n", Dcal, Dexp);

	// if Dcal<Dexp => accepted
	if(Dcal<Dexp){
		printf("Kolmogorov Smirmov Test: Acceptable\n");
		return 1;		
	}
	else{
		printf("Kolmogorov Smirmov Test: Not Acceptable\n");
		return 0;
	}
}

int main(){
	srand(time(NULL));
	int modValue=10, iter=100, option, run=1, *freq;
	
	while(run){
		printf("\nPress 1 to use Mid Square Method\nPress 2 to use Residue Method\nPress 3 to use Arithmetic Generator\nPress 0 to stop\n");
		scanf("%d", &option);

		switch(option){
			case 1:
				// find the frequencies
				freq = freqMidSquareRandomGenerator(rand(), modValue, iter);
				for(int i=0;i<modValue;i++){
					printf("Freq %d: %d\n", i, freq[i]);
				}
				break;
			case 2:
				// find the frequencies
				freq = freqResidueRandomGenerator(rand(), rand(), modValue, rand(), iter);
				for(int i=0;i<modValue;i++){
					printf("Freq %d: %d\n", i, freq[i]);
				}
				break;
			case 3:
				// find the frequencies
				freq = freqArithmeticRandomGenerator(modValue, rand(), rand(), iter);
				for(int i=0;i<modValue;i++){
					printf("Freq %d: %d\n", i, freq[i]);
				}
				break;
			case 0:
				run=0;
		}

		if(run){
			// chisquare for random number classes
			chiSquareForRandomNumber(modValue, iter, freq);

			// kolmogorov Smirmov Test for random number classes
			kolmogorovSmirmovTestForRandomNumber(modValue, iter, freq);
		}
	}
	return 0;
}