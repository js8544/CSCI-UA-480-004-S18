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

struct node{
	map<int,int> adj;
	int deg;
}tree[100002];

int n,m;
PII edge[100001];



signed main(){
	cin>>n>>m;
	REP(i,m){
		int a,b;
		cin>>a>>b;
		edge[i].first = a;
		edge[i].second = b;
		tree[a].adj[b] = 1;
		tree[b].adj[a] = 1;
		tree[a].deg++;
		tree[b].deg++;
	}
	int count=0;
	REP(i,m){
		int a = edge[i].first;
		int b = edge[i].second;

		if(tree[b].deg<tree[a].deg){
			int temp = b;
			b = a;
			a = temp;
		}

		for(map<int,int>::iterator it = tree[a].adj.begin();it!=tree[a].adj.end();++it){
			if(tree[b].adj.find(it->first)!=tree[b].adj.end()){
				count++;
			}
		}
		tree[a].adj.erase(b);
		tree[b].adj.erase(a);
		tree[a].deg--;
		tree[b].deg--;
	}

	cout<<count<<"\n";

}
