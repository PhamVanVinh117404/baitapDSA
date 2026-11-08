#include <stdio.h>
#include <stdlib.h>

void nhap(float *a, int n)
{
    for(int i = 0;i < n;i++)
        scanf("%f",a+i);
}

void xuat(float *a, int n)
{
    for(int i = 0;i < n;i++)
        printf("%.2f ",*(a+i));
}

int main(){
    float *a;
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    a = (float*)malloc(n*sizeof(float));
    nhap(a,n);
    printf("Du lieu ban dau: \n");
    xuat(a,n);
    free(a);
    a = NULL;
    return 0;
}
