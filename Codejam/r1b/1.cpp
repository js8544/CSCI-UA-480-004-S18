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
int t,n,l;
signed main(){
	cin>>t;
	REP(i,t){
		cin>>n>>l;
		vector<int> thr;
		REP(j,n){
			double r = (double)100*j/n;
			double fractpart = r-(int)r;
			if(fractpart>=0.5){
				thr.pb(j);
			}
		}
		if(thr.empty()){
			cout<<"Case #"<<i+1<<": 100\n";
			REP(j,l){
				int x;
				cin>>x;
			}
			continue;
		}
		int total = 0;
		vector<PII> pos;
		
		REP(j,l){
			int x; cin>>x;
			total += x;
			if(x>thr[thr.size()-1]){
				pos.pb(mp(1E9,x));
			} 
			else{
				int l = 0;
				int r = thr.size()-1;
				while(r>l){
					int m = (l+r)/2;
					if(thr[m]<x){
						l = m+1;
					}
					else{
						r = m;
					}
				}
				pos.pb(mp(thr[r]-x,x));
			}
			
		}

		int remain = n-total;
		while(total!=n){
			total++;
			pos.pb(mp(thr[0],0));
		}
		sort(pos.begin(),pos.end());

		int ans=0;
		REP(j,pos.size()){
			if(pos[j].first<=remain){
				pos[j].second+=pos[j].first;
				remain-=pos[j].first;
			}
			double temp =  (double) 100*pos[j].second/n;
			ans += round(temp);
		}
		if(remain>0){
			double temp = (double) 100*1/n;
			int w = round(temp);
			ans += w*remain;
		}
		cout<<"Case #"<<i+1<<": "<<ans<<"\n";



	}
}
