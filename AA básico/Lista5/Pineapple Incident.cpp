
#include <iostream>

using namespace std;

int main() {
	int t, s, x;
	bool barks = false;
	
	cin >> t >> s >> x;

	if (t == x) barks = true;
	
	for (int i = 1; t + s*i <= x; i++) {
		if (t + s*i == x) barks = true;
		if (t + (s*i) + 1 == x) barks = true;
		//cout << t + s*i << endl;
	}
	
	if (barks) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
