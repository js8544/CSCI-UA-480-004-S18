#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	int q;
	cin>>s;
	cin>>q;

	for(int i=0;i<q;i++){
		string ss;
		cin>>ss;
		int curs = 0;
		int curss = 0;
		int start = 0;
		int end = 0;
		while(curs<s.size()){
			//cout<<curs<<" "<<curss<<"\n";
			if(s[curs]==ss[curss]){
				if(curss == 0){
					start = curs;
				}
				if(curss == ss.size()-1){
					end = curs;
					break;
				}
				curss++;
				curs++;
			}
			else{
				curs++;
			}
		}
		if(end == 0){
			cout<<"Not matched\n";
		}
		else{
			cout<<"Matched "<<start<<" "<<end<<"\n";
		}
	}
}