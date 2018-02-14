#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct t{
	int month;
	int day;
	int hour;
	int min;
	int sec;
	char am[2];
};

struct prob{
	char name;
	int points;
};

struct student{
	char name[15];
	double s;
	double score[30];
	int solved[30];
	int freebies[30];
	struct t solve_time[30];
};

struct wsub{
	struct t time;
	char name[15];
	char prob;
};

void display_time(struct t time){
	printf("%d/%d %d:%d:%d\n",time.month,time.day,time.hour,time.min,time.sec);
}

float max(float a,float b){
	return a>b?a:b;
}

int comp(const void *aa, const void *bb){
	struct student *a = (struct student *)aa;
	struct student *b = (struct student *)bb;

	if(a->s>b->s){
		return -1;
	}
	if(a->s<b->s){
		return 1;
	}
	else{
		return strcmp(a->name,b->name);
	}
}

int is_earlier(struct t A,struct t B){
	if(A.month != B.month){
		return (A.month>B.month)?0:1;
	}
	else if(A.day != B.day){
		return (A.day>B.day)?0:1;
	}
	else if(A.hour != B.hour){
		return (A.hour>B.hour)?0:1;
	}
	else if(A.min != B.min){
		return (A.min>B.min)?0:1;
	}
	else{
		return (A.sec>B.sec)?0:1;
	}
}

void exact_time(struct t *time){
	if(strcmp(time->am,"pm")==0 && time->hour != 12){
		time->hour += 12;
	}
}

int main(){
	int n,f;

	char days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	 
	scanf("%d %d\n",&n,&f);

	struct prob probs[n];

	for(int i=0;i<n;i++){
		scanf("%s %d\n",&probs[i].name,&probs[i].points);
	}
	
	struct t deadline;
	scanf("%d/%d %d:%d:%d%s\n",&deadline.month,&deadline.day,&deadline.hour,&deadline.min,&deadline.sec,deadline.am);
	exact_time(&deadline);

	struct t start = deadline;

	if(deadline.day + 7 > days[deadline.month-1]){
		deadline.day = deadline.day + 7 - days[deadline.month-1];
		deadline.month ++;
	}
	else{
		deadline.day += 7;
	}


	// printf("n:%d,k:%d\n",n,k);
	// printf("%d/%d %d:%d:%d\n",deadline.month,deadline.day,deadline.hour,deadline.min,deadline.sec);

	struct t sub;
	struct student students[2000];
	int num_students=0;

	char student_name[15];
	char prob_name;
	char verdict[50];

	struct wsub wsubs[2000];
	int wsub_count = 0;


	while(scanf("%d/%d %d:%d:%d%s %s %c",&sub.month,&sub.day,&sub.hour,&sub.min,&sub.sec,sub.am,student_name,&prob_name)!= EOF){
		fgets(verdict,30,stdin);
		// printf("Scanned:%d/%d %d:%d:%d%s %s %c %s\n",sub.month,sub.day,sub.hour,sub.min,sub.sec,sub.am,student_name,prob_name,verdict);
		exact_time(&sub);
		int student_index = 0;
		int found = 0;
		for(int i=0;i<num_students;i++){
			if(strcmp(students[i].name,student_name)==0){
				student_index = i;
				found = 1;
				//printf("%s:%d Existed\n",student_name,student_index);
			}
		}

		if(!found){
			strcpy(students[num_students].name,student_name);
			//printf("%s Created\n",students[num_students].name);
			student_index = num_students;
			num_students++;
		}
		if(is_earlier(sub,deadline) && is_earlier(start,sub)){
			if(strcmp(verdict," Accepted\n")==0 || strcmp(verdict," Accepted")==0){
				for(int i=0;i<n;i++){
					if(prob_name == probs[i].name){
						if(students[student_index].solved[i]==0){
							students[student_index].score[i]+=probs[i].points;
							students[student_index].solved[i] = 1;
							students[student_index].solve_time[i] = sub;
						}
						else if(is_earlier(sub,students[student_index].solve_time[i])){
							students[student_index].solve_time[i] = sub;
						}
					}
				}
			}

			else{
				// printf("Wrong\n");
				wsubs[wsub_count].time = sub;
				strcpy(wsubs[wsub_count].name,student_name);
				wsubs[wsub_count].prob = prob_name;
				wsub_count++;
			}
		}
	}

	for(int i=0;i<wsub_count;i++){
		for(int j=0;j<num_students;j++){
			if(strcmp(students[j].name,wsubs[i].name)==0){
				for(int k=0;k<n;k++){
					if(wsubs[i].prob == probs[k].name){
						//printf("Wrong Answer by %s on %c\n",students[j].name,probs[k].name);
						if(!(students[j].solved[k] && is_earlier(students[j].solve_time[k],wsubs[i].time))){
							//printf("He has %d freebies\n",students[j].freebies[k] );
							if(students[j].freebies[k]+f>0){
								students[j].freebies[k]--;
							}
							else{
								students[j].score[k] -= 0.1*probs[k].points;
							}
							//printf("%s now has %f points on %c\n",students[j].name,students[j].score[k],probs[k].name);
						}
					}
				}
			}
		}
	}

	for(int i=0;i<num_students;i++){
		for(int j=0;j<n;j++){
			//printf("%s scores %f on %c\n",students[i].name,students[i].score[j],probs[j].name);
			students[i].score[j] = max(0.3*probs[j].points*students[i].solved[j],students[i].score[j]);
			students[i].s += students[i].score[j];
			//printf("%s scores %f on %c\n",students[i].name,students[i].score[j],probs[j].name);
		}
	}

	qsort(students,num_students,sizeof(struct student),comp);

	for(int i=0;i<num_students;i++){
		printf("%s %.12lf\n",students[i].name,students[i].s);
	}

}