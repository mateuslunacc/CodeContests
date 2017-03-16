
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
 
using namespace std;
 
//int 10^5, ll 10^18
#define MAX 1000001
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pb push_back

vll adj[MAX];
ll dist[MAX];
ll n;
ll farest = 1;
ll maxd = 0;

void bfs(int vertice) {
	queue<int> q;

	q.push(vertice);
	dist[vertice] = 0;
 
	while (!q.empty()) {
		vertice = q.front();
		q.pop();
 
		for (int i = 0; i < (int) adj[vertice].size(); i++) {
			//printf("v: %d - child: %d\n", vertice, adj[vertice][i]);
			if (dist[adj[vertice][i]] > dist[vertice] + 1) {
				dist[adj[vertice][i]] = dist[vertice] + 1;
				q.push(adj[vertice][i]);
				if (dist[adj[vertice][i]] > maxd) {
					farest = adj[vertice][i];
					maxd = dist[adj[vertice][i]];
				}
			}
		}
	}
}

void dist_clear() {
	for (int i = 0; i < MAX; i++) {
		dist[i] = MAX;
	}
}

int main(){
	ll x, y;
	
	dist_clear();
	
	scanf("%I64d", &n);
	
	for (int i = 1; i < n; i++) {
		scanf("%I64d%I64d", &x, &y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	
	bfs(1);
	
	dist_clear();
	
	bfs(farest);
	
	printf("%I64d\n", maxd);

	return 0;
}
