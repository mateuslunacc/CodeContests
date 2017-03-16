
#include <bits/stdc++.h>

using namespace std;

#define MAX 22

int main () {
	int n, p, t[MAX], a[MAX], dp, dt[MAX];
	
	scanf("%d", &n);
	
	while (n) {
	
		for (int i = 0; i < MAX; i++) {
			t[i] = INT_MAX;
			a[i] = INT_MAX;
			dp[i] = -INT_MAX;
			dt[i] = -INT_MAX;
		}

		scanf("%d", &p);
		
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &t[i], &a[i]);
			
		}
		
		dt[0] = 0; //total time
		dp = 0; //total pizzas
		for (int i = 1; i <= p; i++) {
			for (int j = 0; j < n; j++){
				if (dp + a[j] <= p) {
					//printf("%d\n", dp[i]);
					dt[i] = max(dp[i], dp[p - a[j]] + t[j]);
					if (dp < dt[i - t[j]] + 1) {
						dt[i] = dt[i];
					}
				}
			}
		}
		
		printf("%d\n", dp[p]);
		
		scanf("%d", &n);
	}
	
	return 0;
}
