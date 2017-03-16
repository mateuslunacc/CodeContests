
#include <stdio.h>
#include <algorithm>
#include <queue>
 
using namespace std;
 
//int 10^5, ll 10^18
#define MAX 10010
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pb push_back

vi adj[MAX];
vi dist;
int t, n, m, ans = 0;

int reverse (int i) {
	int r = 0;
	
	while(i) {
        r = r*10 + (i%10);
        i/=10;
    }
	
	return r;
}

bool valid (int x) {
	return (x < MAX);
}

void bfs(int vertice) {
	queue<int> q;
	bool found = false;
 
	q.push(vertice);
	dist[vertice] = 0;
 
	while (!q.empty() && !found) {
 
		vertice = q.front();
		q.pop();
 
		int num = reverse(vertice);
		if (valid(vertice+1)) adj[vertice].pb(vertice+1);
		if (valid(num)) adj[vertice].pb(num);
 
		for (int i = 0; i < (int) adj[vertice].size(); i++) {
			//printf("v: %d - child: %d\n", vertice, adj[vertice][i]);
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
	scanf("%d", &t);
	
	while (t--) {
		for (int i = 0; i < MAX; i++) {
			dist.pb(MAX);
			adj[i].clear();
		}
		
		ans = 0;
		
		scanf("%d%d", &n, &m);
		
		bfs(n);
	 
		printf("%d\n", ans);
		dist.clear();
	}
 
	return 0;
}
