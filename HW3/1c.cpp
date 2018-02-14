#include<iostream>
#include<map>
#include<string>
#include<stdio.h>

using namespace std;

struct student{
	string left;
	string right;
};

int main(){
	int n,m;

	cin>>n;

	map<string,student> row;

	string temp;
	
	cin>>temp;
	row[temp].left = "-1";
	row[temp].right = "-1";

	for(int i=1;i<n;i++){
		string name;
		cin>>name;
		row[name].left = temp;
		row[name].right = "-1";

		row[temp].right = name;
		temp = name;
	}

	cin>>m;
	for(int i=0;i<m;i++){
		char ins;
		string name;
		cin>>ins;

		if(ins == 'x'){
			string name2;

			cin>>name>>name2;
			//cout<<name<<" "<<name2<<" "<<ins<<"\n";
			student *s1 = &row[name];
			student *s2 = &row[name2];

			//cout<<row[name].left<<" "<<name<<" "<<row[name].right<<"\n";
			student temp_s = *s1;
			*s1 = *s2;
			*s2 = temp_s;

			if(s2->left==name2){
				s2->left=name;
				s1->right=name2;
			}
			else if(s1->left==name){
				s1->left=name2;
				s2->right=name;
			}
			
			row[s1->left].right = name;
			row[s1->right].left = name;
			row[s2->left].right = name2;
			row[s2->right].left = name2;

			//cout<<row[name].left<<" "<<name<<" "<<row[name].right<<"\n";
		}
		else{
			cin>>name;
			student s = row[name];
			//cout<<name<<" "<<ins<<"\n";
			switch(ins){
				case 'r':
					cout<<s.right<<"\n";
					break;
				case 'l':
					cout<<s.left<<"\n";
					break;
				case 'e':
					if(s.left!="-1")row[s.left].right = s.right;
					if(s.right!="-1")row[s.right].left = s.left;
					break;
			}
		}
		// for (auto p : row) {
			
		// 	if(p.second.left == "-1"){
		// 		cout<<p.first<<" ";
		// 		student i = p.second;
		// 		while(i.right != "-1"){
		// 			cout<<i.right<<" ";
		// 			i = row[i.right];
		// 		}
		// 		cout<<"\n";
		// 		break;
		// 	}
		// }
	}
}