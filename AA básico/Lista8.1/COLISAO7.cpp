#include <bits/stdc++.h>

using namespace std;

class Rectangle {
	public: 
	
	int x0, y0, x1, y1;
	
	Rectangle(int xi, int yi, int xf, int yf) {
		x0 = xi;
		y0 = yi;
		x1 = xf;
		y1 = yf;
	}
	
	void print() {
		printf("%d %d %d %d\n", x0, y0, x1, y1);
	}
	
	bool colision(Rectangle o) {
		return !(x1 < o.x0 || y1 < o.y0 || o.x1 < x0 || o.y1 < y0);
	}
};

int main () {
	int x0, y0, x1, y1;
	
	scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
	Rectangle r1 (x0, y0, x1, y1);
	//r1.print();
	
	scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
	Rectangle r2 (x0, y0, x1, y1);
	//r2.print();
	
	if (r1.colision(r2)) {
		puts("1");
	} else {
		puts("0");
	}
	
	return 0;
}
