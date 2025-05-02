#include<iostream>
#include<cmath>
using namespace std;
class CDate{
	private:
		int iNgay;
		int iThang;
		int iNam;
	public:
		CDate(int date=1, int month=1, int year=1){
			iNgay = date;
			iThang = month;
			iNam = year;
		}
		CDate (int t){
			iNgay=t;
			iThang=0;
			iNam=0; 
		} 
		friend istream& operator>>(istream&, CDate&);
		friend ostream& operator<<(ostream&, const CDate&);
		CDate operator++();
		CDate operator--();
		CDate operator+(const int& );
		CDate operator-(const int& );
		int operator-(CDate&); 
		bool CheckNhuan();
		int CovertCDatetoDate();
}; 
    
    bool CDate::CheckNhuan(){
    	if(iNam%400==0) return 1;
    	else if(iNam%4==0 && iNam%100!=0) return 1;
    	else return 0;
	}
	
   //overload Nhap
  istream& operator>>(istream& cin, CDate& t){
  	cin>>t.iNgay>>t.iThang>>t.iNam;
  	return cin;
  }
  
  //overload Xuat
  ostream& operator<<(ostream& cout, const CDate& t){
  	cout<<t.iNgay<<"/"<<t.iThang<<"/"<<t.iNam;
  }
  
  //overload ++tien to
  CDate CDate::operator++(){
  	switch (iThang){
  		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
  			if(iNgay==31){
  				if(iThang==12){
  					iNam++;
  					iNgay=1;
  					iThang=1;
				  }
				else {
					iNgay=1;
					iThang++;
				}
			  }
			  
			else {
				iNgay++;
			}
			break;
		  
		case 4: case 6: case 9: case 11:
			if(iNgay==30){
				iNgay=1;
				iThang++;
			}
			else iNgay++;
			break;
			
		case 2:
			if(this->CheckNhuan()){
				if(iNgay==29){
					iNgay=1;
					iThang++;
				}
				else iNgay++;
			}
			
			else {
				if(iNgay==28){
					iNgay=1;
					iThang++;
				}
				else iNgay++;
			}
			break;
			default:
				cout<<"Ko hop le";
	  }
  		return *this;
  }
  
  //overload --tien to
  CDate CDate::operator--(){
  	if(iNgay==1){
  		--iThang;
  		switch (iThang){
  			case 0: case 1: case 3: case 5: case 7: case 8: case 10: case 12:
  				iNgay=31;
  				if(iThang==0){
  					iThang=12;
  					iNam--;
				  }
  				break;
  				
  			case 4: case 6: case 9: case 11:
  				iNgay=30;
  				break;
  				
  			case 2:
  				if(this->CheckNhuan()) iNgay=29;
  				else iNgay=28;
  				break;
		  }
	  }
	  
	else iNgay--;
	
	return *this;
  }
  
  CDate CDate::operator+(const int& t){
  	for(int i=1; i<=t; i++){
  		++*this;
	  }
	  return *this;
  }
  
  CDate CDate::operator-(const int& t){
  		for(int i=1; i<=t; i++){
  		--*this;
	  }
	  return *this;
  }
  
  int CDate::CovertCDatetoDate(){
  	int SoNgay=0; 
  	for(int i=0;i<iThang;i++){
  		if(i==0) SoNgay+=iNgay;
  		else if(i==4||i==6||i==9||i==11) SoNgay+=30;
  		else if(i==2){
  			if(this->CheckNhuan()) SoNgay+=29;
  			else SoNgay+=28;
		  }
  		else SoNgay+=31;
	  }
	  return SoNgay;
  }
  
int CDate::operator-(CDate& t){
	if(iNam==t.iNam){
		int t1 = CovertCDatetoDate();
  	int t2 = t.CovertCDatetoDate();
  	int k;
  	return k=abs(t1-t2);
	}
	
	else {
		int SoNgay=0;
		CDate NamDau, NamCuoi;
		if(iNam>t.iNam){
			NamDau.iNam = t.iNam;
			NamCuoi.iNam = iNam;
		}
		
		else{
			NamDau.iNam = iNam;
			NamCuoi.iNam = t.iNam;
		}
		
		for(int i=NamDau.iNam; i<=NamCuoi.iNam; i++){
			//so ngay o nam dau tien 
		    if(i==NamDau.iNam){
		    	if(NamDau.CheckNhuan()) SoNgay+=(366-NamDau.CovertCDatetoDate()+1);
		    	else SoNgay+=(365-NamDau.CovertCDatetoDate()+1);
			}
			//so ngay nam cuoi cung
			else if(i==NamCuoi.iNam){
				SoNgay+=NamCuoi.CovertCDatetoDate();
			}
			
			//tong so ngay cac nam khoang giua
			else{
				if(i%400==0 || (i%4==0 && i%100!=0)) SoNgay+=366;
				
			else SoNgay+=365;
			}
			
		}
		return SoNgay;
	}
  		
}
