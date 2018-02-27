#include <iostream>
using namespace std;

const char colors[3] = {'n','r','b'};
int roots[2] = {0,0};
int num_tree;
int know = 0;
struct node{
	int parent;
	int rank;

	int color;
}nodes[1000000];

int check(int i){
	//cout<<i<<":"<<num_tree<<" ROOTS: "<<roots[0]<<","<<roots[1]<<"\n";
	if(num_tree==2 && roots[0] && roots[1]){
		cout<<"Q"<<i<<": I know\n";
		know = 1;
		return 1;
	}
	return 0;
}
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
	if(nodes[xRoot].color){
		nodes[yRoot].color = nodes[xRoot].color;
		roots[nodes[xRoot].color-1] = yRoot;
	}
}

int main(){
	int n,q;
	cin>>n>>q;

	num_tree=n*2;

	for(int i=1;i<2*n+1;i++){
		nodes[i].parent = i;
		nodes[i].rank = 0;
		nodes[i].color = 0;
	}

	for(int i=1;i<q+1;i++){
		char in;
		cin>>in;
		int x,y;
		if(in=='d'){
			cin>>x>>y;
			if(findRoot(x)!=findRoot(y)){
				if(findRoot(x)!=findRoot(y+n)){
					if(!(nodes[findRoot(x)].color&&nodes[findRoot(y)].color)) num_tree-=2;

					unionNodes(x,y+n);
					unionNodes(x+n,y);
					if(check(i)) break;
				}
			}
			else{
				cout<<"Q"<<i<<": ?\n";
			}
		}
		else if(in=='s'){
			cin>>x>>y;
			if(findRoot(x)!=findRoot(y+n)){
				if(findRoot(x)!=findRoot(y)){
					if(!(nodes[findRoot(x)].color&&nodes[findRoot(y)].color)) num_tree-=2;
					unionNodes(x,y);
					unionNodes(x+n,y+n);
					if(check(i)) break;
				}
			}
			else{
				cout<<"Q"<<i<<": ?\n";
			}
		}
		else if(in=='r'){
			cin>>x;
			if(nodes[findRoot(x)].color!=2){
				if(roots[0]){
					if(findRoot(x)!=roots[0]){
						unionNodes(x,roots[0]);
						unionNodes(x+n,roots[1]);
						num_tree-=2;
					}
				}
				else{
					nodes[findRoot(x)].color=1;
					nodes[findRoot(x+n)].color=2;
					roots[0] = findRoot(x);
					roots[1] = findRoot(x+n);
				}
				if(check(i)) break;
			}
			else{
				cout<<"Q"<<i<<": ?\n";
			}
		}
		else if(in=='b'){
			cin>>x;
			if(nodes[findRoot(x)].color!=1){
				if(roots[1]){
					if(findRoot(x)!=roots[1]){
						unionNodes(x,roots[1]);
						unionNodes(x+n,roots[0]);
						num_tree-=2;
					}
				}
				else{
					nodes[findRoot(x)].color=2;
					nodes[findRoot(x+n)].color=1;
					roots[1] = findRoot(x);
					roots[0] = findRoot(x+n);
				}
				if(check(i)) break;
			}
			else{
				cout<<"Q"<<i<<": ?\n";
			}
		}
	}

	if(know){
		for(int i=1;i<n+1;i++){
			cout<<colors[nodes[findRoot(i)].color];
		}
	}
	else cout<<"I am not sure";
	cout<<"\n";

	return 0;
}