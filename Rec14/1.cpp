#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <cctype>
#include <list>
#include <iterator>
#include <iomanip>
#include <stack>

using namespace std;

#define mod 1000000007LL
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FILL(a,b) memset(a,b,sizeof(a))
#define P1(x) cout<<(x)<<"\n"
#define P2(x,y) cout<<(x)<<" "<<(y)<<"\n"
#define P3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<"\n"
#define P4(x,y,z,k) cout<<(x)<<" "<<(y)<<" "<<(z)<<" "<<(k)<<"\n"
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define VI vector<int> 
#define PLL part<ll,ll>
#define int long long
#define INF 1LL<<60
#define mp make_pair
#define int long long
int n;
int type[10001];
PII factor[10001];
signed main(){
	cin>>n;
	REP(i,n+1){
		type[i] = 0;
	}
	type[0] = type[1] = -1;
	factor[0] = factor[1] = mp(0,0);
	type[2] = 0;
	factor[2] = mp(2,2);
	FOR(i,1,n+1){
		if(type[i]==-1){
			FOR(j,2,i){
				if(i*j>n) break;
				if(type[j]==0){
					type[i*j] = -1;
				}
			}
		}
		else if(type[i]==0){
			factor[i] = mp(i,i);
			if(i*i<=n){
				type[i*i] = 1;
				factor[i*i] = mp(i,i);
			}
			FOR(j,2,i){
				if(i*j>n) break;
				if(type[j]==0){
					type[i*j] = 2;
					factor[i*j] = mp(i,j);
				}
			}

		}
		else if(type[i]==1){
			if(i*factor[i].first>n) continue;
			type[i*factor[i].first] = 1;
			factor[i*factor[i].first] = mp(factor[i].first,factor[i].first);
		}
		else if(type[i]==2){
			FOR(j,2,i){
				if(i*j>n) break;
				if(type[j]==0){
					type[i*j] = -1;
				}
			}
			if(i*factor[i].first<=n){
				type[i*factor[i].first] = 2;
				factor[i*factor[i].first] = factor[i];
			}
			if(i*factor[i].second<=n){
				type[i*factor[i].second] = 2;
				factor[i*factor[i].second] = factor[i];
			}
			
			
		}
	}
	int ans = 0;
	FOR(i,1,n+1){
		//P2(i,type[i]);
		if(type[i]==2){
			ans ++;
			//P1(i);
		}
	}
	P1(ans);
}
