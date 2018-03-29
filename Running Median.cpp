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

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;

priority_queue<int,vector<int>> lower_heap;
priority_queue<int,vector<int>,greater<int>> upper_heap;
double med = 0;

int add(int a){
	if(a>=med)upper_heap.push(a);
	else lower_heap.push(a);

	if(upper_heap.size()-lower_heap.size()==2){
		lower_heap.push(upper_heap.top());
		upper_heap.pop();
	}
	else if(lower_heap.size()-upper_heap.size()==2){
		upper_heap.push(lower_heap.top());
		lower_heap.pop();
	}
}

double get(){
	if(upper_heap.size()==lower_heap.size())return lower_heap.top()+upper_heap.top()/2;
	else if(upper_heap.size()>lower_heap.size())return upper_heap.top();
	else return lower_heap.top();
}


