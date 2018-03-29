#include <iostream>
#include <vector>
#include <queue>

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
int sol[200001];

bool compare(int a,int b){
	return queries[a].end>queries[b].end;
}
vector<vector<int> > q(200001,vector<int>());

priority_queue<int,vector<int>,decltype(&compare)> pq (&compare);



int main(){
	int n;
	cin>>n;

	for(int i=1;i<n+1;i++){
		int s,e;
		cin>>s>>e;
		queries[i]=query(i,s,e);
		q[s].push_back(i);
	}

	for(int i=1;i<n+1;i++){
		for(vector<int>::iterator it = q[i].begin();it!=q[i].end();++it){
			//cout<<"Inserting: "<<it->start<<it->end<<"\n";
			pq.push(*it);
		}
		if(pq.empty()){
			cout<<"no solution\n";
			return 0;
		}
		else if(queries[pq.top()].end<i){
			cout<<"no solution\n";
			return 0;
		}
		else{
			//cout<<"Shortest: "<<pq.top().start<<pq.top().end<<"\n";
			sol[queries[pq.top()].index] = i;
			pq.pop();
		}
	}

	for(int i=1;i<n+1;i++){
		cout<<sol[i]<<" ";
	}
	cout<<"\n";
}