
#include <stdio.h>
#include <algorithm>

using namespace std;

//int 10^5, ll 10^18
#define MAX 5005
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pb push_back

vi adj[MAX];
vi c[MAX];
bool vis[MAX];
int comp = 0;

void dfs(int node) {
	vis[node] = true;
	c[comp].pb(node);
	printf("begining DFS: %d\n", node);
	for (int neighbor = 0; neighbor < (int) adj[node].size(); neighbor++) {
		if (!vis[adj[node][neighbor]]) {
			dfs(adj[node][neighbor]);
		} else {
			printf("Loop in %d\n", adj[node][neighbor]);
		}
	}
	printf("finished DFS: %d\n", node);
}

int main(){
	int n = 1;
	int v, e;
	int v1, v2;
	
	for(int i = 0; i < MAX; i++) {
		vis[i] = false;
	}
	
	//scanf("%d", &n);
	
	while(n--) {
		scanf("%d%d", &v, &e);
		
		for(int i = 0; i < e; i++){
			scanf("%d%d", &v1, &v2);
			adj[v1].push_back(v2);
			adj[v2].push_back(v1);
		}
		
		for (int i = 1; i <= v; i++) {
			if (!vis[i]) {
				dfs(i);
				comp++;
			}
		}
		
		printf("%d\n", comp);
		
		for (int i = 0; i < MAX; i++) {
			adj[i].clear();
			vis[i] = false;
			c[i].clear();
		}
		comp = 0;
		
	}
	
	return 0;
}
