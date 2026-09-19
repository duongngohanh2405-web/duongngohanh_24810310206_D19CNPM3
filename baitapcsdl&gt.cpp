#include <stdio.h>
#include <string.h>

struct HangHoa {
    char maHang[20];
    char tenHang[50];
    int ngay;
    int thang;
    int nam;
    float gia;
};

void nhap(struct HangHoa a[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("\nNhap hang hoa thu %d:\n", i + 1);

        printf("Ma hang hoa: ");
        fflush(stdin);
        gets(a[i].maHang);

        printf("Ten hang hoa: ");
        gets(a[i].tenHang);

        printf("Ngay xuat hang (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &a[i].ngay, &a[i].thang, &a[i].nam);

        printf("Gia xuat hang (trieu dong): ");
        scanf("%f", &a[i].gia);
    }
}

void xuat(struct HangHoa a[], int n) {
    int i;

    printf("\n%-15s %-25s %-15s %-15s\n",
           "Ma hang", "Ten hang", "Ngay xuat", "Gia (trieu)");

    for (i = 0; i < n; i++) {
        printf("%-15s %-25s %02d/%02d/%04d %-15.2f\n",
               a[i].maHang,
               a[i].tenHang,
               a[i].ngay,
               a[i].thang,
               a[i].nam,
               a[i].gia);
    }
}

void selectionSort(struct HangHoa a[], int n) {
    int i, j, min;
    struct HangHoa temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (a[j].gia < a[min].gia) {
                min = j;
            }
        }

        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

void timKiemNhiPhan(struct HangHoa a[], int n, float X) {
    int left = 0;
    int right = n - 1;
    int mid;
    int found = 0;
    int i;

    while (left <= right) {
        mid = (left + right) / 2;

        if (a[mid].gia == X) {
            found = 1;
            i = mid - 1;
            while (i >= 0 && a[i].gia == X) {
                i--;
            }

            i++;

            while (i < n && a[i].gia == X) {
                printf("%-15s %-25s %02d/%02d/%04d %-15.2f\n",
                       a[i].maHang,
                       a[i].tenHang,
                       a[i].ngay,
                       a[i].thang,
                       a[i].nam,
                       a[i].gia);
                i++;
            }

            break;
        }
        else if (a[mid].gia < X) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (found == 0) {
        printf("\nKhong tim thay hang hoa co gia %.2f trieu dong.\n", X);
    }
}

int main() {
    struct HangHoa a[100];
    int n;
    float X;
    printf("Nhap so luong hang hoa n = ");
    scanf("%d", &n);
    nhap(a, n);
    printf("\n========== DANH SACH HANG HOA VUA NHAP ==========\n");
    xuat(a, n);
    selectionSort(a, n);

    printf("\n========== DANH SACH SAU KHI SAP XEP ==========\n");
    xuat(a, n);
    printf("\nNhap gia X can tim (trieu dong): ");
    scanf("%f", &X);
    printf("\n========== CAC HANG HOA CO GIA %.2f ==========\n", X);
    timKiemNhiPhan(a, n, X);
    return 0;
}
