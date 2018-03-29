#include <iostream>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;



int main(){
	int diffc[60];
	memset(diffc,0,sizeof(diffc));
	int ori[60];
	int r[10];
	memset(r,0,sizeof(r));
	int n,m,b;
	long long grid[10];
	memset(grid,0,sizeof(grid));
	cin>>n>>m>>b;
	int num1 = 0;
	for(int i=0;i<n;i++){
		for(int j=m-1;j>=0;j--){
			char c;
			cin>>c;
			if(c=='*'){
				grid[i] |= (1<<j);
				num1++;
				r[i]++;
				diffc[j]++;
			}
			else{
				diffc[j]--;
			}
		}
	}
	memcpy(ori,diffc,sizeof(ori));

	int flip = 0;
	int min = 1E9;
	while(flip<((1<<n))){
		int num=0;
		memcpy(diffc,ori,sizeof(ori));
		int correct = 0;
		int rem = num1;

		// bitset<4> f(flip);
		// cout<<f<<"\n";
		for(int i=0;i<n;i++){
			if((flip&(1<<i))>0){
				//cout<<"flipping "<<i<<"\n";
				for(int j=m-1;j>=0;j--){
					if((grid[i]&(1ll<<j))>0) diffc[j]-=2;
					else diffc[j]+=2;
				}
				rem = rem+m-2*r[i];
				num++;
			}
		}

		sort(diffc,diffc+m,greater<int>());
		
		for(int i=0;i<m;i++){
			if(rem<=b){
				correct = 1;
				break;
			}
			if(diffc[i]<=0){
				break;
			}
			else{
				rem -= diffc[i];
				num++;
				if(rem<=b){
					correct = 1;
					break;
				}
			}
		}
		// cout<<num<<"\n";
		if(correct){
			if(num<min) min = num;
		}
		// cout<<rem<<"\n";
		// cout<<correct<<"\n";
		flip++;
	}
	if(min==1E9) min = -1;
	cout<<min<<"\n";
}