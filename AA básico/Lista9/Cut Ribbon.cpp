
#include <bits/stdc++.h>

using namespace std;

#define MAX 4004
#define LENGHTS 3

int main () {
	int n, r[LENGHTS];
	int dp[MAX];
	
	cin >> n;
	
	for (int i = 0; i < LENGHTS; i++) 
		cin >> r[i];
	
	for (int i = 0; i <= n; i++)
		dp[i] = -MAX;
	
	dp[0] = 0;
	for (int l = 1; l <= n; l++) {
		for (int p = 0; p < LENGHTS; p++){
			if (r[p] <= l) {
				dp[l] = max(dp[l], dp[l - r[p]] + 1);
			}
		}
	}
	
	cout << dp[n] << endl;
	
	return 0;
}
