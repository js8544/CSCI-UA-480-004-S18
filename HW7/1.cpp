#include <iostream>
#include <bitset>
using namespace std;
int n,m;
int lines[20];
int originals[20];
int main(){

	cin>>n>>m;

	for(int i=1;i<n+1;i++){
		int line = 0;
		for(int j=m-1;j>=0;j--){
			char c;
			cin>>c;
			if(c=='*') line |= 1<<j;
		}
		lines[i] = line;
		originals[i] = line;
	}
	lines[0] = 0;
	int min = 1e9;
	while(lines[0]<=(1<<m)-1){
		lines[n] = originals[n];
		int num = 0;
		// bitset<8> b(lines[0]);
		// cout<<b<<"\n";
		for(int i=0;i<n;i++){
			// bitset<8> a(lines[i+1]);
			// cout<<"original "<<i+1<<":"<<a<<"\n";
			for(int j=m-1;j>=0;j--){
				if((lines[i]|(1<<j))==lines[i]){
					if(j>=1)lines[i+1] ^= 7<<(j-1);
					if(j==0)lines[i+1] ^= 3;
					
					lines[i+2] ^= 1<<j;
					num++;
				}
			}
			if(i>=1)lines[i] = originals[i];
			// bitset<8> d(lines[i+1]);
			// cout<<"new "<<i+1<<":"<<d<<"\n";
		}
		//cout<<num<<" for "<<b<<"\n";
		if((lines[n]&((1<<m)-1))==0&&num<min) min = num;
		lines[0]++;
	}
	if(min==1e9)min=-1;
	cout<<min<<"\n";


}