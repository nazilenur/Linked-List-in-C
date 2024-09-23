#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Ogrenci{
	int ogrenciNo;
	char isim[40];
	struct Ogrenci *next;
}ogrenci;

struct Ogrenci *createList(ogrenci *head);

void travelList(ogrenci *head);

struct Ogrenci *addNode(ogrenci *head);

struct Ogrenci *deleteNode(ogrenci *head);



int main(){
	
	ogrenci *head;
	
	int secim;
	
	while(1){
		
		printf("1.Create List\n2.Travel List\n3.Add Node\n4.Delete Node\n");
		scanf("%d",&secim);
		
		
		switch(secim){
			
			case 1:head=createList(head);break;
			
			case 2:travelList(head);break;
			
			case 3:head=addNode(head);travelList(head);break;
			
			case 4:head=deleteNode(head);travelList(head);break;
			
			default:printf("Hatali secim");exit(0);
					
		}
		
	}
		
}

struct Ogrenci *createList(ogrenci *head){
	
	int n;
	ogrenci *temp;
	
	printf("Ogrenci sayisini giriniz:");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		
		if(i==0){
			head=(ogrenci*)malloc(sizeof(ogrenci));
			temp=head;
		}
		else{
			temp->next=(ogrenci*)malloc(sizeof(ogrenci));
			temp=temp->next;
		}
		
		printf("%d.Ogrencinin numarasini giriniz:\n",i+1);scanf("%d",&temp->ogrenciNo);
		printf("%d.Ogrencinin ismini giriniz:\n",i+1);scanf("%s",temp->isim);
	}
	
	temp->next=NULL;
	
	return head;
	
	
}

void travelList(ogrenci *head){
	
	ogrenci *temp;
	temp=head;
	while(temp!=NULL){
		printf("%5d\t%s\n",temp->ogrenciNo,temp->isim);
		
		temp=temp->next;
		
	}
	
}

struct Ogrenci *addNode(ogrenci *head){
	
	ogrenci *temp,*p,*newNode;
	int x;
	
	newNode=(ogrenci*)malloc(sizeof(ogrenci));
	
	printf("Eklemek istediginiz ogrencinin numarasini giriniz:\n");scanf("%d",&newNode->ogrenciNo);
	printf("Eklemek istediginiz ogrencinin ismini giriniz:\n");scanf("%s",newNode->isim);
	
	printf("Hangi ogrenciden once eklemek istiyorsaniz o ogrencinin numarasini giriniz eger sona eklemek istiyorsaniz 0 a basiniz:");
	scanf("%d",&x);
	
	temp=head;
	
	if(temp->ogrenciNo==x){
		newNode->next=temp;
		head=newNode;
	}else{
		while(temp->next!=NULL&&temp->ogrenciNo!=x){
			p=temp;
			temp=temp->next;
		}
		if(temp->ogrenciNo==x){
			newNode->next=temp;
			p->next=newNode;
		}
		else if(temp->next==NULL){
			temp->next=newNode;
			newNode->next=NULL;
		}
	}
	
	return head;
}

struct Ogrenci *deleteNode(ogrenci *head){
	ogrenci *temp,*p;
	
	int x;
	
	printf("Silmek istediginiz ogrencinin numarasini giriniz:\n");scanf("%d",&x);
	
	temp=head;
	
	if(temp->ogrenciNo==x){
		head=temp->next;
		free(temp);
	}else{
		while(temp->ogrenciNo!=x){
		p=temp;
		temp=temp->next;		
	}
	p->next=temp->next;
	free(temp);
	}

	
	return head;
	
}
