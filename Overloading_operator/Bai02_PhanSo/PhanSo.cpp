#include<iostream>
using namespace std;

class PhanSo{
	private:
	    int iTu, iMau;
		
	public:
	    PhanSo(int a=0, int b=1){
	    	iTu=a;
	    	iMau = b;
		} 
		
		PhanSo(int k){
			iTu = k;
			iMau = 1;
		}
		
		friend PhanSo operator+(const PhanSo& ps1, const PhanSo& ps2);
		friend PhanSo operator-(const PhanSo& ps1, const PhanSo& ps2);
		friend PhanSo operator*(const PhanSo& ps1, const PhanSo& ps2);
		friend PhanSo operator/(const PhanSo& ps1, const PhanSo& ps2);
		bool operator==(const PhanSo& ps);
		bool operator>(const PhanSo& ps);
		bool operator<(const PhanSo& ps);
		friend istream& operator>>(istream&, PhanSo&);
		friend ostream& operator<<(ostream&, const PhanSo&); 
		int ucln(int a, int b);
		void rutgon();
		friend PhanSo operator+ 
};
    int PhanSo::ucln(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void PhanSo::rutgon() {
    int gcd = ucln(iTu, iMau);
    iTu /= gcd; 
    iMau /= gcd; 

    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

  PhanSo operator+(const PhanSo& ps1, const PhanSo& ps2){
  	PhanSo kq;
  	kq.iTu = ps1.iTu*ps2.iMau + ps2.iTu*ps1.iMau;
  	kq.iMau = ps1.iMau*ps2.iMau;
  	kq.rutgon();
  	return kq;
  }
  
  PhanSo operator-(const PhanSo& ps1, const PhanSo& ps2){
  	PhanSo kq;
  	kq.iTu = ps1.iTu*ps2.iMau - ps2.iTu*ps1.iMau;
  	kq.iMau = ps1.iMau*ps2.iMau;
  	kq.rutgon();
  	return kq;
  }
  
  PhanSo operator*(const PhanSo& ps1, const PhanSo& ps2){
  	PhanSo kq;
  	kq.iTu = ps1.iTu * ps2.iTu;
  	kq.iMau = ps1.iMau * ps2.iMau;
  	kq.rutgon();
  	return kq;
  }
  
  PhanSo operator/(const PhanSo& ps1, const PhanSo& ps2){
  	PhanSo kq;
  	kq.iTu = ps1.iTu * ps2.iMau;
  	kq.iMau = ps1.iMau * ps2.iTu;
  	kq.rutgon();
  	return kq;
  }
  
  bool PhanSo::operator==(const PhanSo& ps){
  	double a = (double)iTu/iMau;
  	double b = (double)ps.iTu/ps.iMau;
  	if(a==b) return true;
  	else return false;
  }
  
  bool PhanSo::operator>(const PhanSo& ps){
  	double a = (double)iTu/iMau;
  	double b = (double)ps.iTu/ps.iMau;
  	if(a>b) return true;
  	else return false;
  }
  
  bool PhanSo::operator<(const PhanSo& ps){
  	double a = (double)iTu/iMau;
  	double b = (double)ps.iTu/ps.iMau;
  	if(a<b) return true;
  	else return false;
  }
  
  istream& operator>>(istream& cin, PhanSo& ps){
  	cin>>ps.iTu>>ps.iMau;
  	return cin;
  }
  
  ostream& operator<<(ostream& cout, const PhanSo& ps){
  	if(ps.iTu%ps.iMau == 0) cout<<ps.iTu/ps.iMau;
  	
  	else 
  	cout<<ps.iTu<<"/"<<ps.iMau;
  	return cout;
  }
