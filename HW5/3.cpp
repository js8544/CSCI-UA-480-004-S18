#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

struct node{
	int value;
	node* child[2];
	node(){
		child[0] = NULL;
		child[1] = NULL;
	}
};

struct edge{
	int b;
	int w;
	edge(int bb,int ww){
		b = bb;
		w = ww;
	}
};

node* newNode(){
	node* temp = new node;
	*temp = node();

	return temp;
}

node* root = newNode();

struct treenode{
	int weight;
	vector<int> children;
	treenode(){
		weight = 0;
	}
}tree[200001];

int values[200001];

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
	temp->value = v;
}

int findmax(int v){
	node* temp = root;
	for(int i=31;i>=0;i--){
		bool var = v & (1<<i);
		if(temp->child[1-var]){
			temp = temp->child[1-var];
		}
		else{
			temp = temp->child[var];
		}
	}
	return temp->value^v;
}
void init_trie(int root){
	for(vector<int>::iterator it=tree[root].children.begin();it!=tree[root].children.end();++it){
		int cur = *it;
		//cout<<"children of "<<root<<": "<<cur<<"\n";
		values[cur] = values[root]^tree[cur].weight;
		insert(values[cur]);
		init_trie(cur);
	}
}
int main(){
	int n;
	cin>>n;
	int a,b,w;

	values[1] = 0;

	vector<vector<edge> > neighbors(n+1,vector<edge>());

	for(int i=1;i<n;i++){
		cin>>a>>b>>w;
		neighbors[a].push_back(edge(b,w));
		neighbors[b].push_back(edge(a,w));
	}

	queue<int> q;

	q.push(1);
	int connected[n+1];
	memset(connected,0,sizeof(connected));
	connected[1] = 1;

	while(!q.empty()){
		int t = q.front();
		q.pop();

		for(int i=0;i<neighbors[t].size();i++){
			if(!connected[neighbors[t][i].b]){
				connected[neighbors[t][i].b]=1;
				tree[t].children.push_back(neighbors[t][i].b);
				tree[neighbors[t][i].b].weight = neighbors[t][i].w;
				q.push(neighbors[t][i].b);
			}
		}
	}

	// for(int i=1;i<n;i++){
	// 	cout<<i<<" "<<tree[i].children.size()<<"\n";
	// }

	init_trie(1);

	int result = 0;
	for(int i=1;i<n+1;i++){
		//cout<<findmax(values[i])<<" ";
		int r = findmax(values[i]);
		if(r>result) result = r;
	}
	cout<<result<<"\n";

	return 0;



}