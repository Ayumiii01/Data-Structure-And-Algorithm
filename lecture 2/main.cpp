#include <iostream>
#include "point.hpp"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
int *midpoint(int x1, int x2, int y1, int y2) {
	int mid_x = (x1 + x2) / 2;
	int mid_y = (y1 + y2) / 2;
	static int arr[] = {mid_x, mid_y};
	return arr;
} 
*/



int main(int argc, char** argv) {
	//Point point1 = {2, 4};
	cout << "Size of: " << sizeof(Point) << endl;
	
	Point* point1 = new Point;
	point1->x = -2;
	point1->y = -1;
	
	Point* point2 = new Point;
	point2->x = 8;
	point2->y = 5;
	
	Point* res = point2 -> midpoint(point1);
	
	cout << "The midpoint is: " << "(" << res->x << ", " << res->y << ")" << endl;;
	
	return 0;
}