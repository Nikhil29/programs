#include<bits/stdc++.h>
using namespace std;

// positive lower and upper limits
double integralXCube(double lowLimit, double upLimit, int iter){
	srand(time(NULL));

	double lowValue = lowLimit * lowLimit * lowLimit;
	double upValue = upLimit * upLimit * upLimit;
	int total=iter, inside=0;
	double x, y;

	while(iter--){
		x = 1.00 * rand() / RAND_MAX * (upLimit - lowLimit) + lowLimit;
		y = 1.00 * rand() / RAND_MAX * (upValue);
		if(y <= x*x*x){
			inside++;
		}
	}

	return 1.00 * inside / total * (upLimit - lowLimit) * (upValue);
}

int main(){
	int lowLimit, upLimit, iter;
	
	printf("Enter the positive lower and upper limit for x^3 integral\n");
	scanf("%d%d", &lowLimit, &upLimit);

	printf("Enter the no of iterations: \n");
	scanf("%d", &iter);

	printf("Integral of x^3 from %d to %d: %lf\n", lowLimit, upLimit, integralXCube(lowLimit, upLimit, iter));
}