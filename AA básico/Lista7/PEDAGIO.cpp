
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
 
using namespace std;
 
//int 10^5, ll 10^18
#define MAX 254
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pb push_back

vi adj[MAX];
vi visited;
vi dist;
int c, e, l, p;
int test = 1;

int reverse (int i) {
	int r = 0;
	
	while(i) {
        r = r*10 + (i%10);
        i/=10;
    }
	
	return r;
}

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
				if (dist[adj[vertice][i]] <= p) {
					visited.pb(adj[vertice][i]);
				}
			}
		}
	}
}

int main(){		
	
	scanf("%d%d%d%d", &c, &e, &l, &p);
	
	while (c || e || l || p) {

		for (int i = 0; i < MAX; i++) {
			dist.pb(MAX);
			adj[i].clear();
		}
		
		for (int i = 0; i < e; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		
		bfs(l);		
		sort(visited.begin(), visited.end());

		printf("Teste %d\n", test++);
		for (int i = 0; i < (int) visited.size(); i++) {
			printf("%d ", visited[i]);
			
		}
		printf("\n\n");
		
		dist.clear();
		visited.clear();
		
		scanf("%d%d%d%d", &c, &e, &l, &p);
		
	}
 
	return 0;
}
