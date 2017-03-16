#include <stdio.h>
#include <algorithm>

using namespace std;

//int 10^5, ll 10^18
#define MAX 26
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
	//printf("begining DFS: %d\n", node);
	for (int neighbor = 0; neighbor < (int) adj[node].size(); neighbor++) {
		if (!vis[adj[node][neighbor]]) {
			dfs(adj[node][neighbor]);
		}
	}
	//printf("finished DFS: %d\n", node);
}

int main(){
	int n, v, e;
	int cases = 0;
	char v1, v2;
	
	for(int i = 0; i < MAX; i++) {
		vis[i] = false;
	}
	
	scanf("%d", &n);
	
	while(n--) {
		scanf("%d%d", &v, &e);
		
		for(int i = 0; i < e; i++){
			scanf(" %c %c", &v1, &v2);
			adj[v1 - 'a'].push_back(v2 - 'a');
			adj[v2 - 'a'].push_back(v1 - 'a');
		}
		
		for (int i = 0; i < v; i++) {
			if (!vis[i]) {
				dfs(i);
				comp++;
			}
		}
		
		printf("Case #%d:\n", ++cases);
		for (int i = 0; i < comp; i++) {
			sort(c[i].begin(), c[i].end());
			for (int j = 0; j < (int) c[i].size(); j++) {
				printf("%c,", ((char) c[i][j] + 'a'));
			}
			printf("\n");
		}
		printf("%d connected components\n\n", comp);
		
		for (int i = 0; i < MAX; i++) {
			adj[i].clear();
			vis[i] = false;
			c[i].clear();
		}
		comp = 0;
		
	}
	
	
	return 0;
}
