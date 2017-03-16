
#include <iostream>
#include <climits>

#define ll long long

using namespace std;

ll modpow(ll base, ll exp, ll modulus) {
	base %= modulus;
	ll result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % modulus;
		base = (base * base) % modulus;
		exp >>= 1;
	}
	return result;
}

int main() {
	ll r;
	
	cin >> r;
	
	cout << modpow(3, r, LONG_MAX) << endl;
	
	return 0;
}

