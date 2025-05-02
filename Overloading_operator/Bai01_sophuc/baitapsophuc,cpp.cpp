#include<iostream>
#include"sophuc.cpp"
using namespace std;
int main(){
	sophuc a(1,2);
    sophuc b(3,4);
    sophuc c = a - b;
	c.xuat();
}
