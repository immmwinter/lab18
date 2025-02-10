#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect * R1, Rect * R2) {
    double left = (R1->x > R2->x) ? R1->x : R2->x;
    double right = (R1->x + R1->w < R2->x + R2->w) ? R1->x + R1->w : R2->x + R2->w;
    double bottom = (R1->y - R1->h > R2->y - R2->h) ? R1->y - R1->h : R2->y - R2->h;
    double top = (R1->y < R2->y) ? R1->y : R2->y;

    double width = right - left;
    double height = top - bottom;

    if (width <= 0 || height <= 0) return 0;

    return width * height;
}

int main(){
	Rect R1 = {1,1,5,5};
	Rect R2 = {2,2,5,5};
	Rect *r1 = &R1;
	Rect *r2 = &R2;
	cout << overlap(r1,r2);

}
