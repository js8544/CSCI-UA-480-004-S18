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
#include <cmath>

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

int t;
signed main(){
	cin>>t;
	REP(i,t){
		int n;
		double e;
		cin>>n>>e;

		double a,b;
		REP(i,n){
			cin>>a>>b;
		}
		double res_max; //= 2*n*(a+b+sqrt(a*a+b*b));
		double res_min; //= 2*n*(a+b);
		double prev_max; //= 2*n*(a+b+MIN(a,b));

		int cut = 0;
		int find = 0;
		while(cut<=n){
			res_min = 2*n*(a+b)+2*cut*MIN(a,b);
			res_max = 2*n*(a+b)+2*cut*sqrt(a*a+b*b);
			prev_max = 2*n*(a+b)+2*(cut-1)*sqrt(a*a+b*b);
			if(e<res_min){
				cout<<setprecision(7)<<"Case #"<<i+1<<": "<<prev_max<<"\n";
				find = 1;
				break;
			}
			if(e>res_max){
				cut++;
			}
			else{
				cout<<setprecision(7)<<"Case #"<<i+1<<": "<<e<<"\n";
				find = 1;
				break;
			}

		}
		if(!find){
			cout<<setprecision(7)<<"Case #"<<i+1<<": "<<2*n*(a+b+sqrt(a*a+b*b))<<"\n";

		}
		


		
	}
}
