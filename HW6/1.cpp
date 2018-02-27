#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
struct node{
	int age;
	string name;
	int rank;
	int parent;
	int young;
	int old;
}nodes[1000000];

int findRoot(int x){
	if(nodes[x].parent == x) return x;
	return nodes[x].parent = findRoot(nodes[x].parent);
}

void unionNodes(int x,int y){
	int xRoot = findRoot(x);
	int yRoot = findRoot(y);

	if(nodes[xRoot].rank>nodes[yRoot].rank){
		int temp = xRoot;
		xRoot = yRoot;
		yRoot = temp;
	}
	if(nodes[xRoot].rank==nodes[yRoot].rank){
		nodes[yRoot].rank++;
	}
	nodes[xRoot].parent = yRoot;

	node xyoung = nodes[nodes[xRoot].young];
	node xold = nodes[nodes[xRoot].old];
	node yyoung = nodes[nodes[yRoot].young];
	node yold = nodes[nodes[yRoot].old];

	if(xyoung.age<yyoung.age){
		nodes[yRoot].young = nodes[xRoot].young;
	}
	else if(xyoung.age==yyoung.age && xyoung.name<yyoung.name){
		nodes[yRoot].young = nodes[xRoot].young;
	}

	if(xold.age>yold.age){
		nodes[yRoot].old = nodes[xRoot].old;
	}
	else if(xold.age==yold.age && xold.name<yold.name){
		nodes[yRoot].old = nodes[xRoot].old;
	}
	
	cout<<nodes[nodes[yRoot].young].name<<" "<<nodes[nodes[yRoot].old].name<<"\n";
	
}

int main(){
	unordered_map<string,int> names;

	int n,q;
	cin>>n;

	for(int i=0;i<n;i++){
		string na;
		int ag;

		cin>>na>>ag;
		nodes[i].age=ag;
		nodes[i].name = na;
		nodes[i].young = i;
		nodes[i].old = i;
		nodes[i].parent = i;
		nodes[i].rank = 0;
		names[na] = i;
	}

	cin>>q;

	for(int i=0;i<q;i++){
		string a,b;
		cin>>a>>b;

		unionNodes(names[a],names[b]);
	}
}