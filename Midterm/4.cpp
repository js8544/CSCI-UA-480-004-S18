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
int n,m,k;
struct res{
	int pos;
	int t;
}res[10001];

int cus[10001];

int cmp(struct res a,struct res b){
	if(a.pos<b.pos) return 1;
	else return 0;
}
int main(){
	cin>>n>>m>>k;

	REP(i,n){
		cin>>res[i].pos>>res[i].t;
	}

	sort(res,res+n,cmp);

	REP(i,m){
		cin>>cus[i];
	}

	sort(cus,cus+m);
	int ans = 0;
	int l = 0;
	
	REP(i,m){
		map<int,int> exist;
		int count=0;
		int close[k];
		int x = cus[i];
		while(res[l+1].pos<x&&l<n-1){
			l++;
		}	
		int temp = l;
		int r = l+1;
		while (l >= 0 && r < n && count < k){
	        if (x - res[l].pos < res[r].pos - x){
	        	if(exist.count(res[l].t)){
	        		l--;
	        		continue;
	        	}
	        	exist[res[l].t]=1;
	        	close[count]=res[l].pos;
	            l--;
	        }
	        else{
	        	if(exist.count(res[r].t)){
	        		r++;
	        		continue;
	        	}
	        	exist[res[r].t]=1;
	        	close[count]=res[r].pos;
	            r++;
	        }

	        count++;
    	}
    	while (count < k && l >= 0){
    		if(exist.count(res[l].t)){
    			l--;
	        	continue;
	        }
	        exist[res[l].t]=1;
    		close[count]=res[l].pos;
    		l--, count++;
    	}
        
	    while (count < k && r < n){
	    	if(exist.count(res[r].t)){
	    		r++;
	        	continue;
	        }
	        exist[res[r].t]=1;
	    	close[count]=res[r].pos;
	        r++, count++;
		}
		//cout<<"the "<<k<<"th closeset to "<<cus[i]<<" is "<<close[k-1]<<"\n";
		if(ABS(close[k-1]-cus[i])>ans) ans = ABS(close[k-1]-cus[i]);
	}
	P1(ans);


}
