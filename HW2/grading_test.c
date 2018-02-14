#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int main(){
	time_t t;
	srand((unsigned) time(&t));

	int num_student = 5;
	int num_lines = 10;

	//int months[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	char am[2];

	char ams[2][5] = {"am","pm"};

	char students[100][15] = {"john1","john2","john3","john4","john5"};

	int month = rand()%12+1;
	int day = rand()%days[month-1]+1;
	int hour = rand()%13;
	int min = rand()%60;
	int sec = rand()%60;

	if(hour == 12){
		strcmp(am,"pm");
	}
	else{
		strcmp(am,ams[rand()%2]);
	}

	
	char vs[2][30] = {"Accepted","No"};
	FILE* fp = fopen("input1","w");
	fprintf(fp,"26 5\n");
	for(int i=0;i<26;i++){
		fprintf(fp, "%c 999\n", i+'A');
	}
	fprintf(fp, "%d/%d %d:%d:%d%s\n",month,day,hour,min,sec,am);
	for(int i=0;i<num_lines;i++){
		fprintf(fp, "%d/%d %d:%d:%d%s %s %c %s\n",month,day,rand()%12,rand()%60,rand()%60,ams[rand()%2],students[rand()%num_student],rand() % 3 + 'A',vs[rand()%2]);
	}
	fclose(fp);
}