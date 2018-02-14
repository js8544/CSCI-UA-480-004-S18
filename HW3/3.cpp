#include<iostream>
#include<stdio.h>
using namespace std;
const unsigned int m = 1000000007;

int stack_num[20000];
char stack_op[20000];

int operate(int top,char op){
	int a = stack_num[top-1];
	int b = stack_num[top];
	int r;
	if(op=='*'){
		long long result = (long long) (a % m) * (b % m);
		r = result % m;
	}
	if(op=='+'){
		r = (a % m + b % m) % m;
	}
	if(op=='-'){
		if(a>=b) r = (a % m - b % m) % m;
		else r = (m + a % m - b % m) % m;
	}
	//cout<<a<<op<<b<<"="<<r<<"\n";
	return r;
}

int main(){
	char c;
	char last;
	int top_num = -1;
	int top_op = -1;

	int error=0;
	c=getchar();

	while(((c>='0'&&c<='9')||c=='+'||c=='('||c==')'||c=='-'||c=='*')&&error==0){
		//cout<<"Read "<<c<<"\n";

		// if(c==' '){
		// 	last = c;
		// 	c=getchar();
		// 	continue;
		// }

		if(c<='9' && c>='0'){

			int num=0;
			while(c<='9' && c>='0'){
				num = num*10 + (c-'0');
				last = c;
				c=getchar();
			}
			stack_num[++top_num]=num;
		}
		else{
			if(c=='('){
				stack_op[++top_op]=c;
			}
			else if(c==')'){
				if(last=='('){
					error = 1;
					//cout<<"empty parenthesis"<<"\n";
				}
				while(stack_op[top_op]!='('){
					if(top_num<1||top_op==0){
						error = 1;
						//cout<<"No ( before )"<<"\n";
						break;
					}
					if(stack_op[top_op]==' '){
						continue;
					}
					stack_num[top_num-1]=operate(top_num,stack_op[top_op]);

					top_num--;
					top_op--;
				}
				top_op--;
			}
			else{
				while(top_op>=0&&(stack_op[top_op]<=c||stack_op[top_op]-c==2)&&stack_op[top_op]!='('){
					if(top_num<1){
						error=1;
						//cout<<"Not enough numbers for"<<stack_op[top_op]<<"\n";
						break;
					}
					stack_num[top_num-1] = operate(top_num,stack_op[top_op]);
					top_num--;
					top_op--;
				}
				stack_op[++top_op] = c;
			}
			last = c;
			c = getchar();
		}
	}
	while(top_op!=-1){
		if(top_num<1||stack_op[top_op]=='('){
			error = 1;
			//cout<<"Final stack:Not enough numbers for"<<c<<"\n";
			break;
		}
		stack_num[top_num-1] = operate(top_num,stack_op[top_op]);

		top_op--;
		top_num--;

	}

	if(top_num==0&&error==0){
		cout<<stack_num[0]<<"\n";
	}
	else{
		cout<<"invalid"<<"\n";
	}
}