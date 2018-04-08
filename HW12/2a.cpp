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
#define INF 1ll<<60
struct node{
	vector <int> s;
	vector <int> out;
	vector <int> weight;
	node(vector<int> _s){
		s = _s;
	}
	node(){}
}nodes[1000000];

struct Pair { // custom pair (vertex, distance) that compares based on distance
  int x, d;
  Pair(int _x, int _d): x(_x), d(_d) {}
  bool operator < (const Pair &another) const { return d > another.d; }
};

map<vector<int>,int> m;

int f[5];
int v;
int dist[1000000];
vector<int> state(int x1,int x2,int x3,int x4,int x5){
	vector<int> s;
	s.pb(x1);
	s.pb(x2);
	s.pb(x3);
	s.pb(x4);
	s.pb(x5);
	return s;
}


signed main(){

	clock_t t1,t2;
	t1 = clock();


	cin>>f[0]>>f[1]>>f[2]>>f[3]>>f[4]>>v;
	int count = 0;
	REP(x2,MIN(f[1],f[0])+1){
		REP(x3,MIN(f[2],f[0]-x2)+1){
			REP(x4,MIN(f[3],f[0]-x2-x3)+1){
				REP(x5,MIN(f[4],f[0]-x2-x3-x4)+1){
					vector<int> s = state(f[0]-x2-x3-x4-x5,x2,x3,x4,x5);
					m[s] = count;
					nodes[count] = node(s);
					count++;
				}
			}
		}
	}

	P1(count);
	t2=clock();
    float diff ((float)t2-(float)t1);
    float seconds = diff / CLOCKS_PER_SEC;

    cout<<seconds<<endl;
    
	REP(i,count){
		REP(a,4){
			REP(b,4){
				if(b!=a){
					int am = MIN(nodes[i].s[a],f[b]-nodes[i].s[b]);
					vector<int> s = nodes[i].s;
					s[a]-= am;
					s[b]+= am;
					nodes[i].out.pb(m[s]);
					nodes[i].weight.pb(am);
				}
			}
		}
	}

	priority_queue<Pair> pq;
	pq.push(Pair(0, 0));
	for (int x = 0; x < count; x++) dist[x] = INF;
	dist[0] = 0;
	int min=INF;
	while (!pq.empty()) {
	    Pair cur = pq.top();
	    pq.pop();
	    int x = cur.x;
	    if (cur.d > dist[x]) continue; // ignore out-of-date pair
	    for (int i=0;i<nodes[x].out.size();i++) {
	    	int y = nodes[x].out[i];
	    	int w = nodes[x].weight[i];
	        if (dist[x] + w < dist[y]) {
	            dist[y] = dist[x] + w;
	            pq.push(Pair(y, dist[y]));
	            if(nodes[y].s[0]==v){
	            	if(dist[y]<min) min = dist[y];
	            }
	        }
	    }
	}
	if(min==INF) min=-1;
	P1(min);


}

