#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Node{
	char name[20];
	Node *prev;
	Node *next;
};


Node* find(Node *stu,char *name){
	while(stu != NULL){
		if(strcmp(stu->name,name)==0){
			return stu;
		}
		else stu = stu->next;
	}
	return NULL;
}

void display(Node *stu){
	while(stu != NULL){
		printf("%s ",stu->name);
		stu = stu->next;
	}
	printf("\n");
}

int main(){
	int n,m;
	scanf("%d",&n);

	Node *head = new Node;
	Node *tail = new Node;
	head = NULL;

	for(int i=0;i<n;i++){
		Node *temp=new Node;
		scanf("%s ",temp->name);
		temp->next=NULL;
		if(!head){
	        head=temp;
	        tail=temp;
	        temp=NULL;
	    }
	    else
	    {	
	        tail->next=temp;
	        temp->prev=tail;
	        tail=temp;
	    }
	}



	scanf("%d\n",&m);

	for(int i=0;i<m;i++){
		char ins;
		char name[20];
		scanf("%c ",&ins);
		if(ins == 'x'){
			char name2[20];

			scanf("%s %s\n",name,name2);
			Node *student1,*student2;

			student1 = find(head,&name[0]);
			student2 = find(head,&name2[0]);

			char temp[20];
			strcpy(temp,student2->name);
			strcpy(student2->name,student1->name);
			strcpy(student1->name,temp);
		}
		else{
			scanf("%s\n",name);
			//printf("ins:%c, name:%s\n",ins,name);
			Node *student = find(head,&name[0]);
			switch(ins){
				case 'r':
					if(student->next){
						printf("%s\n",student->next->name);
					}
					else{
						printf("-1\n");
					}
					break;
				case 'l':
					if(student->prev){
						printf("%s\n",student->prev->name);
					}
					else{
						printf("-1\n");
					}
					break;
				case 'e':
					if(student->prev && student->next){
						student->prev->next = student -> next;
						student->next->prev = student -> prev;
					}
					else{
						if(student->prev){
							student->prev->next = NULL;
						}
						if(student->next){
							head = student->next;
							head->prev = NULL;
						}
					}
					break;
				}
		}
	}




}