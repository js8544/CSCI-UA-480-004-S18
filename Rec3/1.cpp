#include <iostream>
#include <cmath>
using namespace std;
int check(int m){
	for(int i=0;i<=m/3;i++){
		double k=(double)(m-i*3)/7;
		//cout<<k<<"\n";
		if(k-floor(k)<1e-6){
			return 1;
		}
		else{
			continue;
		}
	}
	return 0;
}
int main(){
	int n,m;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>m;
		if(check(m)){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}