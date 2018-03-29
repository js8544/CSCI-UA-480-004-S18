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
#define MAXN 100000
#define MAXLEN 20
#define MAXNODES (MAXN*MAXLEN + 1)

int a[501];
int b[501];
int trieSize = 0;
map<int,int> cnt;
struct node{
	node* child[2];
	node(){
		child[0] = NULL;
		child[1] = NULL;
	}
};
node* newNode(){
	node* temp = new node;
	*temp = node();

	return temp;
}
node* root = newNode();

void insert(int v){
	//cout<<"inserting "<<v<<"\n";
	node* temp = root;
	for(int i=31;i>=0;i--){
		bool var = v & (1<<i);
		//cout<<var;
		if(!temp->child[var]){
			temp->child[var] = newNode();
		}
		temp = temp->child[var];
	}
	//cout<<"\n";
}

int find(int v){
	node* temp = root;
	int f = 1;
	for(int i=31;i>=0;i--){
		bool var = v & (1<<i);
		if(temp->child[var]){
			temp=temp->child[var];
		}
		else{
			f=0;
			break;
		}
	}
	return f;
}

int main(){
	int n;
	cin>>n;
	REP(i,n){
		cin>>a[i];
	}
	REP(i,n){
		cin>>b[i];
	}

	int ans=0;
	FOR(i,0,n){
		FOR(j,i+1,n){
			int p = a[i]^a[j];
			if(cnt.count(p)==0)cnt[p]=1;
			else cnt[p]++;
			//insert(p);
		}
	}
	FOR(i,0,n){
		FOR(j,i+1,n){
			int v = b[i]^b[j];
			//if(find(v))ans+=cnt[v];
			if(cnt.count(v))ans+=cnt[v];
		}
	}
	cout<<ans;
}