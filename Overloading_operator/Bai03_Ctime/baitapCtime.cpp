#include<iostream>
#include"Ctime.cpp"
using namespace std;

int main(){
	Ctime time(0,0,0);
	Ctime time1 = time-300;
	cout<<time1<<" "<<time;
	
}
