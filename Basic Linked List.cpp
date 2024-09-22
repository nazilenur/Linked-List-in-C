#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int age;
	char *name;
	struct Node *next;
}node;

void write_linkedList(struct Node *head){
	
	node*temp=head;
	
	while(temp!=NULL){
		printf("%d\n",temp->age);
		printf("%s\n",temp->name);
		temp=temp->next;
	}
	
	
}



int main(){
	
	node *head=(node*)malloc(sizeof(node));
	head->age=17;
	head->name="Ahmet";
	head->next=NULL;
	
	head->next=(node*)malloc(sizeof(node));
	head->next->age=20;
	head->next->name="Nazli";
	head->next->next=NULL;
	
	printf("%d\n",head->age);
	printf("%s\n",head->name);
	printf("%p\n",&(head));
	printf("%p\n",&(head->age));
	printf("%p\n",&(head->name));
	printf("%p\n",&(head->next));
	
	printf("--------------------------------------\n");
	
	write_linkedList(head);

}

