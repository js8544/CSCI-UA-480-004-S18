#include <iostream>
#include <cstring>

using namespace std;

int trieSize = 0;

struct node{
	int next[26];
	char max_child;
	int max_fre;
	int is_word;
	int word_fre;

	node(){
		is_word = 0;
		max_fre = 0;
		word_fre = 0;
		max_child = ' ';
		memset(next,0,sizeof(next));
	}
}nodes[2000001];

void add(int k,int i,string &s,int fre){
	if(i>=s.size()){
		if(nodes[k].max_fre<=fre){
			nodes[k].is_word = 1;
			nodes[k].word_fre = fre;
		}
		return;
	}

	char c = s[i];
	int t = c-'a';

	if(nodes[k].next[t]==0){
		nodes[k].next[t]=++trieSize;
		nodes[trieSize] = node();
	}
	if(nodes[k].max_fre<fre){
		nodes[k].max_fre=fre;
		nodes[k].max_child = c;
		if(fre>nodes[k].word_fre)nodes[k].is_word=0;
	}
	else if(nodes[k].max_fre==fre && c<nodes[k].max_child){
		nodes[k].max_child = c;
		if(fre>nodes[k].word_fre)nodes[k].is_word=0;
	}

	add(nodes[k].next[t],i+1,s,fre);

}


int findmax(int k){
	if(nodes[k].is_word&&nodes[k].max_child!=' '){
		k = nodes[k].next[nodes[k].max_child-'a'];
	}

	while(!nodes[k].is_word){
		k = nodes[k].next[nodes[k].max_child-'a'];
	}

	return k;
}


int main(){
	int n,q;
	cin>>n;

	//cout<<sizeof(node);

	nodes[0] = node();
	for(int i=0;i<n;i++){
		string s;
		int fre;
		cin>>s>>fre;
		add(0,0,s,fre);

	}

	cin>>q;
	for(int i=0;i<q;i++){
		string s;
		cin>>s;

		int k=0;
		string cur;
		for(int j=0;j<s.size();j++){
			if(s[j]!='#'){
				if(nodes[k].next[s[j]-'a']){
					cur+=s[j];
					k = nodes[k].next[s[j]-'a'];
				}
				else{
					for(int l=j;l<s.size();l++){
						if(s[l]!='#'){
							cur+=s[l];
						}
					}
					break;
				}
			}
			else{
				if(nodes[k].is_word&&nodes[k].max_child!=' '){
					cur+=nodes[k].max_child;
					k = nodes[k].next[nodes[k].max_child-'a'];
				}

				while(!nodes[k].is_word){
					cur+=nodes[k].max_child;
					k = nodes[k].next[nodes[k].max_child-'a'];
				}	
			}
		}
		cout<<cur<<"\n";
	}
}