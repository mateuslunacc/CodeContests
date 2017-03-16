#include <stdio.h>
#include <algorithm>
#include <queue>
 
using namespace std;
 
//int 10^5, ll 10^18
#define MAX 10000
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pb push_back

vll adj[6*MAX];
vll dist;
ll n, m, ans = -1;

bool valid (ll x) {
	return ((x < MAX) && (x > -MAX));
}

void bfs(ll vertice) {
	queue<ll> q; 
	ll pos = 3*MAX + vertice;
	q.push(vertice);
	dist[pos] = 0;
 
	while (!q.empty()) {
		vertice = q.front();
		q.pop();

		pos = 3*MAX + vertice;

		if (vertice == m) {
			ans = dist[pos];
			break;
		} else {
			
			if (valid(vertice)) {
				adj[pos].pb(vertice/2);
				adj[pos].pb(vertice/3);
				adj[pos].pb(vertice-7);			
				adj[pos].pb(vertice*2);
				adj[pos].pb(vertice*3);
				adj[pos].pb(vertice+7);
				
				for (int i = 0; i < (int) adj[pos].size(); i++) {
					//printf("father: %I64d child: %I64d -- dist: %I64d\n", vertice, adj[pos][i], dist[3*MAX + adj[pos][i]]);
					
					if (dist[3*MAX + adj[pos][i]] > dist[pos] + 1) {
						dist[3*MAX + adj[pos][i]] = dist[pos] + 1;
						q.push(adj[pos][i]);
					}
				}
			}
		}
	}
}
 
int main(){
	for (ll i = 0; i < 6*MAX; i++) {
		dist.pb(4*MAX);
	}
 
	scanf("%I64d%I64d", &n, &m);
 
	bfs(n);
 
	printf("%I64d\n", ans);
 
	return 0;
}
