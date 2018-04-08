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

int t,n;

signed main(){
	cin>>t;
	REP(i,t){
		priority_queue<int> s;
		cin>>n;
		int cur = 1;
		int d = 0;
		char c = 0;
		while(c != '\n'){
			cin.get(c);
			if(c=='C'){
				cur*=2;
			}
			if(c=='S'){
				if(cur>1) s.push(cur);
				d += cur;
			}
		}

		int count = 0; 
		while(d>n){
			if(s.empty()){
				count = -1;
				break;
			}
			else{
				int l = s.top()/2;
				d -= l;
				s.pop();
				if(l>1) s.push(l);

				count++;
			}
		}
		if(count==-1){
			cout<<"Case #"<<i+1<<": IMPOSSIBLE\n";
		}
		else{
			cout<<"Case #"<<i+1<<": "<<count<<"\n";
		}

	}
}
