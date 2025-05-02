#include<iostream>
using namespace std;
class sophuc{
	private:
		double dThuc;
		double dAo;
		
	public:
		friend sophuc operator+(const sophuc& p1, const sophuc& p2);	
		friend sophuc operator-(const sophuc& p1, const sophuc& p2);
		friend sophuc operator*(const sophuc& p1, const sophuc& p2);
		friend sophuc operator/(const sophuc& p1, const sophuc& p2);
		bool operator==(const sophuc& p2); 
		bool operator!=(const sophuc& p2);
		friend istream& operator>>(istream&, sophuc&);
		friend ostream& operator<<(ostream&, const sophuc&);
		
		sophuc(double a=0, double b=0){
			dThuc=a;
			dAo=b;
		}
		
		sophuc(int a){
			dThuc = a;
			dAo = 0;
	}
};
    
    sophuc operator+(const sophuc& p1, const sophuc& p2){
   	    sophuc kq;
   	    kq.dThuc = p1.dThuc+ p2.dThuc;
   	    kq.dAo = p1.dAo + p2.dAo;
   	return kq;
   }
    
    sophuc operator-(const sophuc& p1, const sophuc& p2){
    	sophuc kq;
    	kq.dThuc = p1.dThuc - p2.dThuc;
    	kq.dAo = p1.dAo - p2.dAo;
    return kq;
	}
	
	sophuc operator*(const sophuc& p1, const sophuc& p2){
		sophuc kq;
		kq.dThuc = p1.dThuc*p2.dThuc- p1.dAo*p2.dAo;
		kq.dAo = p1.dThuc*p2.dAo + p1.dAo*p2.dThuc;
		return kq;
	}
	
	sophuc operator/(const sophuc& p1, const sophuc& p2){
		sophuc kq;
		kq.dThuc = (p1.dThuc*p2.dThuc+p1.dAo*p2.dAo)/(p2.dThuc*p2.dThuc + p2.dAo*p2.dAo);
		kq.dAo = (p1.dAo*p2.dThuc - p1.dThuc*p2.dAo)/(p2.dThuc*p2.dThuc + p2.dAo*p2.dAo);
		return kq;
	}
    
    bool sophuc::operator==(const sophuc& p2){
    	if(dThuc = p2.dThuc && dAo == p2.dAo) return true;
    	else return false;
	}
	
	bool sophuc::operator!=(const sophuc& p2){
			if(dThuc = p2.dThuc && dAo == p2.dAo) return false;
    	else return true;
	}
	
	istream& operator>>(istream& cin, sophuc& p){
		cin>>p.dThuc>>p.dAo;
		return cin;
	}
	ostream& operator<<(ostream& cout, const sophuc& p){
		cout<<p.dThuc<<"+"<<p.dAo<<"i";
		return cout;
	}
    
   
   
