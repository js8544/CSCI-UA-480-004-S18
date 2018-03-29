#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct query{
	int index;
	int start;
	int end;
	query(int i,int s,int e){
		index = i;
		start = s;
		end = e;
	}
	query(){
		index = 0;
		start = 0;
		end = 0;
	}
}queries[200001];

bool compare_end(int a,int b){
	return queries[a].end>queries[b].end;
}

bool compare_start(int a,int b){
	return queries[a].start>queries[b].start;
}
priority_queue<int,vector<int>,decltype(&compare_start)> pq_start (&compare_start);
priority_queue<int,vector<int>,decltype(&compare_end)> pq_end (&compare_end);



int min(int a,int b){
	if(a<b) return a;
	else return b;
}

int max(int a,int b){
	if(a>b) return a;
	else return b;
}

int main(){
	int n,x,y;
	cin>>n>>x>>y;

	for(int i=0;i<n;i++){
		int k,s,e;
		cin>>k;

		s = max(0,k-x);
		e = min(k+x,y-k);
		queries[i] = query(k,s,e);
		if(e>=s){
			pq_start.push(i);
			//cout<<"added "<<k<<","<<s<<","<<e<<"\n";

		}
	}
	
	int cla[n];
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		cla[i]=k;
	}

	sort(cla,cla+n);
	int query_i = 0;
	int r = 0;

	for(int i=0;i<n;i++){
		if(!pq_start.empty()){
			while(queries[pq_start.top()].start<=cla[i]){
				//cout<<"inserting "<<queries[pq_start.top()].index<<"\n";
				pq_end.push(pq_start.top());
				pq_start.pop();
				if(pq_start.empty()) break;
			}			
		}
			
	
		if(pq_end.empty()) continue;
		while(queries[pq_end.top()].end<cla[i]){
			pq_end.pop();
			if(pq_end.empty())break;
		}

		if(pq_end.empty()) continue;

		//cout<<"Pair("<<cla[i]<<","<<queries[pq_end.top()].index<<")\n";
		pq_end.pop();
		r++;
	}

	cout<<r;
	cout<<"\n";
}