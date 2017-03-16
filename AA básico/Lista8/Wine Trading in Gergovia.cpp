#include <stdio.h>
#include <iostream>
 
using namespace std;
 
#define MAX 100001
#define ll long long
 
int main () {
	ll n, sum = 0, work = 0;
	ll m;
 
	cin >> n;
	while (n) {
 
		for (int i = 0; i < n; i++) {
			cin >> m;
			sum += m;
			work += (sum > 0? sum : -sum);
		}
 
		cout << work << endl;
		sum = 0;
		work = 0;
 
		cin >> n;
	}
 
	return 0;
}
