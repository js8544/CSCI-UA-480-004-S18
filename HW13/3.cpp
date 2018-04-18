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
vector<PII> edges;
string words[200001];
queue<int> w[52][52];
vector<queue<int> > adj(52,queue<int>());
int in_deg[52];
int out_deg[52];
int b=-1,e=-1;
vector<int> order;

void euler(int x){
	//P2("at",x);
	while(!adj[x].empty()){
		int y=adj[x].front();
		adj[x].pop();
		out_deg[x]--;
		in_deg[y]--;
		euler(y);
	}
	if(in_deg[x]==0&&out_deg[x]==0){
		order.pb(x);
	}
}
signed main(){
	FILL(in_deg,0);
	FILL(out_deg,0);
	cin>>n;
	REP(i,n){
		string s;
		cin>>s;
		words[i] = s;
		int x=s[0]-'A'-6*(s[0]>='a');
		int y=s[s.size()-1]-'A'-6*(s[s.size()-1]>='a');
		edges.pb(mp(x,y));
		adj[x].push(y);
		out_deg[x]++;
		in_deg[y]++;
		w[x][y].push(i);
	}

	REP(i,52){
		int diff = in_deg[i]-out_deg[i];
		if(diff>1||diff<-1){
			cout<<"impossible\n";
			return 0;
		}
		else{
			if(diff==1){
				if(e==-1)e=i;
				else{
					cout<<"impossible\n";
					return 0;
				}
			}
			if(diff==-1){
				if(b==-1)b=i;
				else{
					cout<<"impossible\n";
					return 0;
				}
			}
		}
	}

	if(b==-1&&e==-1){
		b = words[0][0]-'A'-6*(words[0][0]>='a');
		e = b;
	}
	//cout<<b<<" "<<e<<"\n";

	euler(b);
	//P2(order.size(),n);
	if(order.size()<=n){
		cout<<"impossible\n";
		return 0;
	}
	reverse(order.begin(),order.end());
	REP(i,order.size()-1){
		int x = order[i];
		int y = order[i+1];
		cout<<words[w[x][y].front()]<<"\n";
		w[x][y].pop();
	}



}
