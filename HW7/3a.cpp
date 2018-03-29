#include <iostream>
using namespace std;
#define int long long

signed main(){
	int n;
	cin>>n;
	int grid[n*n];
	for(int i=0;i<n*n;i++){
		char c;
		cin>>c;
		if(c=='-') grid[i] = -1;
		else grid[1] = c-'0';
	}

	int in = 0;
	while(in<(1ll<<(n*n+1))){
		
	}

}