
#include <iostream>
#include <math.h>

#define ll long long

using namespace std;

int main() {
	ll n;
	
	cin >> n;
	
	cout << (ll) round(pow(3, 3*n)) - (ll) round(pow(7, n)) << endl;
	
	return 0;
}
