#include<bits/stdc++.h>
using namespace std;

float mean(vector<int> data, int n){
	float meanValue=0;
	for(int i=0;i<n;i++){
		meanValue += data[i];
	}
	meanValue /= n;
	return meanValue;
}

int median(vector<int> data, int n){
	if(n==0)
		return -1;

	int medianValue;
	sort(data.begin(), data.end());
	medianValue = data[n/2];
	return medianValue;
}

int mode(vector<int> data, int n){
	map<int, int> freq;
	int modeValue=-1, maxFreq=0;

	for(int i=0;i<n;i++){
		if(freq.find(data[i])==freq.end()){
			freq[data[i]]=1;
		}
		else{
			freq[data[i]]++;
		}

		if(freq[data[i]]>maxFreq){
			maxFreq=freq[data[i]];
			modeValue=data[i];
		}
	}

	return modeValue;
}

int main(){
	int n, tmp;
	vector<int> data;

	printf("Enter the number of elements: ");
	scanf("%d",&n);

	printf("Enter the elements:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		data.push_back(tmp);
	}

	printf("Mean: %f\n", mean(data, n));
	printf("Median: %d\n", median(data, n));
	printf("Mode: %d\n", mode(data, n));
	return 0;
}