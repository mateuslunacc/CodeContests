
#include <iostream>

using namespace std;

#define ll long long

ll pow10(ll n) {
    static ll pow10[10] = {
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 
        100000000, 1000000000};

    return pow10[n]; 
}

ll digits (ll num) {
	ll d = 1, n = num;
	
	while (n > 9) {
		n /= 10;
		d++;
	}
	
	return d;
}

ll fac (ll num) {
	ll n = 0;
	
	for (ll i = 0; i < num; i++) {
		n += pow10(i);
	}

	return n;
}

int main() {
	ll n, d;
	
	cin >> n;
	d = digits(n);
	
	cout << d*(n + 1) - fac(d) << endl;
	
	return 0;
}
