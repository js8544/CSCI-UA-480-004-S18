#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	int n;
	cin>>n;

	int a[n];
	int link[n];
	link[0] = -1;
	a[0] = -1;
	int b=1,e=1;

	for(int i=0;i<n;i++){
		char ins;
		cin >> ins;

		if(ins == 'p'){
			if(b>=e){
				cout<<"-1\n";
				continue;
			}
			cout<<a[b]<<"\n";
			a[b] = -1;
			b++;
		}
		if(ins == 'a'){
			int k;
			cin>>k;
			int m = e-1;
			while(k<=a[m]){
				m = link[m];
			}
			link[e] = m;
			cout<<a[m]<<"\n";
			a[e] = k;
			e++;
		}
	}
}