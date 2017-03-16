#include <bits/stdc++.h>

using namespace std;

#define MAX 1000010
#define ll long long int
#define vll vector<ll>

ll n, m, k, v, e;
vll adj[MAX];
ll rep[MAX];

int main () {

	while(scanf("%I64d%I64d", &n, &m) != EOF) {
		for (int i = 0; i < MAX; i++) {
			rep[i] = 0;
			adj[i].clear();
		}
		
		for (ll i = 0; i < n; i++) {
			scanf("%I64d", &e);
			adj[e].push_back(i+1);
			rep[e]++;
		}
		
		for (ll i = 0; i < m; i++) {
			scanf("%I64d%I64d", &k, &v);
			
			if (rep[v] >= k--) {
				cout << adj[v][k] << endl;
			} else {
				printf("0\n");
			}
		}
	}
	return 0;
}
