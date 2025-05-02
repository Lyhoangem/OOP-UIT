#include<iostream>
#include"CDate.cpp"
using namespace std;

int main(){
	CDate ngay1(15,8,2006);
	CDate ngay2(15,8,2007);
	int k = ngay2 - ngay1; 
	cout<<k;
}
