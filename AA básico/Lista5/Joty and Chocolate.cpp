#include <iostream>

#define li long long

using namespace std;

li n, a, b, p, q;

bool read() {
	return (cin >> n >> a >> b >> p >> q);
}

//greatest common divisor
li gcd(li a, li b) { return !a ? b : gcd(b % a, a); }

//least common multiple
li lcm(li a, li b) { return a / gcd(a, b) * b; }

void solve() {
	li ans = 0;
	ans += (n / a) * p;
	ans += (n / b) * q;
	ans -= (n / lcm(a, b)) * min(p, q);
	cout << ans << endl;
}

int main () {
	read();
	solve();
	
}
