#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main(){
	int n;
	cin>>n;
	int scores[1000];
	memset(scores,0,sizeof(scores));
	int result=0;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		if(k>0 && scores[k]!=1){
			result++;
			scores[k]=1;
		}
	}

	cout<<result;
	return 0;

}