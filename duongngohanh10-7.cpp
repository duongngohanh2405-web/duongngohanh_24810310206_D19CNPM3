#include"iostream"
#include"string.h"
using namespace std;
typedef struct{
	int makh;
	string tenkh;
	string sdt;
	float tien;
}kh;
void nhap(kh a[],int n){
	for(int i=0;i<n;i++){
		cout<<"nhap ma khach hang thu"<<i+1<<":";
		cin>>a[i].makh;
		cin.ignore();
		
		cout<<"nhap ten khach hang thu "<<i+1<<":";
		getline(cin,a[i].tenkh);
		
		cout<<"nhap so dien thoai khach hang thu "<<i+1<<":";
		getline(cin,a[i].sdt);
		
		cout<<"nhap so tien cua khach hang thu "<<i+1<<":";
		cin>>a[i].tien;
	}
}
void hienthi(kh a[],int n){
	for(int i=0;i<n;i++){
		cout<<"Hien thi ma khach hang thu "<<i+1<<":"<<a[i].makh<<endl;
		cout<<"Hien thi ten khach hang thu "<<i+1<<":"<<a[i].tenkh<<endl;
		cout<<"hien thi so dien thoai thu "<<i+1<<":"<<a[i].sdt<<endl;
		cout<<"Hien thi so tien khach hang thu "<<i+1<<":"<<a[i].tien<<endl;
	}
}
void chensx(kh a[],int n){
	for(int i=0;i<n;i++){
		kh x=a[i];
		int j=i-1;
		while(j>=0 && a[j].tien > x.tien){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
void timkiem(kh a[], int n, float x)
{
    int left = 0;
    int right = n - 1;
    int timthay = -1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(a[mid].tien == x)
        {
            timthay = mid;
            break;
        }
        else if(a[mid].tien < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if(timthay == -1)
    {
        cout << "\nKhong tim thay khach hang co tong tien bang " << x << endl;
    }
    else
    {
        cout << "\nCac khach hang co tong tien bang " << x << " la:" << endl;

        int i = timthay;

        while(i >= 0 && a[i].tien == x)
        {
            i--;
        }

        i++;

        while(i < n && a[i].tien == x)
        {
            cout << "\nMa khach hang: " << a[i].makh << endl;
            cout << "Ten khach hang: " << a[i].tenkh << endl;
            cout << "So dien thoai: " << a[i].sdt << endl;
            cout << "So tien: " << a[i].tien << endl;

            i++;
        }
    }
}

int main()
{
    kh a[100];
    int n;
    float x;

    cout << "Nhap so luong khach hang: ";
    cin >> n;

    nhap(a, n);

    cout << "\n========== DANH SACH VUA NHAP ==========" << endl;
    hienthi(a, n);

    chensx(a, n);

    cout << "\n========== DANH SACH SAU KHI SAP XEP ==========" << endl;
    hienthi(a, n);

    cout << "\nNhap tong tien X can tim: ";
    cin >> x;

    timkiem(a, n, x);

    return 0;
}
