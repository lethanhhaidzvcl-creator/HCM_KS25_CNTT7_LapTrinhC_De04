#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

typedef struct{
    int maHang;
    char tenHang[50];
    int soLuong;
    float donGia;
}MatHang;

MatHang ds[MAX_SIZE];
int n = 0;

// Tim mat hang
int timMaHang(int ma){
    for(int i=0;i<n; i++){
        if(ds[i].maHang == ma){
            return i;
        }
    }

    return -1;
}

// 1. Them mat hang
void themMatHang(){
    if(n >= MAX_SIZE){
        printf("Danh sach da day!\n");
        return;
    }

    MatHang mh;

    printf("Nhap ma mat hang: ");
    scanf("%d", &mh.maHang);

    if(timMaHang(mh.maHang) != -1){
        printf("Ma mat hang da ton tai!\n");
        return;
    }

    printf("Nhap ten mat hang: ");
    scanf(" %49[^\n]", mh.tenHang);

    printf("Nhap so luong: ");
    scanf("%d", &mh.soLuong);

    if(mh.soLuong < 0){
        printf("So luong khong hop le!\n");
        return;
    }

    printf("Nhap don gia: ");
    scanf("%f", &mh.donGia);

    if(mh.donGia <= 0){
        printf("Don gia khong hop le!\n");
        return;
    }

    ds[n] = mh;
    n++;

    printf("Them mat hang thanh cong!\n");
}

// 2. Hien thi danh sach mat hang
void hienThiMatHang(){
    if(n==0){
        printf("Danh sach rong\n");
        return;
    }

    printf("\n%-10s %-25s %-12s %-12s %-15s\n", 
        "Ma", "Ten mat hang", "So luong", "Don gia", "Thanh Tien");

    for(int i=0; i<n; i++){
        float thanhTien = ds[i].soLuong * ds[i].donGia;

        printf("\n%-10d %-25s %-12d %-12.2f %-15.2f\n",
        ds[i].maHang, ds[i].tenHang, ds[i].soLuong, ds[i].donGia, thanhTien);
    }
}

// 3. Cap nhat mat hang theo ma
void capNhatMatHang(){
    int ma;

    printf("Nhap ma hang can cap nhat: ");
    scanf("%d", &ma);

    int vt = timMaHang(ma);

    if(vt == -1){
        printf("Khong tim thay mat hang!\n");
        return;
    }

    MatHang mh = ds[vt];

    printf("Nhap ten mat hang: ");
    scanf(" %49[^\n]", mh.tenHang);

    printf("Nhap so luong: ");
    scanf("%d", &mh.soLuong);

    if(mh.soLuong < 0){
        printf("So luong khong hop le!\n");
        return;
    }

    printf("Nhap don gia: ");
    scanf("%f", &mh.donGia);

    if(mh.donGia <= 0){
        printf("Don gia khong hop le!\n");
        return;
    }

    ds[vt] = mh;

    printf("Cap nhat thanh cong!\n");
}

// 5.Xoa mat hang
void xoaMatHang(){
    int ma;

    printf("Nhap ma hang can xoa: ");
    scanf("%d", &ma);

    int vt = timMaHang(ma);

    if(vt == -1){
        printf("Khong tim thay mat hang!\n");
        return;
    }

    for(int i= vt; i< n-1; i++){
        ds[i] = ds[i + 1];
    }

    n--;

    printf("Xoa mat hang thanh cong!\n");
}

// 6. Tim mat hang
void timTheoTen(){
    char ten[50];
    int dem = 0;

    printf("Nhap ten mat hang can tim: ");
    scanf(" %49[^\n]", ten);

    for(int i = 0; i<n;i++){
        if(strstr(ds[i].tenHang, ten) != NULL){
            printf("\nMa Hang: %d\n",ds[i].maHang);
            printf("\nTen Hang: %s\n", ds[i].tenHang);
            printf("\nSo Luong: %d\n", ds[i].soLuong);
            printf("\nDon gia: %.2f\n", ds[i].donGia);
            dem++;
        }
    }

    if(dem == 0){
        printf("Khong tim thay mat hang!\n");
    }
}
int main(){
    int choice;

    do{
        printf("\n=========QUAN LY MAT HANG============");
        printf("1.Them mat hang\n");
        printf("2.Hien thi danh sach mat hang\n");
        printf("3.Cap nhat mat hang theo ma\n");
        printf("4.Xoa mat hang theo ma\n");
        printf("5.Tim mat hang theo ten\n");
        printf("6.Thong ke kho hang\n");
        printf("0.Thoat\n");

        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                themMatHang();
                break;
            case 2:
                hienThiMatHang();
                break;
            case 3:
                capNhatMatHang();
                break;
            case 4:
                xoaMatHang();
                break;
            case 5:
                timTheoTen();
                break;
            case 6:
                themMatHang();
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }while(choice != 0);

    return 0;
}
