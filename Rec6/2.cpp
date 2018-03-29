#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double error = 1e-7;
double p,q,r,s,t,u;
double cal(double x){
	return p*exp(-1*x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double bis(double a, double b){
	if(cal(a)==0){
		return a;
	}
	if(cal(b)==0){
		return b;
	}
	double c = (a+b)/2;
	while(b-a>1e-7){
		c = (a+b)/2;
		if(cal(c)*cal(a)<=0){
			b = c;
		}
		else if(cal(c)*cal(a)>0){
			a = c;
		}
		else if(cal(c)==0){
			return c;
		}
	}
	return (a+b)/2;
}
int main(){
	

	double x = 0;

	while(!cin.eof()){
		cin>>p>>q>>r>>s>>t>>u;
		if(!cin.eof()){
			int solve=0;
			if(cal(0)*cal(1)>0){
				cout<<"No solution\n";
			}
			else{
				printf("%.4lf\n", bis(0,1));
			}
		}

	}
}