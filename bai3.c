#include<stdio.h>
#include<stdlib.h>
typedef struct {
    	char hoten[30];
    	int masv;
    	float d1, d2, d3;
}SV;
void nhap(SV *a, int n){
    for(int i = 0;i < n;i++){
        printf("Nhap ma sv: ");
        scanf("%d", &(a->masv));
        printf("Nhap ma ho ten: ");
        scanf("%s", (a->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(a->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(a->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(a->d3));
    }
}
void xuat(SV *a, int n){
    for(int i = 0;i < n;i++)
        printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 2: %.2f\n", a->hoten, a->masv, a->d1, a->d2, a->d3);
}
int main(){
    SV *a;
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    a = malloc(n*sizeof(SV));
    nhap(a,n);
    printf("Du lieu ban dau: \n");
    xuat(a,n);
    free(a);
    a = NULL;
}
