#include<bits/stdc++.h>
using namespace std;
#define MAXITEMS 1000

// print the frequent Item set
void print(vector<vector<int> > freq){
	vector<int> v;
	printf("Print freq Item Set:\n");
	for(int i=0;i<freq.size();i++){
		v = freq[i];
		for(int j=0;j<v.size();j++){
			printf("%d ", v[j]);
		}
		printf("\n");
	}
	printf("End print freq Item Set\n");
}

int main(){
	vector< vector<int> > freqItemSet;
	vector<int> v;
	int noTrans, noItems, temp, item, minSupport, curCard;
	
	printf("Enter the number of transactions and number of items: ");
	scanf("%d%d", &noTrans, &noItems);

	int trans[noTrans][MAXITEMS];
	memset(trans, 0, noTrans*MAXITEMS);

	printf("Enter the items in each transaction\n");
	for(int i=0;i<noTrans;i++){
		printf("Enter no of items in transaction %d: ", i+1);
		scanf("%d", &temp);
		printf("Enter the items of transaction %d:\n", i+1);
		for(int j=0;j<temp;j++){
			scanf("%d", &item);
			trans[i][item]=1;
		}
	}

	printf("Enter the minimum support: ");
	scanf("%d", &minSupport);

	// take the all items as initially present in itemset
	for(int i=1;i<=noItems;i++){
		v.clear();
		v.push_back(i);
		freqItemSet.push_back(v);
	}

	// used as a delimiter in the freqItemSet
	v.clear();
	v.push_back(-1);
	freqItemSet.push_back(v);

	// apriori algo
	curCard = 1; 
	while(freqItemSet.front()[0]!=-1){
		while(freqItemSet.front()[0]!=-1){
			
			// find the support for itemset
			int sup=0;
			v = freqItemSet.front();
			for(int i=0;i<noTrans;i++){
				int done=1;
				for(int j=0;j<v.size();j++){
					if(trans[i][v[j]]==0)
						done=0;
				}
				if(done!=0)
					sup++;
			}
			
			// check if the itemset is having minsupport then push it back
			if(sup>=minSupport){
				freqItemSet.push_back(v);
			}
			freqItemSet.erase(freqItemSet.begin());
		}

		// push the delimiter to the end
		v = freqItemSet.front();
		freqItemSet.push_back(v);
		freqItemSet.erase(freqItemSet.begin());

		// print the itemset
		printf("\nCardinality %d:\n", curCard);
		print(freqItemSet);

		// self join
		temp = freqItemSet.size()-1;
		for(int i=0;i<temp;i++){
			for(int j=i+1;j<temp;j++){

				// union of i and j
				vector<int> vj = freqItemSet[j];
				v = freqItemSet[i];
				for(int k=0; k<vj.size();k++){
					int l;
					for(l=0;l<v.size();l++){
						if(vj[k]==v[l])
							break;
					}
					if(l==v.size())
						v.push_back(vj[k]);
				}

				// check cardinality
				if(v.size()==curCard+1){

					// add to the list first check if the element already exists or not
					int k;
					for(k=temp+1;k<freqItemSet.size();k++){
						
						// compare v with kth itemSet in the freqItemSet
						int l, m;
						for(l=0;l<v.size();l++){
							for(m=0;m<freqItemSet[k].size();m++){
								if(v[l]==freqItemSet[k][m])
									break;
							}
							if(m==freqItemSet[k].size())
								break;
						}
						if(l==v.size())
							break;
					}
					if(k==freqItemSet.size())
						freqItemSet.push_back(v);
				}
			}
		}

		// push the delimiter
		v.clear();
		v.push_back(-1);
		freqItemSet.push_back(v);

		// remove the first temp+1 elements from freqItemSet
		for(int i=0;i<temp+1;i++)
			freqItemSet.erase(freqItemSet.begin());

		curCard++;
	}
	return 0;
}