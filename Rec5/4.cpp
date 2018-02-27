#include <iostream>
#include <bitset>
using namespace std;

int finds(int l, int u, int n,int c){
	int next = 1;
	int check = c|n;
	next = (~check) & (-(~check));
	if(u>=n){
		int k = u;
		k |= k>>1;
	    k |= k>>2;   
	 
	    k |= k>>4;  
	    k |= k>>8;
	    k |= k>>16;
	    

	    if(u>=(k-n)){
	    	if(k>n){
	    		return k-n; 
	    	}
	    	else{
	    		return 1;
	    	}
	    }
	    else{
	    	return u;
	    }
	}
	if(c+next<=u){
		return finds(l,u,n,c+next);
	}
	else if(l+next<=u){
		return u-(u&n);
	}
	else{
		return c;
	}
	return 0;
}

int main(){
	while(!cin.eof()){
		int n,l,u;
		cin>>n>>l>>u;
		if(!cin.eof())cout<<finds(l,u,n,l)<<"\n";
	}
}