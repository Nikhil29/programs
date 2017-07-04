#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int main(){
	srand(time(NULL));

	int a, b;
	printf("Enter the values of a & b\n");
	scanf("%d%d", &a, &b);

	double x, y;
	while(1){
		y = 1.00 * rand() / RAND_MAX;
		x = y * (b - a) + a;
		printf("%lf => %lf\n", y, x);
		sleep(1);
	}
	return 0;
}