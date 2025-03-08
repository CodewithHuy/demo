#include<iostream>
#include<iomanip>
#include<set>
#include<vector>
#include<queue>
#include<map>
#include<deque>
#include<functional>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
#define foru(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a; i>=b; i--)
#define endl "\n"
#define nmax 200005
#define pb push_back
#define pf push_front
#define pll pair<ll, ll>
#define sz(s) (ll)s.size();
#define fi first 
#define se second
const int INF=(int) 1e9+2804;
inline ll gcd(ll a, ll b){ll r; while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a, ll b){return a/gcd(a, b)*b;}
struct PhanSo{
    int tu, mau;
    friend istream& operator>>(istream &in, PhanSo &a){
        cout<<"Nhap tu so: "; in>>a.tu;
        cout<<"Nhap mau so: "; in>>a.mau;
        while(!a.mau){
            cout<<"Nhap lai mau so khac 0: ";
            in>>a.mau;
        }
        return in;
    }
    friend bool operator<(const PhanSo a, const PhanSo b){
        return a.tu*b.mau<b.tu*a.mau;
    }
    friend bool operator>(const PhanSo a, const PhanSo b){
        return a.tu*b.mau>b.tu*a.mau;
    }
    friend bool operator<=(const PhanSo a, const PhanSo b){
        return a.tu*b.mau<=b.tu*a.mau;
    }
    friend bool operator>=(const PhanSo a, const PhanSo b){
        return a.tu*b.mau>=b.tu*a.mau;
    }
    friend bool operator==(const PhanSo a, const PhanSo b){
        return a.tu*b.mau==b.tu*a.mau;
    }
    friend bool operator!=(const PhanSo a, const PhanSo b){
        return a.tu*b.mau!=b.tu*a.mau;
    }
};
PhanSo toigian(PhanSo a);
void nhap(vector<PhanSo> &a, int n);
void nhap(PhanSo &a);
void nhap1(PhanSo &a);
void nhap2(PhanSo &b);
void xuat(PhanSo a);
PhanSo find(PhanSo a, PhanSo b);
ostream& operator<<(ostream &out, PhanSo a);
PhanSo operator++(PhanSo &a);
PhanSo operator++(PhanSo &a, int);
PhanSo operator+(PhanSo a, PhanSo b);
PhanSo operator+(int a, PhanSo b);
PhanSo operator-(PhanSo a, PhanSo b);
PhanSo operator*(PhanSo a, PhanSo b);
PhanSo operator/(PhanSo a, PhanSo b);
PhanSo timmax(vector<PhanSo> a, int n);
void xuatmang(vector<PhanSo> a, int n);
void sapxeptang(vector<PhanSo> &a);
void sapxepgiam(vector<PhanSo> &a);
PhanSo toigian(PhanSo a){
    int ucln=gcd(abs(a.tu), abs(a.mau));
    a.tu/=ucln;
    a.mau/=ucln;
    if(a.mau<0){
        a.tu=-a.tu; 
        a.mau=-a.mau;
    }
    return a;
}
void nhap(vector<PhanSo> &a, int n){
    foru(i, 0, n){
        PhanSo p;
        cout<<"Nhap phan so thu "<<i+1<<endl;
        cin>>p;
        p=toigian(p);
        a.pb(p);
    }
}
void nhap(PhanSo &a){
    cin>>a;
}
void nhap1(PhanSo &a){
    cout<<"Nhap phan so thu nhat: "<<endl;
    cin>>a;
}
void nhap2(PhanSo &b){
    cout<<"Nhap phan so thu hai: "<<endl;
    cin>>b;
}
void xuat(PhanSo a){
    if(!a.mau){
        cout<<"Khong xac dinh"<<endl;
        return;
    }
    else if(!a.tu){
        cout<<"0"; return;
    }
    int ucln=gcd(abs(a.tu), abs(a.mau));
    a.tu/=ucln;
    a.mau/=ucln;
    if(a.mau<0){
        a.tu=-a.tu;
        a.mau=-a.mau;
    }
    if(a.mau==1) cout<<a.tu;
    else cout<<a.tu<<"/"<<a.mau;
}
PhanSo find(PhanSo a, PhanSo b){
    a=toigian(a); b=toigian(b);
    int bcnn=lcm(a.mau, b.mau);
    a.tu*=(bcnn/a.mau); b.tu*=(bcnn/b.mau);
    if(a.tu<b.tu){
        cout<<"Phan so lon nhat trong 2 phan so la: "<<endl;
        return b;
    }
    else if(a.tu>b.tu){
        cout<<"Phan so lon nhat trong 2 phan so la: "<<endl;
        return a;
    }
    else{
        cout<<"Hai phan so bang nhau la bang: "<<endl;
        return a;
    }
}
ostream& operator<<(ostream &out, PhanSo a){
    xuat(a);
    return out;
}
PhanSo operator++(PhanSo &a){
    a.tu+=a.mau;
    return a;
}
PhanSo operator++(PhanSo &a, int){
    PhanSo temp=a;
    a.tu+=a.mau;
    return temp;
}
PhanSo operator+(PhanSo a, PhanSo b){
    a=toigian(a); b=toigian(b);
    int bcnn=lcm(a.mau, b.mau);
    a.tu*=(bcnn/a.mau); b.tu*=(bcnn/b.mau);
    PhanSo c;
    c.tu=a.tu+b.tu; c.mau=bcnn;
    return c;
}
PhanSo operator+(int a, PhanSo b){
    PhanSo tong;
    tong.tu=b.tu+b.mau*a;
    tong.mau=b.mau;
    return tong;
}
PhanSo operator+(PhanSo ps1, int a)
{
    PhanSo tong;
    tong.tu=ps1.tu+a*ps1.mau;
    tong.mau=ps1.mau;
    return tong;
}
PhanSo operator-(PhanSo a, PhanSo b){
    a=toigian(a); b=toigian(b);
    int bcnn=lcm(a.mau, b.mau);
    a.tu*=(bcnn/a.mau); b.tu*=(bcnn/b.mau);
    PhanSo c;
    c.tu=a.tu-b.tu;
    c.mau=bcnn;
    return c;
}
PhanSo operator-(PhanSo ps1, int a)
{
    PhanSo hieu;
    hieu.tu=ps1.tu-a*ps1.mau;
    hieu.mau=ps1.mau;
    return hieu;
}
PhanSo operator-(int a, PhanSo ps1)
{
    PhanSo hieu;
    hieu.tu=a*ps1.mau-ps1.tu;
    hieu.mau=ps1.mau;
    return hieu;
}
PhanSo operator*(PhanSo a, PhanSo b){
    a=toigian(a); b=toigian(b);
    PhanSo c;
    c.tu=a.tu*b.tu; c.mau=a.mau*b.mau;
    return c;
}
PhanSo operator*(PhanSo ps1, int a)
{
    PhanSo tich;
    tich.tu=ps1.tu*a;
    tich.mau=ps1.mau;
    return tich;
}
PhanSo operator*(int a, PhanSo ps1)
{
    PhanSo tich;
    tich.tu=ps1.tu*a;
    tich.mau=ps1.mau;
    return tich;
}
PhanSo operator/(PhanSo a, PhanSo b){
    a=toigian(a); b=toigian(b);
    PhanSo c;
    if(!b.tu){
        cout<<"Phan so thu 2 tu khong duoc la 0"<<endl;
        return {0, 1};
    }
    c.tu=a.tu*b.mau; c.mau=a.mau*b.tu;
    return c;
}
PhanSo operator/(PhanSo ps1, int a)
{
    PhanSo thuong;
    thuong.tu=ps1.tu;
    thuong.mau=ps1.mau*a;
    return thuong;
}
PhanSo operator/(int a, PhanSo ps1)
{
    PhanSo thuong;
    thuong.tu=ps1.tu;
    thuong.mau=ps1.mau*a;
    return thuong;
}
PhanSo timmax(vector<PhanSo> a, int n){
    PhanSo max=a[0];
    foru(i, 0, n) if(a[i]>max) max=a[i];
    return max;
}
void xuatmang(vector<PhanSo> a, int n){
    if(!a.size()){
        cout<<"Mang rong"<<endl;
        return;
    }
    foru(i, 0, n){
        xuat(a[i]); cout<<endl;
    }
}
void sapxeptang(vector<PhanSo> &a){
    //sort(a.begin(), a.end());
    int n=a.size();
    foru(i, 0, n-1){
        foru(j, i+1, n){
            if(a[i]>a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}
void sapxepgiam(vector<PhanSo> &a){
    sort(a.begin(), a.end(), greater<PhanSo>());
}
int main(){
    int chon;
    PhanSo a, b;
    while(true){
        cout<<endl;
        cout<<"-------------------CHUONG TRINH XU LY PHAN SO----------------"<<endl;
        cout<<"0. Thoat chuong trinh"<<endl;
        cout<<"1. Nhap 1 phan so, rut gon va xuat ket qua"<<endl;
        cout<<"2. Nhap 2 phan so, tim phan so max va xuat ket qua"<<endl;
        cout<<"3. Nhap 2 phan so, tinh tong hieu tich thuong cua chung va xet ket qua"<<endl;
        cout<<"4. Nhap day n phan so, tim phan so lon nhat, sap xep day tang dan, giam dan"<<endl;
        cout<<"------------------------------------------------------------ "<<endl;
        cout<<"Ban chon: "; cin>>chon;
        if(!chon){
bye:
            cout<<"Dang thoat chuong trinh...."<<endl;
            break;
        }
        else if(chon==1){
            nhap(a); 
            cout<<"Phan so la: "<<endl; xuat(a);
        }
        else if(chon==2){
            nhap1(a); nhap2(b);
            PhanSo c=find(a, b);
            xuat(c);
        }
        else if(chon==3){
try_again:
            nhap1(a); nhap2(b);
            PhanSo cong=a+b;
            PhanSo tru=a-b;
            PhanSo nhan=a*b;
            PhanSo chia=a/b;
            while(true){
                cout<<"Ban co cac lua chon la:"<<endl;
                cout<<"0. Khong muon tinh tong hieu tich thuong nua"<<endl;
                cout<<"1. Thoat chuong trinh"<<endl;
                cout<<"2. Tinh tong 2 phan so"<<endl;
                cout<<"3. Tinh hieu 2 phan so"<<endl;
                cout<<"4. Tinh tich 2 phan so"<<endl;
                cout<<"5. Tinh thuong 2 phan so"<<endl;
                cout<<"6. Toi muon doi phan so khac"<<endl;
                cout<<"Lua chon cua ban la:"<<endl;
                int chon1; cin>>chon1;
                if(!chon1) break;
                else if(chon1==1) goto bye;
                else if(chon1==2){
                    cout<<"Tong 2 phan so la: "; 
                    xuat(a); cout<<" + "; xuat(b); cout<<" = ";
                    xuat(cong); cout<<endl; 
                }
                else if(chon1==3){
                    cout<<"Hieu 2 phan so la: "; 
                    xuat(a); cout<<" - "; xuat(b); cout<<" = ";
                    xuat(tru); cout<<endl;
                }
                else if(chon1==4){
                    cout<<"Tich 2 phan so la: ";
                    xuat(a); cout<<" x "; xuat(b); cout<<" = "; 
                    xuat(nhan); cout<<endl; 
                }
                else if(chon1==5){
                    cout<<"Thuong 2 phan so la: "; 
                    xuat(a); cout<<" / "; xuat(b); cout<<" = ";
                    xuat(chia);
                }
                else if(chon1==6) goto try_again;
                else cout<<"Ban nhap sai roi, moi ban nhap lai"<<endl;
            }
        }
        else if(chon==4){
try_again1:
            vector<PhanSo> ve;
            cout<<"Nhap so luong phan tu: ";
            int n; cin>>n;
            nhap(ve, n);
            PhanSo max=timmax(ve, n);
            while(true){
                cout<<"Ban co cac lua chon la:"<<endl;
                cout<<"0. Khong muon tim lon nhat va sap xep nua"<<endl;
                cout<<"1. Thoat chuong trinh"<<endl;
                cout<<"2. Tim phan so lon nhat"<<endl;
                cout<<"3. Sap xep phan so khong giam"<<endl;
                cout<<"4. Sap xep phan so giam dan"<<endl;
                cout<<"5. Toi muon doi mang khac"<<endl;
                cout<<"Lua chon cua ban la:"<<endl;
                int chon1; cin>>chon1;
                if(!chon1) break;
                else if(chon1==1) goto bye;
                else if(chon1==2){
                    cout<<"Phan so lon nhat la: "; xuat(max); cout<<endl;
                }
                else if(chon1==3){
                    cout<<"Day sap xep khong giam la: "<<endl; sapxeptang(ve); xuatmang(ve, n);
                }
                else if(chon1==4){
                    cout<<"Day sap xep day giam dan: "<<endl; sapxepgiam(ve); xuatmang(ve, n);
                }
                else if(chon1==5) goto try_again1;
                else cout<<"Ban nhap sai roi, moi ban nhap lai"<<endl;
            }
        }
        else{
            cout<<"Ban nhap sai roi, moi ban nhap lai"<<endl;
        } 
    }
    return 0;
}