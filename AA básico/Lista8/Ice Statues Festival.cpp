
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000010
#define ll long long int

int main (){
	ll t, n, m;
	ll blocks[MAX], dp[MAX];
	
	scanf("%I64d", &t);
	while (t--) {
		scanf("%I64d%I64d", &n, &m);
				
		for (int i = 0; i < n; i++) {
			scanf("%I64d", &blocks[i]);
		}

		for (int i = 1; i <= m; i++) {
			dp[i] = MAX;
		}

		dp[0] = 0;
		
		for (int i = 0; i < n; i++) {
			for (ll v = 0; v <= m; v++) {
				//printf("dp[v]: %I64d  v: %I64d\n", dp[v], v);
				if (blocks[i] <= v) {
					if (dp[v - blocks[i]] + 1 < dp[v]) {
						dp[v] = dp[v - blocks[i]] + 1;
					}
				}
			}
		}
		
		//for (ll i = 0; i <= m; i++) printf("%I64d : %I64d\n", i, dp[i]);
		cout << dp[m] << endl;
	}
	
	return 0;
}
