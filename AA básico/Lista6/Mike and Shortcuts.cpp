
#include <stdio.h>
#include <algorithm>
#include <queue>
 
using namespace std;
 
//int 10^5, ll 10^18
#define MAX 200022
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pb push_back
 
vll adj[MAX];
vll dist;
ll n;
 
void bfs(ll vertice) {
 
	queue<ll> q; 
	q.push(vertice);
	dist[vertice] = 0;
 
	while (!q.empty()) {
		vertice = q.front();
		q.pop();
 
		for (int i = 0; i < (ll) adj[vertice].size(); i++) {
			//printf("father: %I64d child: %I64d\n", vertice, adj[vertice][i]);
			if (dist[adj[vertice][i]] > dist[vertice] + 1) {
				dist[adj[vertice][i]] = dist[vertice] + 1;
				q.push(adj[vertice][i]);
			}
		}
	}
}
 
int main(){	
	ll edge;
	
	for (ll i = 0; i < MAX; i++) {
		dist.pb(MAX);
	}

	scanf("%I64d", &n);
	for (ll i = 1; i < n; i++) {
		scanf("%I64d", &edge);
		adj[i].pb(edge);
		adj[i].pb(i+1);
		adj[i+1].pb(i);
	}
	scanf("%I64d", &edge);
	adj[n].pb(edge);

	bfs(1);
 
 	//for (ll i = 0; i < n; i++) {
	
	for (ll i = 1; i <= n; i++) {
		printf("%I64d ", dist[i]);
	}
	printf("\n");
 
	return 0;
}
