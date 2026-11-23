#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
typedef struct    {
    	char hoten[30];
    	int masv;
    	float d1, d2, d3;
}Data;
typedef struct tagNode    {
    	Data infor;
    	struct tagNode *next, *prev;
}Node;
typedef struct    {
    	Node *pHead;  
    	Node *pTail;
    	int spt;
}DList;

void initList(DList *L)
    {
    	L->pHead = NULL;
    	L->pTail = NULL;
    	L->spt = 0;
    }

int emptyList(DList L)
 {
    	return (L.spt == 0); 
}

void insert_Head(DList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->next = NULL;
    	pp->prev = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		L->pHead->prev = pp;
    		pp->next=L->pHead;
    		L->pHead = pp;
    		}
    	L->spt++;
    }
    
void insert_Tail(DList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->next = NULL;
    	pp->prev = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		L->pTail->next = pp;
    		pp->prev=L->pTail;
    		L->pTail = pp;
    		}
    	L->spt++;
    }
   
void del_Head(DList *L){
	Node *pp;
	if(emptyList(*L)) return;
	else{
		pp = L->pHead;
		L->pHead = pp->next;
		if(L->pHead!=NULL) L->pHead->prev=NULL;
		free(pp);
		L->spt--;
		if(L->pHead==NULL) L->pTail==NULL; 
	} 
}
    
void del_Tail(DList *L){
	Node *pp;
	if(emptyList(*L)) return;
	else{
		pp = L->pTail;
		L->pTail = pp->prev; 
		free(pp);
		if(L->pTail!=NULL) L->pTail->next=NULL;
		L->spt--;
		if(L->pTail==NULL) L->pHead==NULL; 
	} 
}

void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ten sv: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}

void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 2: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}

void processList(DList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
        	in(pp->infor);
        	pp = pp->next;
    	}
}

int main(){
    DList L;
	int kt = 0;
	Data x;
	initList(&L);
	do{
	    printf("\nChuong trinh lam viec voi DSLK kep SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Xoa nut dau");
	    printf("\n4: Xoa nut cuoi");
	    printf("\n9: Duyet ds");
		printf("\n0: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon;
	    scanf("%d", &chon);
		switch(chon){
			case 1:
				printf("Nhap thong tin sv can them vao danh sach\n");
				nhap(&x);
				insert_Head(&L,x);
				break;
			case 2:
				printf("Nhap thong tin sv can them vao danh sach\n");
				nhap(&x);
				insert_Tail(&L,x);
				break;
			case 3:
				del_Head(&L);
				break;
			case 4:
				del_Tail(&L);
				break;
			case 9:
				processList(L);
				break;
			case 0:
			printf("Chao tam biet!\n");
			 kt = 1;
				 break;
		}
	}while(kt==0);
}
