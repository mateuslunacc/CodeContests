#include <stdio.h>
#include <algorithm>
#include <queue>
 
using namespace std;
 
//int 10^5, ll 10^18
#define MAX 20020
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pb push_back

vi adj[MAX];
vi dist;
int n, m, ans = 0;
int c = 0;
 
void bfs(int vertice) {
 
	queue<int> q;
	bool found = false;
 
	q.push(vertice);
	dist[vertice] = 0;
 
	while (!q.empty() && !found) {
 
		vertice = q.front();
		q.pop();
 
		if (vertice > 0) {
			adj[vertice].pb(vertice-1);
		}
 
		if (vertice * 2 < MAX) {
			adj[vertice].pb(vertice*2);
		}
 
		for (int i = 0; i < (int) adj[vertice].size(); i++) {
			if (dist[adj[vertice][i]] > dist[vertice] + 1) {
				dist[adj[vertice][i]] = dist[vertice] + 1;
				q.push(adj[vertice][i]);
				if (adj[vertice][i] == m) {
					ans = dist[adj[vertice][i]];
					found = true;
				}
			}
		}
	}
}
 
int main(){	
	for (int i = 0; i < MAX; i++) {
		dist.pb(MAX);
	}
 
	scanf("%d%d", &n, &m);
 
	bfs(n);
 
	printf("%d\n", ans);
 
	return 0;
}
