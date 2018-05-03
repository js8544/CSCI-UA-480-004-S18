// This solution runs two Kahn's. The first one using a max-heap, the second with min-heap.
// If the two orders are equal, then it is unique, otherwise it's not.
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

#define MAXN 100001
int n,m; //The number of vertices and edges
vector<int> adj[MAXN];
int in_degree[MAXN];
int in_degree2[MAXN];

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		in_degree[i]=0;
		in_degree2[i]=0;
	}
	for(int i=0;i<n;i++){
		int l; cin>>l;
		for(int j=0;j<l;j++){
			int a = i+1;
			int b; cin>>b;
			adj[a-1].push_back(b-1);
			in_degree[b-1]++;
			in_degree2[b-1]++;
		}	
	}
	priority_queue<int> max_heap;
	for(int i=0;i<n;i++){
		if(in_degree[i]==0) max_heap.push(i);
	 }
	int count = 0; //The number of vertices added to the order,used to check cycle
	int unique = 1;
	vector<int> order; //The topological order
	while(!max_heap.empty()){ //Kahn's algorithm
		if(max_heap.size()>1) unique = 0; //if anytime there's more than one element in the queue, it is not unique
		int x = max_heap.top();
		max_heap.pop();
		count++;
		order.push_back(x);
		for(int i=0;i<adj[x].size();i++){
			int y = adj[x][i];
			in_degree[y]--;
			if(in_degree[y]==0){
				max_heap.push(y);
			} 

		}
	}

	if(count<n){
		cout<<"build error\n";
		return 0;
	}

	priority_queue<int,vector<int>,greater<int> > min_heap;
	for(int i=0;i<n;i++){
		if(in_degree2[i]==0) min_heap.push(i);
	 }
	vector<int> order2; //The topological order
	while(!min_heap.empty()){ //Kahn's algorithm
		int x = min_heap.top();
		min_heap.pop();
		order2.push_back(x);
		for(int i=0;i<adj[x].size();i++){
			int y = adj[x][i];
			in_degree2[y]--;
			if(in_degree2[y]==0){
				min_heap.push(y);
			} 

		}
	}
	for(int i=0;i<order.size();i++){
		if(order[i]!=order2[i]){
			cout<<"not unique\n";
			return 0;
		}
	}

	cout<<"unique\n";
	for(int i=0;i<order.size();i++){
		cout<<order[i]+1<<" ";
	}
	cout<<"\n";

}

