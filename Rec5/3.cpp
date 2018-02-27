#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n,d,r;

	cin>>n>>d>>r;
	while(n){
		int h=0;
		int day[n];
		int night[n];

		for(int i=0;i<n;i++){
			cin>>day[i];
		}
		for(int i=0;i<n;i++){
			cin>>night[i];
		}
		sort(day,day+n);
		sort(night,night+n);

		for(int i=0;i<n;i++){
			if(day[i]+night[n-i-1]>d){
				h+=day[i]+night[n-i-1]-d;
			}
		}
		cout<<h*r<<"\n";
		cin>>n>>d>>r;
	}	
}