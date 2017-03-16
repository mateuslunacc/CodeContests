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
	ll n, h, k, p, t = 0, r = 0;
	
	scanf("%I64d%I64d%I64d", &n, &h, &k);
	
	for (ll i = 0; i < n; i++) {
		scanf("%I64d", &p);
		
		if ((p + r) > h) {
			t++;
			r = 0;
		}
		t += (p+r)/k;
		r = (p+r)%k;
		
		//printf("t: %d r: %d\n", t, r);
	}
	t += (r/k + (r%k? 1 : 0));
	
	printf("%I64d\n", t);
	
	return 0;
}
