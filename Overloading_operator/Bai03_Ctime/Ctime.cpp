#include<iostream>
using namespace std;
class Ctime{
	private:
		int iHour;
		int iMinute;
		int iSecond;
		
	public:
		Ctime(int h=0, int m=0, int s=0){
			iHour = h;
			iMinute = m;
			iSecond = s;
		}
		
		int ConvertCtimetoSecond();
		Ctime ConvertSecondtoCtime(int t);
		friend istream& operator>>(istream& cin, Ctime& );
		friend ostream& operator<<(ostream& cout, const Ctime&);
		Ctime operator+(const int&);
		Ctime operator-(const int&);
		Ctime operator++();
		Ctime operator++(int);
		Ctime operator--();
		Ctime operator--(int); 
			
}; 

     
     Ctime Ctime::operator++(int){
     	Ctime k1 = *this;
		  int k = this->ConvertCtimetoSecond();
     	    k++;
     	    *this = this->ConvertSecondtoCtime(k);
     	    return k1;
	 }  
	 
     Ctime Ctime::operator++(){
     	    int k = this->ConvertCtimetoSecond();
     	    k++;
     	    *this = this->ConvertSecondtoCtime(k);
     	    return *this;
	 }
	 Ctime Ctime::operator--(int){
     	Ctime k1 = *this;
		  int k = this->ConvertCtimetoSecond();
     	    k--;
     	    *this = this->ConvertSecondtoCtime(k);
     	    return k1;
	 }  
	 
     Ctime Ctime::operator--(){
     	    int k = this->ConvertCtimetoSecond();
     	    k--;
     	    *this = this->ConvertSecondtoCtime(k);
     	    return *this;
	 }
	 
int Ctime::ConvertCtimetoSecond(){
	int second = iHour*3600 + iMinute*60 + iSecond;
	if(second>86400) second-=86399;
	return second;
}

Ctime Ctime::ConvertSecondtoCtime(int t){
	Ctime temp;
	if(t<0) t=86399+t+1;
	
	temp.iHour = t / 3600;
    t %= 3600;
    temp.iMinute = t / 60;
    t%=60;
    temp.iSecond = t;
    if(temp.iHour==24) temp.iHour=0;
    
      return temp;
}

istream& operator>>(istream& cin, Ctime& t){
	cin>>t.iHour>>t.iMinute>>t.iSecond;
	return cin;
}

ostream& operator<<(ostream& cout, const Ctime& t){
	cout<<t.iHour<<":"<<t.iMinute<<":"<<t.iSecond;
	return cout;
}

Ctime Ctime::operator+(const int& t){
	Ctime k;
	int t1 = ConvertCtimetoSecond();
	int tq = t1 + t;
	k = ConvertSecondtoCtime(tq);
	return k;
} 

Ctime Ctime::operator-(const int& t){
	Ctime k;
	int t1 = ConvertCtimetoSecond();
	int tq = t1 - t;
	k = ConvertSecondtoCtime(tq);
	return k;
} 


