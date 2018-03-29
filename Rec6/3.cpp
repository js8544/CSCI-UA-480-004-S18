#include <iostream>

using namespace std;


int main(){
	int t,n;
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>n;
		int rungs[n+1];
		rungs[0] = 0;
		int max = 0;
		int cur = -1;
		for(int i=1;i<n+1;i++){
			cin>>rungs[i];
			int diff = rungs[i]-rungs[i-1];
			if(diff>max){
				max = diff;
				cur = max-1;
			}
			else if(diff>cur){
				max++;
				cur = max;
			}
			else if(diff==cur){
				cur--;
			}
		}
		cout<<"Case "<<j+1<<": "<<max<<"\n";
	}
}