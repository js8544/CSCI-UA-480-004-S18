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
#define INF 1LL<<60
#define mp make_pair
int n;
int black[20];
int white[20];

int depth[2000000];
int reach[2000000];
stack<char> sol;
int BFS(int s){
	
	if(depth[s]>=1000000){
		return 0;
	}
	if(__builtin_popcount(s)==1){
		return 1;
	}
	int b=0,w=0;
	REP(i,n){
		if(s&(1<<i)){
			b|=1<<(n-black[n-i-1]);
			w|=1<<(n-white[n-i-1]);
		}
	}
	//P3(s,w,b);
	if(!reach[b]){
		reach[b] = 1;
		depth[b] = depth[s]+1;
		if(BFS(b)){
			sol.push('b');
			return 1;
		}
	}
	
	if(!reach[w]){
		reach[w] = 1;
		depth[w] = depth[s]+1;
		if(BFS(w)){
			sol.push('w');
			return 1;
		}
	}
	return 0;
}
int main(){
	FILL(reach,0);
	FILL(depth,0);
	cin>>n;
	REP(i,n){
		int x;
		cin>>x;
		white[i]=x;
	}
	REP(i,n){
		int x;
		cin>>x;
		black[i]=x;
	}
	reach[(1<<n)-1]=1;
	if(BFS((1<<n)-1)){
		while(!sol.empty()){
			char c = sol.top();
			cout<<c;
			sol.pop();
		}
		cout<<"\n";
	}
	else{
		cout<<"impossible\n";
	}
}
