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
// #define pb push_back
// #define PII pair<int,int>
// #define ll long long
// #define VI vector<int> 
// #define PLL part<ll,ll>
// //#define int long long
#define INF 1E9//1LL<<60
// #define mp make_pair
int res[30001];
int coin[1000];
int t,n,p;
int main(){
	cin>>t;
	REP(i,t){
		cin>>p;
		cin>>n;
		REP(j,n){
			cin>>coin[j];
		}
		
		REP(j,30001){
			res[j] = INF;
		}

		res[0] = 0;
		
		REP(j,n){
			for(int k = 30001-coin[j]-1;k>=0;k--){
				if(res[k]<INF){
					res[k+coin[j]] = MIN(res[k+coin[j]],res[k]+1);
				}
			}
		}

		int c = p;
		while(res[c]==INF) c++;
		P2(c,res[c]);

	}
}
