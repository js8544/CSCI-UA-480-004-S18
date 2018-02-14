#include <iostream>
#include <map>

using namespace std;

int main(){
	int n,m;

	
	cin>>n;
	for(int i=0;i<n;i++){
		int a=0;
		int b=0;

		int max=0;
		int d;
		cin>>m;
		int l[m];

		map <int,int> p;
		for(int j=0;j<m;j++){
			cin>>l[j];
		}
		//cout<<n<<m;
		while(b<m){
			//cout<<b;
			if(p.count(l[b])!=1||p[l[b]]==0){
				p[l[b]] = 1;
			}
			else{
				while(l[b]!=l[a]){
					p[l[a]]=0;
					a++;
				}
				a++;
			}
			
			d = b-a+1;

			if(d>max){
				max = d;
			}
			// cout<<"a: "<<a<<"b: "<<b<<"\n";
			// cout<<"Current:";
			// for(int k=a;k<=b;k++){
			// 	cout<<l[k]<<" ";
			// }
			// cout<<"\n";
			b++;
		}
		cout<<max<<"\n";
	}
}