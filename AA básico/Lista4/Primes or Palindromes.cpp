#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define MAX 1001

bool palindrome(ll num) {
	bool p;

	string fh = to_string(num);
	fh = fh.substr(0, fh.size()/2);
	
	string sh = to_string(num);
	sh = sh.substr((sh.size()/2) + (sh.size()%2), sh.size());
	reverse(sh.begin(), sh.end());
	
	if (!fh.compare(sh)) p = true;
	else p = false;
	
	return p;
}

vector <bool> primes (ll n) {
	vector <bool> p(n, true);
	p[0] = false;
	p[1] = false;
	
	for (int i = 2; i < n; i++) {
		if (p[i]) {
			for (int j = i; j < n; j+=i) {
				p[j] = false;
			}
		}
	}
	
	return p;
}


int main () {
	ll p, q;
	vector <bool> prime = primes(MAX);
	ll palindromes[5] = {0};
	
	for (int i = 1; i < 5; i++) {
		palindromes[i] = palindromes[i-1] + round(pow(10, (i - i%2)/2 + 1));
		//cout << palindromes[i] << endl;
	}
	
	cin >> p >> q;
	p /= q;
	
	if (palindrome(p)) cout << "Y" << endl;
	else cout << "N" << endl;
	
	return 0;
}
