#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n,q;
	cin>>n>>q;

	int l[n];
	for(int i=0;i<n;i++){
		cin>>l[i];
	}

	sort(l,l+n);

	for(int i=0;i<q;i++){
		int sum;
		cin>>sum;

		int a = 0;
		int b = n-1;

		int num=0;
		int check;
		while(a<b){
			int s = l[a] + l[b];

			if(s>sum){
				b--;
				continue;
			}
			if(s<sum){
				a++;
				continue;
			}
			if(s==sum){
				num++;
				check = b;
				b--;
				while(a<b){
					s = l[a] + l[b];
					if(s<sum){
						break;
					}
					if(s==sum){
						num++;
						b--;
						continue;
					}
				}
				b = check;
				a++;
			}
		}
		cout<<num<<"\n";
	}
}