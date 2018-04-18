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
int n,k;
vector<vector<int> > adj(100,vector<int>(0,0));
int out_deg[100];
int in_deg[100];
priority_queue<int,vector<int>,greater<int> > iso;
queue<int> q;
vector<int> order;

signed main(){
	FILL(out_deg,0);
	FILL(in_deg,0);

	cin>>n>>k;
	string cur;
	string next;
	cin>>cur;
	REP(i,n-1){
		cin>>next;
		//P2(cur,next);
		int l = MIN(cur.size(),next.size());
		int find=0;
		REP(j,l){
			if(cur[j]!=next[j]){
				find=1;
				int x = cur[j]-'A'-6*(cur[j]>='a');
				int y = next[j]-'A'-6*(next[j]>='a');
				adj[x].pb(y);
				out_deg[x]++;
				in_deg[y]++;
				// P3("added",cur[j],next[j]);
				break;
			}
		}
		if(find==0){
			if(cur.size()>next.size()){
				cout<<"impossible\n";
				return 0;
			}
		}
		cur = next;
	}

	int count=0;

	REP(i,k){
		if(in_deg[i]==0){
			if(out_deg[i]==0){
				iso.push(i);
			}
			else{
				q.push(i);
			}
			count++;
		}
	}

	while(!q.empty()){
		int x = q.front();q.pop();
		if(!iso.empty()){
			while(iso.top()<x){
				int check = iso.top();
				order.pb(check);
				iso.pop();
				P2("added",check);
				if(iso.empty()){
					break;
				}
			}
		}
		
		P2("added",x);
		order.pb(x);
		REP(i,adj[x].size()){
			int y = adj[x][i];
			in_deg[y]--;
			if(in_deg[y]==0){
				q.push(y);
				count++;
			}
		}
	}
	while(!iso.empty()){
		order.pb(iso.top());
		iso.pop();
	}
	if(count<k){
		cout<<"impossible\n";
	}
	else{
		REP(i,k){
			char c = 'A'+order[i]+(order[i]>25)*6;
			cout<<c;
		}
		cout<<"\n";
	}



}
