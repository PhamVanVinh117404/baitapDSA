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
    	struct tagNode *link;
}Node;
typedef struct    {
    	Node *pHead;  
    	Node *pTail;
    	int spt;
}LList;
/////////////////////////////////////
void initList(LList *L)
    {
    	L->pHead = NULL;
    	L->pTail = NULL;
    	L->spt = 0;
    }
/////////////////////////////////////
int emptyList(LList L)
 {
    	return (L.spt == 0); 
}
/////////////////////////////////////
void insert_Head(LList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		pp->link = L->pHead;
    		L->pHead = pp;
    		}
    	L->spt++;
    }
void insert_Tail(LList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		L->pTail = pp->link;
    		L->pTail=pp;
    		}
    	L->spt++;
    }
void insert(LList *L,Data x,int n)
    {
    	Node *pp;
        Node *q;
        q = L->pHead + n;
        if(NULL==q) return;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
        pp->link = q->link;
        q->link = pp;
        if(q==L->pTail) L->pTail = pp;
    	L->spt++;
    }
Node *searchId(LList L,int ma){
	Node *pp = L.pHead;
	while (pp!=NULL && ma != pp->infor.masv)
		pp = pp->link;
	return pp; 
}
Node *searchName(LList L,char name[30]){
	Node *pp = L.pHead;
	while (pp!=NULL && !strstr(pp->infor.hoten,name))
		pp = pp->link;
	return pp; 
}
void del_Head(LList *L){
	Node *pp;
	if(emptyList(*L)) return;
	else{
		pp = L->pHead;
		L->pHead = pp->link;
		free(pp);
		L->spt--;
		if(L->pHead==NULL) L->pTail==NULL; 
	} 
}
void del_Tail(LList *L){
	Node *pp;
	if(emptyList(*L)) return;
	else{
		pp = L->pTail;
		L->pTail = pp->link; 
		free(pp);
		L->spt--;
		if(L->pHead==NULL) L->pTail==NULL; 
	} 
} 
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ma sv: ");
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
void processList(LList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
        	in(pp->infor); //in d? li?u trong node 
        	pp = pp->link;
    	}
}
/////////////////////////////////////////

int main(){
    LList L;
	int kt = 0;
	Data x;
	initList(&L); //tao ra 1 ds rong
	do{
	    printf("\nChuong trinh lam viec voi DSLK don SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
	    printf("\n4: Tim du lieu");
	    printf("\n5: Xoa nut dau")
		printf("\n6:Xoa nut cuoi") 
	    printf("\n9: Duyet ds");
	    printf("\n0: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon;
	    scanf("%d", &chon);
	    switch(chon){
	        case 1: 
	            printf("Nhap so thông tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Head(&L, x);
            	break;
            case 2:	
	            printf("Nhap so thông tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Tail(&L, x);
            	break;
            case 3:
	            printf("Nhap so thông tin sv can them\n");
                nhap(&x);
                int n;
                printf("Nhap vi tri can them vao sau: ");
                scanf("%d",&n);
                insert(&L,x,n);
            	break;
            case 4:
            	printf("Chon du lieu can tim voi 41 la tim ma, 42 la tim ten: ");
            	int tim;
				scanf("%d",&tim);
				switch(tim){
					case 41:
					printf("Nhap ma sv: ");
					int ma;
					searchId(L,ma);
					break;
					case 42:
					printf("Nhap ten: ");
					char ten[30];
					scanf("%s",ten);
					searchName(L,ten);
					break; 
				} 
				break;
			case 5:
				del_Head(&L); 
				break;
			case 6:
				del_Tail(&L); 
				break;  
            case 9: 
                processList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
	            kt = 1;
        }
	}while(kt==0); 
}
