#include<iostream>
#include<cmath>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect r1,Rect r2){
	double area;
	
	
	if((r1.x + r1.w<=r2.x and r1.y + r1.h>=r2.h) or (r2.x + r2.w <= r1.x and r2.y + r2.h >= r1.y)){
		return 0;
	}
	else if(((r1.x +r1.w <= r2.x +r2.w)and r2.x<r1.x)){
		area=r1.w*r1.h;
		return area;
	}
	else if(((r2.x +r2.w <= r1.x +r1.w)and r1.x<r2.x)){
		area=r2.w*r2.h;
		return area;
	}
	else if (r1.x < r2.x) {
		double ovw = abs(r2.x-(r1.x+r1.w));
		double ovh = abs(r2.y-(r1.y +r1.h));
		
		area=ovw*ovh;
		
		return area;
	}
	else if (r1.x>r2.x) {
		double ovw = abs(r1.x-(r2.x+r2.w));
		double ovh = abs(r1.y-(r2.y +r2.h));
		
		area=ovw*ovh;
		
		return area;
	} 
}

int main(){
	double x,y,w,h,x2,y2,w2,h2;
	
	cout << "Please input Rect 1 (x y w h): ";
	cin>>x>>y>>w>>h;
	Rect Rect1 = {x,y,w,h};
	cout << "Please input Rect 2 (x y w h): ";
	cin>>x2>>y2>>w2>>h2;
	Rect Rect2 = {x2,y2,w2,h2};
	cout << "Overlap area = ";
	cout<<overlap(Rect1,Rect2);
	return 0;
}
