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
#define MAXN 100001
vector<int> aux,raux;
int n;
int num[MAXN],num_reverse[MAXN];
int finish[MAXN],start[MAXN];
int ans[MAXN];
int cnt[MAXN];
int bs(int val){
	int l = 0;
	int r = aux.size()-1;
	while(r>l){
		int m = (l+r)/2;
		if(num[aux[m]]<val){
			l = m+1;
		}
		else{
			r = m;
		}
	}
	return r;
}
int bsr(int val){
	int l = 0;
	int r = raux.size()-1;
	while(r>l){
		int m = (l+r)/2;
		if(num_reverse[raux[m]]<val){
			l = m+1;
		}
		else{
			r = m;
		}
	}
	return r;
}
signed main(){
	cin>>n;
	REP(i,n){
		cin>>num[i];
		num_reverse[n-i-1] = -num[i];
		finish[i] = -1;
		start[i] = -1;
		cnt[n] = 0;
	}
	REP(i,n){
		if(aux.empty()||num[i]>num[aux.back()]){
			aux.pb(i);
			finish[i] = aux.size()-1;
		}
		else{
			int pos = bs(num[i]);
			aux[pos] = i;
			finish[i] = pos;
		}
		// P2(num[i],finish[i]);
	}
	REP(i,n){
		if(raux.empty()||num_reverse[i]>num_reverse[raux.back()]){
			raux.pb(i);
			start[i] = raux.size()-1;
		}
		else{
			int pos = bsr(num_reverse[i]);
			raux[pos] = i;
			start[i] = pos;
		}
		// P2(num_reverse[i],start[i]);
	}
	// REP(i,n){
	// 	P2(finish[i],start[n-i-1]);
	// }
	int len = aux.size();
	REP(i,n){
		int sum = finish[i]+start[n-i-1];
		if(sum<len-1) ans[i] = 1;
		else{
			ans[i] = 2;
			cnt[start[n-i-1]]++;
		}
	}
	// REP(i,n){
	// 	if(ans[i]==2&&cnt[start[n-i-1]]==1) ans[i]++;
	// }

	// REP(i,n){
	// 	cout<<ans[i];
	// }
	// cout<<"\n";
	vector<int> sol;
	REP(i,n){
		if(ans[i]==2&&cnt[start[n-i-1]]==1) sol.pb(num[i]);
	}

	//sort(sol.begin(),sol.end());
	if(sol.empty()) cout<<"-1\n";
	else{
		REP(i,sol.size()){
			cout<<sol[i]<<" ";
		}
		cout<<"\n";
	}
}
