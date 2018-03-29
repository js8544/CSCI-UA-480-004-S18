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

#define m 1000000007LL
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
#define MAXNODES 2000000
#define int long long

int n,k;
int fac[1000001];
int trieSize = 0;

int fenwick[1000001];

void fadd(int k, int v){
  k++;
  for(;k<MAXN;k+=-k&k) fenwick[k]+=v;
}
void init(){
  FOR(i,1,n+1){
    fadd(i,1);
  }
}
int get(int k){
  //cout<<k+1<<" ";
  if (k < 0) return 0;
  k++;
  int ans = 0;
  for(;k;k-=-k&k) ans += fenwick[k];
  //P1(ans);
  return ans;
}

struct TrieNode {
  int next[26], id;
  TrieNode(){
    memset(next, 0, sizeof(next));
    id=-1;
  }
} nodes[MAXNODES];

void add(int k, int strIndex, string &str, int i) {
  if(strIndex==str.size()){
    nodes[k].id = i;
    return;
  }
  char c = str[strIndex];
  int t = c - 'a';
  if(nodes[k].next[t] == 0){
    nodes[k].next[t] = ++trieSize;
    nodes[trieSize] = TrieNode();
  }

  add(nodes[k].next[t], strIndex + 1, str, i);
}

int madd(int a,int b){
  return (a % m + b % m) % m;
}

int mul(int a,int b){
  long long result = (long long) (a % m) * (b % m);
  return result % m;
}

int find(string &s){
  int cnt=0;
  int id=0;
  int c=0;
  int sol=1;
  
  REP(j,k){
    c=0;
    while(nodes[c].id==-1){
      c=nodes[c].next[s[id]-'a'];
      id++;
    }
    int i = nodes[c].id;
    sol=madd(sol,mul(get(i-1),fac[k-cnt-1]));
    fadd(i,-1);
    cnt++;
    c=0;
  }
  return sol;
}





signed main(){
  FILL(fenwick,0);

  cin>>n>>k;
  init();

  vector<string> str;
  fac[0]=1LL;
  REP(i,n+2){
    fac[i+1]=mul(fac[i],(n-k+i+1));
  }

  REP(i,n){
    string s;
    cin>>s;
    str.pb(s);
  }

  sort(str.begin(),str.end());

  // REP(i,n){
  //   P1(str[i]);
  // }

  REP(i,n){
    add(0,0,str[i],i+1);
  }


  string test;
  cin>>test;
  int sol=1;

  P1(find(test));
}
