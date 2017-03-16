
#include <bits/stdc++.h>

using namespace std;

int main () {
	double r, x, y, xi, yi;
	
	cin >> r >> x >> y >> xi >> yi;
	
	double d = sqrt((xi - x)*(xi - x) + (yi - y)*(yi - y));

	cout << ceil(d/2*r) << endl;
	
	printf("%L\n", ceil(d/2*r));
	
	return 0;
}
