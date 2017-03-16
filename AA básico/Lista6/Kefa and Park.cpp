
#include <stdio.h>
#include <algorithm>
#include <queue>
 
using namespace std;
 
//int 10^5, ll 10^18
#define MAX 10009
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pb push_back

vi adj[MAX];
vi dist;
bool cats[MAX];
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
 
		for (int i = 0; i < (int) adj[vertice].size(); i++) {
			if (dist[adj[vertice][i]] > dist[vertice] + 1) {
				if (adj[vertice][i] == m) {
					ans = dist[adj[vertice][i]];
					found = true;
				}
				dist[adj[vertice][i]] = dist[vertice] + 1;
				q.push(adj[vertice][i]);
			}
		}
	}
}
 
int main(){	
	for (int i = 0; i < MAX; i++) {
		dist.pb(MAX);
	}
 
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		int cat;
		scanf("%d", &cat);
		cats[i] = cat ? true : false;
	}
	
	for (int i = 1; i < n; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		adj[v1].pb(v2);
	}
	
	bfs(n);
 
	printf("%d\n", ans);
 
	return 0;
}
