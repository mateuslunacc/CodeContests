
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	
	ll n;
	string s;
	vector <ll> l;
	vector <ll> r;
	bool found = false;

	cin >> n;
	cin >> s;
	
	for (ll i = 0; i < n; i++) {
		ll p;
		cin >> p;
		if (s[i] == 'L') l.push_back(p);
		else if (s[i] == 'R') r.push_back(p);
	}
	
	if (l.size() > 0) sort(l.begin(), l.end());
	else l.push_back(-1);
	
	if (r.size() > 0) sort(r.begin(), r.end());
	else r.push_back(-1);
		
	for (int i = 0; i < r.size() && !found; i++) {
		for (int j = 0; j < l.size() && !found; j++) {
			if (r[i] - l[j] <= 0) {
				cout << (l[j] - r[i])/2 << endl;
				found = true;
			} 
		}
	}
	
	if (!found) {
		cout << -1 << endl;
	}
	
	return 0;
}
