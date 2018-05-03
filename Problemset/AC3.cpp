// This solution checks after the topological sort if every two consecutive nodes
// are connected, if so, then it's unique.

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

#define MAXN 100001
int n,m; //The number of vertices and edges
vector<int> adj[MAXN];
int in_degree[MAXN];

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		in_degree[i]=0;
	}
	for(int i=0;i<n;i++){
		int l; cin>>l;
		for(int j=0;j<l;j++){
			int a = i+1;
			int b; cin>>b;
			adj[a-1].push_back(b-1);
			in_degree[b-1]++;
		}	
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		if(in_degree[i]==0) q.push(i);
	 }
	int count = 0; //The number of vertices added to the order,used to check cycle
	vector<int> order; //The topological order
	int unique = 1;


	while(!q.empty()){ //Kahn's algorithm
		int x = q.front();
		q.pop();
		count++;
		order.push_back(x);
		for(int i=0;i<adj[x].size();i++){
			int y = adj[x][i];
			in_degree[y]--;
			if(in_degree[y]==0){
				q.push(y);
			} 

		}
	}

	if(count<n){
		cout<<"build error\n";
		return 0;
	}

	for(int i=0;i<order.size()-1;i++){
		int x = order[i];
		int y = order[i+1];
		int find = 0;
		for(int j=0;j<adj[x].size();j++){
			if(adj[x][j]==y){
				find = 1;
				break;
			}
		}
		if(find==0){
			unique = 0;
			break;
		}
	}
	if(unique == 1){
		cout<<"unique\n";
		for(int i=0;i<order.size();i++){
			cout<<order[i]+1<<" ";
		}
		cout<<"\n";
	}
	else{
		cout<<"not unique\n";

	}
}

