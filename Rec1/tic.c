#include<stdio.h>


int main(){
	char temp;
	char board[9];
	int count=0;
	int numX=0,num0=0;
	while(scanf("%c",&temp)!=EOF){
		if(temp!=' '&&temp!='\n'){
			board[count]=temp;
			count++;
		}
	}
	for(int i=0;i<9;i++){
		if(board[i]=='X'){
			numX++;
		}
		else if(board[i]=='0'){
			num0++;
		}
	}
	char win[8];
	count =0;
	if(board[0]==board[1]&&board[1]==board[2]){
		win[count]=board[0];
		count++;
	}
	if(board[0]==board[4]&&board[4]==board[8]){
		win[count]=board[0];
		count++;	
	}	
	if(board[0]==board[3]&&board[3]==board[6]){
		win[count]=board[0];
		count++;	
	}	
	if(board[1]==board[4]&&board[4]==board[7]){
		win[count]=board[1];
		count++;	
	}	
	if(board[2]==board[5]&&board[5]==board[8]){
		win[count]=board[2];
		count++;	
	}
	if(board[2]==board[4]&&board[4]==board[6]){
		win[count]=board[2];
		count++;	
	}
	if(board[3]==board[4]&&board[4]==board[5]){
		win[count]=board[3];
		count++;	
	}
	if(board[6]==board[7]&&board[7]==board[8]){
		win[count]=board[6];
		count++;	
	}
	int winX=0,win0=0;
	for(int i=0;i<8;i++){
		if(win[i]=='X'){
			winX=1;
		}
		else if(win[i]=='0'){
			win0=1;
		}
	}
	if(numX-num0<0||numX-num0>1){
		printf("illegal");
		return 0;
	}
	if(winX*win0>0){
		printf("illegal");
		return 0;
	}
	if(winX == 1 && numX == num0){
		printf("illegal");
		return 0;
	}
	if(win0==1 && numX>num0){
		printf("illegal");
		return 0;
	}
	if(winX == 1){
		printf("the first player won");
		return 0;
	}
	if(win0 == 1){
		printf("the second player won");
		return 0;
	}
	if(numX+num0==9){
		printf("draw");
		return 0;
	}
	if(numX>num0){
		printf("second");
		return 0;
	}
	if(num0==numX){
		printf("first");
	}

}

