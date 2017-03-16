
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//int 10^5, ll 10^18
#define MAX 1000001
#define ll long long
#define vi vector <int>
#define vll vector <ll>

int main () {
	ll n, last = 0, a, maxl= 0, sum = 0;
	
	cin >> n;
	
	for (int i =0; i < n; i++) {
		scanf ("%I64d", &a);
		
		if (a > last) {
			sum ++;
		} else {
			sum = 1;
		}
		if (maxl < sum) {
			maxl = sum;
		}
		
		last = a;
		//printf("a: %I64d last: %I64d sum: %I64d maxl: %I64d\n", a, last, sum, maxl);
	}
	
	cout << maxl << endl;

	return 0;
}
