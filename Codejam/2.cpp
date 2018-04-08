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
#define P1(x) cout<<(x)<<endl
#define P2(x,y) cout<<(x)<<" "<<(y)<<endl
#define P3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define P4(x,y,z,k) cout<<(x)<<" "<<(y)<<" "<<(z)<<" "<<(k)<<endl
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define VI vector<int> 
#define PLL part<ll,ll>
#define int long long
int t,n;
signed main(){
	cin>>t;
	REP(i,t){
		cin>>n;
		vector<int> odd;
		vector<int> even;
		REP(j,n/2){
			int x,y;
			cin>>x>>y;
			even.pb(x);
			odd.pb(y);
		}
		if(n%2==1){
			int x;
			cin>>x;
			even.pb(x);
		}

		sort(odd.begin(),odd.end());
		sort(even.begin(),even.end());

		// REP(j,n/2){
		// 	cout<<even[j]<<" "<<odd[j]<<" ";
		// }

		int index = -1;
		REP(j,n-1){
			if(j%2==0){
				if(even[j/2]>odd[j/2]){
					index = j;
					break;
				}
			}
			else{
				if(odd[j/2]>even[j/2+1]){
					index = j;
					break;
				}
			}
		}
		if(index==-1){
			cout<<"Case #"<<i+1<<": OK"<<endl;
		}
		else{
			cout<<"Case #"<<i+1<<": "<<index<<endl;
		}
	}
}
