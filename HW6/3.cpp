#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;


int n,m,q;

struct node{
	node* parent;
	long long rank;
	long long h;
	int x;
	int y;
}grid[2001][2001];

bool nodeCompare(node *a,node *b){return a->h>b->h;}
bool pointerCompare(long long* a, long long* b) { return *a > *b; }
vector<node*> neighbor(node *no){
	vector<node*> neighbors;
	if(no->x>0) neighbors.push_back(&grid[no->x-1][no->y]);
	if(no->x<n-1) neighbors.push_back(&grid[no->x+1][no->y]);
	if(no->y>0) neighbors.push_back(&grid[no->x][no->y-1]);
	if(no->y<m-1) neighbors.push_back(&grid[no->x][no->y+1]);
	return neighbors;	
} 

node* findRoot(node* x){
	if(x->parent == x) return x;
	return x->parent = findRoot(x->parent);
}

void unionNodes(node* x, node *y){
	node* xRoot = findRoot(x);
	node* yRoot = findRoot(y);

	if(xRoot->rank>yRoot->rank){
		node* temp = xRoot;
		xRoot = yRoot;
		yRoot = temp;
	}
	if(xRoot->rank==yRoot->rank){
		yRoot->rank++;
	}
	xRoot->parent = yRoot;
}

int main(){
	cin>>n>>m>>q;
	vector<long long> hs(q,0);
	vector<node*> nodes(n*m,NULL);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			long long he;
			cin>>he;
			grid[i][j].parent = &grid[i][j];
			grid[i][j].rank = 0;
			grid[i][j].h = he;
			grid[i][j].x = i;
			grid[i][j].y = j;
			nodes[i*m+j] = &grid[i][j];
		}
	}
	vector<long long*> hmap(q,NULL);
	for(int i=0;i<q;i++){
		long long h;
		cin>>h;
		hs[i] = h;
		hmap[i] = &hs[i];
	}

	sort(nodes.begin(),nodes.end(),nodeCompare);
	sort(hmap.begin(),hmap.end(),pointerCompare);

	unordered_map <long long,long long> sol;
	long long cur = 0;
	long long count = 0;

	for(int i=0;i<q;i++){
		while(cur<n*m && nodes[cur]->h>*hmap[i]){
			//cout<<hs[i]<<":"<<cur<<"\n";
			vector <node*> neighbors= neighbor(nodes[cur]);
			for(int j=0;j<neighbors.size();j++){
				node* neighbor = neighbors[j];
				if(neighbor->h>*hmap[i]&&findRoot(neighbor)!=findRoot(nodes[cur])){
					unionNodes(nodes[cur],neighbor);
					count--;
				}
			
			}
			count++;
			cur++;
		}
		//cout<<*hmap[i]<<" "<<hs[i]<<":"<<count<<"\n";
		sol[*hmap[i]]=count;
	}

	for(int i=0;i<q;i++){
		cout<<sol[hs[i]]<<"\n";
	}
}