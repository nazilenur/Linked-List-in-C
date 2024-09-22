#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Ogrenci{
	
	int ogrenciNo;
	char isim[40];
	int vize;
	int final;
	struct Ogrenci *next;
	
}ogrenci;

struct Ogrenci *kayitEkleme(ogrenci *head);
float ortalamaHesaplama(int vize,int final);
void *notListeleme(ogrenci *head);
void *enBasarili(ogrenci *head);
void *ortalama(ogrenci *head);
struct Ogrenci *ogrenciEkleme(ogrenci *head);
struct Ogrenci *ogrenciSilme(ogrenci *head);

int main(){
	
	ogrenci *head;
	
	int x;

	while(1){
		printf("1.Kayit Ekleme\n2.Not Listeleme\n3.En Basarili Ogrenciyi Goster\n4.Sinif Ortalamasini Goster\n5.Ogreci Ekleme\n6.Ogrenci Silme\n");
	    scanf("%d",&x);
		
		switch(x){
			
			case 1:head=kayitEkleme(head);break;
			
			case 2:notListeleme(head);break;
			
			case 3:enBasarili(head);break;
			
			case 4:ortalama(head);break;
			
			case 5:head=ogrenciEkleme(head);break;
			
			case 6:head=ogrenciSilme(head);break;
			
			default:printf("Hatali secim!");exit(0);
		
	    }
	}
	
}

struct Ogrenci *kayitEkleme(ogrenci *head){
	
	int n;
	ogrenci *temp;
	
	printf("Girmek istediginiz ogrenci sayisini giriniz:\n");scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		
		if(i==0){
			head=(ogrenci*)malloc(sizeof(ogrenci));
			temp=head;
		}else{
			temp->next=(ogrenci*)malloc(sizeof(ogrenci));
			temp=temp->next;
		}
		
		printf("%d.Ogrencinin numarasini giriniz:\n",i+1);scanf("%d",&temp->ogrenciNo);
		printf("%d.Ogrencinin ismini giriniz:\n",i+1);scanf("%s",&temp->isim);
		printf("%d.Ogrencinin vize notunu giriniz:\n",i+1);scanf("%d",&temp->vize);
		printf("%d.Ogrencinin final notunu giriniz:\n",i+1);scanf("%d",&temp->final);
	}
	
	temp->next=NULL;
	
	return head;
}

float ortalamaHesaplama(int vize,int final){
	
	return vize*0.4+final*0.6;
	
}

void *notListeleme(ogrenci *head){
	
	ogrenci *temp;
	
	temp=head;
	
	while(temp!=NULL){
		printf("Ogrenci No:%d\tAd:%s\tVize:%d\tFinal:%d\tOrtalamasi:%f\n\n",temp->ogrenciNo,temp->isim,temp->vize,temp->final,ortalamaHesaplama(temp->vize,temp->final));
		temp=temp->next;
	}
	
	return head;

}

void *enBasarili(ogrenci *head){
	
	ogrenci *basarili,*temp;
	basarili=head;
	temp=head;
	
	
	while(temp->next!=NULL){
		temp=temp->next;
		if(ortalamaHesaplama(temp->vize,temp->final)>ortalamaHesaplama(basarili->vize,basarili->final)){
			basarili=temp;
		}
	}
	
	printf("-------------Sinifin En Basarili Ogrencinin Bilgileri---------------\n\n\n");
	printf("Ogrenci No:%d\tAd:%s\tVize Notu:%d\tFinal Notu:%d\tOrtalamasi:%f\n\n",basarili->ogrenciNo,basarili->isim,basarili->vize,basarili->final,ortalamaHesaplama(basarili->vize,basarili->final));
	
	
	
}
void *ortalama(ogrenci *head){
	
	ogrenci *temp;
	temp=head;
	
	float ortalama,toplam;
	int counter=0;
	
	while(temp!=NULL){
		toplam+=ortalamaHesaplama(temp->vize,temp->final);
		temp=temp->next;
		counter++;
	}
	
	ortalama=toplam/counter;
	
	printf("\n\nSinifin ortalamasi:%f\n\n",ortalama);
	
}

struct Ogrenci *ogrenciEkleme(ogrenci *head){
	
	ogrenci *temp,*p,*newNode;
	int x;
	
	newNode=(ogrenci*)malloc(sizeof(ogrenci));
	
	temp=head;
	
		printf("Ekleyeceginiz Ogrencinin numarasini giriniz:\n");scanf("%d",&newNode->ogrenciNo);
		printf("Ekleyeceginiz Ogrencinin ismini giriniz:\n");scanf("%s",&newNode->isim);
		printf("Ekleyeceginiz Ogrencinin vize notunu giriniz:\n");scanf("%d",&newNode->vize);
		printf("Ekleyeceginiz Ogrencinin final notunu giriniz:\n");scanf("%d",&newNode->final);
		
		printf("Ekleyeceginiz ogrenci hangi ogrenciden once olmasýný istiyorsaniz o ogrencinin numarasini giriniz en sona koymak isterseniz 0 a basiniz\n");
		scanf("%d",&x);
		
		if(temp->ogrenciNo==x){
			newNode->next=temp;
			head=newNode;
		}else{
			while(temp->next!=NULL&&temp->ogrenciNo!=x){
				p=temp;
				temp=temp->next;		
			}if(temp->ogrenciNo==x){
				p->next=newNode;
				newNode->next=temp;
			}else if(temp->next==NULL){
				temp->next=newNode;
				newNode->next=NULL;
			}
			
		}		
		return head;	
}

struct Ogrenci *ogrenciSilme(ogrenci *head){
	
	int x;
	ogrenci *temp,*p;
	
	printf("Silmek istediginiz ogrencinin numarasini giriniz:\n");scanf("%d",&x);
	
	temp=head;
	
	if(temp->ogrenciNo==x){
		head=temp->next;
		free(temp);
	}else{
		while(temp!=NULL&&temp->ogrenciNo!=x){
			p=temp;
			temp=temp->next;
		}if(temp->ogrenciNo==x){
			p->next=temp->next;
			free(temp);
		}
	}
	
	return head;

}
	
