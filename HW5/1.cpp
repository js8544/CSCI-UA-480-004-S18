#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>
#include <bitset>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

#define MAXN 100005

int isb(char c){
	if(c == '#'){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int n,m,a,b;

	cin>>n>>m;

	unsigned int target[n][(m+31)/32+1];
	FILL(target,0);

	REP(i,0,n){
		REP(j,0,m){
			char c;
			cin>>c;
			target[i][j/32] |= isb(c)<<(31-j%32);
		}
	}

	cin>>a>>b;

	unsigned int temp[a][(b+31)/32];
	unsigned int mask[a][(b+31)/32];
	FILL(temp,0);
	FILL(mask,~0);

	REP(i,0,a){
		REP(j,0,b){
			char c;
			cin>>c;
			if(c!='?'){
				mask[i][j/32] &= ~(1<<(31-j%32));
			}
			temp[i][j/32] |= isb(c)<<(31-j%32);
		}
	}
	// bitset<32> t(target[60][1]);
	// cout<<t<<"\n";
	int count=0;
	REP(i,0,n-a+1){
		REP(j,0,m-b+1){
			int match = 1;
			REP(l,0,a){
				REP(k,0,(b+31)/32){
					unsigned int tar;
					if(j%32){
						tar = (target[i+l][j/32+k] << j%32) + (target[i+l][j/32+k+1] >> (32-(j%32)));
					}
					else{
						tar = target[i+l][j/32+k];
					}
					// bitset<32> t(temp[l][k]);
					// bitset<32> ta(tar);
					// cout<<ta<<"\n";
					// bitset<32> m(mask[l][k]);
					// cout<<m<<"\n";
					// bitset<32> c(tar&~mask[l][k]);
					// cout<<c<<"\n";
					if((temp[l][k]^(tar&~mask[l][k]))!=0){
						//cout<<"("<<i<<","<<j<<","<<l<<","<<k<<")"<<"\n";
						match = 0;
						break;
					}
				}
				if(!match){
					break;
				}
			}
			if(match){
				count++;
			}
		}
	}
	cout<<count<<"\n";;
}