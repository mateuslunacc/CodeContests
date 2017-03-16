#include <stdio.h>
#include <algorithm>
#include <queue>
 
using namespace std;
 
//int 10^5, ll 10^18
#define MAX 100001
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pb push_back

vll adj[MAX];
vll dist;
ll o, d, k, ans = -1;

bool valid (ll x) {
	return (x > 0 && x < MAX);
}

void create_children (ll x) {
	ll children[] = {x/2, x*2, x*3, x+1, x-1};
	bool valids[] = 
	{x%2==0 && x, valid(x*2), valid(x*3), valid(x+1), valid(x-1)};
	
	for (int i = 0; i < 5; i++) {		
		if (valids[i]) {
			if (adj[children[i]].size()) {
				if (adj[children[i]][0]) {
					adj[x].pb(children[i]);
				}
			} else {
				adj[x].pb(children[i]);
			}
		}
	}
}

void bfs(ll vertice) {
	queue<ll> q; 

	q.push(vertice);
	dist[vertice] = 0;
 
	while (!q.empty()) {
		vertice = q.front();
		q.pop();

		if (vertice == d) {
			ans = dist[vertice];
			break;
		} else {
			create_children(vertice);
			
			for (int i = 0; i < (int) adj[vertice].size(); i++) {
				//printf("father: %I64d child: %I64d\n", vertice, adj[vertice][i]);
				
				if (dist[adj[vertice][i]] > dist[vertice] + 1) {
					dist[adj[vertice][i]] = dist[vertice] + 1;
					q.push(adj[vertice][i]);
				}
			}
		}
	}
}

int main(){
	scanf("%I64d%I64d%I64d", &o, &d, &k);

	while (o || d || k) {
		for (ll i = 0; i < MAX; i++) {
			dist.pb(MAX);
			adj[i].clear();
		}
		
		for (int i = 0; i < k; i++) {
			ll b;
			scanf("%I64d", &b);
			adj[b].pb(0);
		}
		
		bfs(o);
	 
		printf("%I64d\n", ans);
		
		dist.clear();
		ans = -1;
		
		scanf("%I64d%I64d%I64d", &o, &d, &k);
	}

	return 0;
}
