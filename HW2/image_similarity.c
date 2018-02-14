#include<stdio.h>
#include<string.h>


void rotate(int *row,int *col,char M[(*row)*(*col)]){
	int r = *row;
	int c = *col;
	char N[r*c];
	for(int i=0;i<c;i++){
		for(int j=0;j<r;j++){
			N[i*r+j] = M[(r-j-1)*c+i];
		}
	}
	memcpy(M,N,r*c);
	*row = c;
	*col = r;
}


void display(int r,int c,char M[r*c]){
	printf("A:\n");
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%c",M[i*c+j]);
		}
		printf("\n");
	}
}

void flip(int r,int c, char M[r*c]){
	char N[r*c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			N[(r-i-1)*c+j] = M[i*c+j];
		}
	}
	memcpy(M,N,r*c);
}

int max(int a,int b){
	return (a>b)?a:b;
}

int min(int a,int b){
	return (a<b)?a:b;
}

int check(int r1, int c1, char M[r1*c1],int r2, int c2, char N[r2*c2]){
	int m = 0;
	for(int i=0;i<r1+r2-1;i++){
		for(int j=0;j<c1+c2-1;j++){
			int count = 0;
			for(int k=max(r1-1,i);k<min(i+r1,r1+r2-1);k++){
				for(int l=max(c1-1,j);l<min(j+c1,c1+c2-1);l++){
					if(M[(k-i)*c1+l-j]=='#' && M[(k-i)*c1+l-j]==N[(k+1-r1)*c2+l+1-c1]){
						count++;
					}
				}
			}
			m = max(count,m);
		}
	}
	return m;
}

int main(){
	char buff[100];
	int r1,r2,c1,c2;
	scanf("%d %d",&r1,&c1);
	fgets(buff,100,stdin);
	char A[r1*c1];
	for(int i=0;i<r1;i++){
		for(int j=0;j<c1;j++){
			scanf("%c",&A[i*c1+j]);
			// printf("Read:%c\n",A[i*c1+j]);
		}
		fgets(buff,100,stdin);
	}

	scanf("%d %d",&r2,&c2);
	fgets(buff,100,stdin);
	char B[r2*c2];
	for(int i=0;i<r2;i++){
		for(int j=0;j<c2;j++){
			scanf("%c",&B[i*c2+j]);
		}
		fgets(buff,100,stdin);
	}

	//display(r1,c1,A);
	//display(r2,c2,B);
	int max_count = 0;
	for(int i = 0;i<2;i++){
		for(int j = 0;j<4;j++){
			max_count=max(check(r1,c1,A,r2,c2,B),max_count);
			//display(r1,c1,A);
			rotate(&r1,&c1,A);
			//display(r1,c1,A);
		}
		flip(r1,c1,A);		
	}

	printf("%d\n",max_count);

}