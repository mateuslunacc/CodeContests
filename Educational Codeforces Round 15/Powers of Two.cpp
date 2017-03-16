

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

//int 10^5, ll 10^18
#define MAX 1000001
#define ll long long
#define vi vector <int>
#define vll vector <ll>

int main () {
	
	int n;
	vll num;
	ll p = 0;
	
	scanf("%d", &n);
	
	for (int i = 0 ; i < n; i++) {
		ll a;
		scanf("%I64d", &a);
		num.push_back(a);
		
	}
	
	for (int i = 0 ; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			ll x = (num[i] + num[j]);
			if (!(x == 0) && !(x & (x - 1))) {
				p++;
				//cout << x << endl;
			}
			
		}
	}
	
	cout << p << endl;
	
	return 0;
}
