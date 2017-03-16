
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1000001
#define ll long long
#define vi vector <int>
#define vll vector <ll>

int main () {
	ll n, m, sum = 0;
	vll w;
	
	scanf("%I64d", &n);
		
	for (ll i = 0; i < n; i++) {
		ll p;
		scanf("%I64d", &p);
		
		for (ll j = 0; j < p; j++) {
			w.push_back(i+1);
		}
		sum += p;
	}
	
	scanf("%I64d", &m);
	
	for (ll i = 0; i < m; i++) {
		ll j;
		scanf("%I64d", &j);
		
		printf("%I64d\n", w[--j]);
	}
	
	return 0;
}
