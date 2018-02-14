#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
	int d[2];
	int p[2];
	for(int k=0;k<2;k++){
		int E;
		cin >> E;
		vector<vector<int> > adj(E,vector<int>());
		vector<int> count(E,0);

		for(int i=0;i<E-1;i++){
			int a,b;
			cin>>a>>b;
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
			count[a-1]++;
			count[b-1]++;
		}
		int exist = E;
		int round = 0;
		queue <int> q1;
		queue <int> q2;

		for(int i=0;i<E;i++){
			if(count[i]==1){
				q1.push(i);
			}
		}

		while(exist>2){
			int a = q1.front();
			q1.pop();
			count[a]--;
			exist--;
			for(int i=0;i<adj[a].size();i++){
				int b = adj[a][i];
				count[b]--;
				if(count[b]==1){
					q2.push(b);
				}
			}
			if(q1.empty()){
				round++;
				q1.swap(q2);
			}
		}
		while(exist==2&&q1.size()==1){
			int a = q1.front();
			q1.pop();
			count[a]--;
			exist--;
			round++;
		}

		for(int i=0;i<E;i++){
			if(count[i]==1){
				p[k]=i+1;
				break;
			}
		}
		
		if(exist==2){
			d[k] = round*2+1;
		}
		else{
			d[k] = round*2;
		}
	}
	cout<<max(max(d[0],d[1]),(d[0]+1)/2+(d[1]+1)/2+1)<<"\n";
	cout<<p[0]<<" "<<p[1]<<"\n";


}