#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int main(){
	srand(time(NULL));

	int mu;
	printf("Enter the values of mu\n");
	scanf("%d", &mu);

	double x, y;
	while(1){
		y = 1.00 * rand() / RAND_MAX;
		x = -1.00 / mu * log(1-y);
		printf("%lf => %lf\n", y, x);
		sleep(1);
	}
	return 0;
}