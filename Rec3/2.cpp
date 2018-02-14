#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	int min=1000000007;
	int d=1;
	int mind=100007;
	int k;
	for(int i=0;i<n;i++){
		cin>>k;

		if(k<min){
			min = k;
			d = 1;
			mind = 10007;
		}
		else if(k==min){
			if(d<mind){
				mind = d;
			}
			d = 1;
		}
		else{
			d++;
		}
	}
	cout<<mind<<"\n";
}