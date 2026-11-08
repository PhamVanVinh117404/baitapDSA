#include <stdio.h>
#include <stdlib.h>

void nhap(float **ma,int hang, int cot){
    for(int i = 0;i < hang; i++){
        for(int j = 0;j < cot; j++)
            scanf("%f" ,&ma[i][j]);
    }
}

void xuat(float **ma,int hang, int cot){
    for(int i = 0;i < hang; i++){
        for(int j = 0;j < cot; j++)
            printf("%.2f " ,ma[i][j]);
            printf("\n");
    }
}

int main(){
    float **ma;
    int h,c;
    printf("Nhap so hang va so cot: ");
    scanf("%d%d", &h,&c);
    ma = (float**)malloc(h*sizeof(float*));
    for(int i = 0; i < h; i++){
        ma[i] = (float*)malloc(c*sizeof(float));
    }
    nhap(ma,h,c);
    printf("Du lieu ban dau: \n");
    xuat(ma,h,c);
    for (int i = 0; i < h; i++) {
        free(ma[i]);
        }
    free(ma);
    return 0;
}
