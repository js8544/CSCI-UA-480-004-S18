#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int trieSize = 0;
struct node{
	int next[26];
	int max_fre;
	string max_child;
	string self;
	node(string s){
		max_fre = 0;
		max_child = "N";
		self = s;
		memset(next,0,sizeof(next));
	}
	node(){
		max_fre = 0;
		max_child = "N";
		self = "";
		memset(next,0,sizeof(next));
	}
}nodes[1000007];

void add(int k,int i,string s,int fre){
	if(i>=s.size()){
		return;
	}
	char c = s[i];
	int t = c-'a';

	if(nodes[k].next[t]==0){
		nodes[k].next[t]=++trieSize;
		nodes[trieSize] = node(nodes[k].self+c);
	}
	if(nodes[k].max_fre<fre){
		nodes[k].max_fre=fre;
		nodes[k].max_child = s;
	}
	else if(nodes[k].max_fre==fre && nodes[k].max_child.compare(s)>0){
		nodes[k].max_child = s;
	}

	add(nodes[k].next[t],i+1,s,fre);

}

int find(string s){
	int k=0;
	for(int i=0;i<s.size();i++){
		if(nodes[k].next[s[i]-'a']!=0){
			k = nodes[k].next[s[i]-'a'];
		}
		else{
			return -1;
		}
	}
	return k;
}

int main(){
	int n,q;
	cin>>n;

	nodes[0] = node("");
	for(int i=0;i<n;i++){
		string s;
		int fre;
		cin>>s>>fre;
		add(0,0,s,fre);
		nodes[find(s)].max_child = s;
	}
	// for(int i=0;i<=trieSize;i++){
	// 	cout<<nodes[i].self<<","<<nodes[i].max_child<<"\n";
	// }

	cin>>q;
	for(int i=0;i<q;i++){
		string s;
		cin>>s;
		if(s.find('#')==-1){
			cout<<s<<"\n";
		}
		else{
			string cur="";
			for(int j=0;j<s.size();j++){
				if(s[j]!='#'){
					cur+=s[j];
				}
				else{
					if(find(cur)!=-1){
						cur = nodes[find(cur)].max_child;
					}
				}
			}
			cout<<cur<<"\n";
		}
	}
}