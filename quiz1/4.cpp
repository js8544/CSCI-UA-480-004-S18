#include<iostream>
#include<map>
#include<string>
#include<stdio.h>

using namespace std;

struct student{
	int left;
	int right;
};

int main(){
	int n,m;

	cin>>n;

	map<int,student> row;

	for(int i=0;i<n+1;i++){
		row[i].left = i-1;
		row[i].right = i+1;
	}

	row[1].left = -1;
	row[n].right = -1;
	int lm = 1;
	int rm = n;
	cin>>m;
	for(int i=0;i<m;i++){
		string ins;
		int id;
		cin>>ins;
		cin>>id;
		student s = row[id];
		//cout<<name<<" "<<ins<<"\n";
		if(ins=="r")cout<<s.right<<"\n";
		else if(ins == "l")cout<<s.left<<"\n";
		else if(ins == "mr"&&rm!=id){
			if(s.left!=-1)row[s.left].right = s.right;
			if(s.right!=-1)row[s.right].left = s.left;
			if(lm==id&&s.right!=-1)lm=s.right;
			
			row[id].right = -1;

			row[id].left = rm;
			row[rm].right = id;
			rm = id;
		}
				
		else if(ins == "ml"&&lm!=id){
			if(s.left!=-1)row[s.left].right = s.right;
			if(s.right!=-1)row[s.right].left = s.left;
			if(rm==id&&s.left!=-1)rm=s.left;
			row[id].right = lm;
			row[lm].left = id;
			row[id].left = -1;
			lm = id;
		}
		//cout<<lm<<" "<<rm<<"\n";
	}
}