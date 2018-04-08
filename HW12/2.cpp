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
#include <unordered_map>

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
#define INF 1000000007

struct node{
	int s[5];
	vector <int> out;
	vector <int> weight;
	node(int a,int b,int c,int d,int e){
		s[0]=a;
		s[1]=b;
		s[2]=c;
		s[3]=d;
		s[4]=e;
	}
	node(){}
}nodes[1000000];

struct Pair { // custom pair (vertex, distance) that compares based on distance
  int x, d;
  Pair(int _x, int _d): x(_x), d(_d) {}
  bool operator < (const Pair &another) const { return d > another.d; }
};

vector<vector<vector<vector<int> > > > m;

int f[5];
int v;
int dist[1000000];

signed main(){
	// clock_t t1,t2;
	// t1 = clock();
	cin>>f[0]>>f[1]>>f[2]>>f[3]>>f[4]>>v;
	int count = 0;
	int s[5];
	
	for(s[1]=0;s[1]<MIN(f[1],f[0])+1;s[1]++){
		vector<vector<vector<int> > > t1;
		m.pb(t1);
		for(s[2]=0;s[2]<MIN(f[2],f[0]-s[1])+1;s[2]++){
			vector<vector<int> > t2;
			m[s[1]].pb(t2);
			for(s[3]=0;s[3]<MIN(f[3],f[0]-s[1]-s[2])+1;s[3]++){
				vector<int> t3;
				m[s[1]][s[2]].pb(t3);
				for(s[4]=0;s[4]<MIN(f[4],f[0]-s[1]-s[2]-s[3])+1;s[4]++){
					s[0] = f[0]-s[1]-s[2]-s[3]-s[4];
					m[s[1]][s[2]][s[3]].pb(count);
					nodes[count] = node(s[0],s[1],s[2],s[3],s[4]);
					count++;
				}
			}
		}
	}
	// REP(i,m.size()){
	// 	REP(j,m[i].size()){
	// 		REP(k,m[i][j].size()){
	// 			REP(h,m[i][j][k].size()){
	// 				cout<<m[i][j][k][h]<<" ";
	// 				P4(i,j,k,h);
	// 			}
	// 		}
	// 	}
	// }

	//P1(count);

	priority_queue<Pair> pq;
	pq.push(Pair(0, 0));
	FILL(dist,INF);
	dist[0] = 0;
	int min=INF;
	while (!pq.empty()) {
		//P1(pq.size());
	    Pair cur = pq.top();
	    pq.pop();
	    int x = cur.x;
	    if (cur.d > dist[x]) continue; // ignore out-of-date pair
	    
		//cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<" "<<s[3]<<" "<<s[4]<<"\n";

	    REP(a,5){
	    	REP(b,5){
    			int s[5];
			    REP(i,5){
			    	s[i] = nodes[x].s[i];
			    }
    			int w = MIN(s[a],f[b]-s[b]);
    			//P3(a,b,w);
    			s[a]-= w;
				s[b]+= w;
				int y = m[s[1]][s[2]][s[3]][s[4]];
				if (dist[x] + w < dist[y]) {
		            dist[y] = dist[x] + w;
		            pq.push(Pair(y, dist[y]));
		        }
		        if(nodes[y].s[0]==v){
		            	if(dist[y]<min) min = dist[y];
		        }
	    	}
	    }
	}
	if(min==INF) min=-1;
	P1(min);

	// t2=clock();
 //    float diff ((float)t2-(float)t1);
 //    float seconds = diff / CLOCKS_PER_SEC;

 //    cout<<seconds<<endl;
	
    return 0;

}
