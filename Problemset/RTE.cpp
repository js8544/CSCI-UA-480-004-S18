// This program checks the queue of zero in-degree vertices,
// if there are more than 1 vertices in the queue, the sort is not unique.
// it uses an adjacency matrix, so it will cause RTE.


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 100001
int n,m; //The number of vertices and edges
vector <vector<int> > adj;
vector<int> in_degree;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		vector<int> temp;
		for(int j=0;j<n;j++){
			temp.push_back(0);
		}
		adj.push_back(temp);
		in_degree.push_back(0);
	}
	for(int i=0;i<n;i++){
		int l; cin>>l;
		for(int j=0;j<l;j++){
			int a = i+1;
			int b; cin>>b;
			adj[a-1][b-1] = 1;
			in_degree[b-1]++;
		}	
	}
	// string buff;
	// getline(cin,buff);
	// for(int i=0;i<n;i++){
	// 	int a,b;
	// 	string line;
	// 	getline(cin,line);
	// 	istringstream iss(line);
	// 	iss>>a;
	// 	while(iss>>b){
	// 		adj[a-1][b-1] = 1;
	// 		in_degree[b-1]++;
	// 	}
		
	// }
	queue<int> q;
	for(int i=0;i<n;i++){
		if(in_degree[i]==0) q.push(i);
	 }
	int count = 0; //The number of vertices added to the order,used to check cycle
	vector<int> order; //The topological order
	int unique = 1;


	while(!q.empty()){ //Kahn's algorithm
		if(q.size()>1) unique = 0; //if anytime there's more than one element in the queue, it is not unique
		int x = q.front();
		q.pop();
		count++;
		order.push_back(x);
		for(int i=0;i<n;i++){
			if(adj[x][i]==0) continue;
			int y = i;
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

