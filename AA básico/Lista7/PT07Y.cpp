#include <stdio.h>
#include <algorithm>

using namespace std;

//int 10^5, ll 10^18
#define MAX 20002
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pb push_back

vi adj[MAX];
bool vis[MAX];
bool cycle = false;
int comp = 0;

void dfs(int node, int pai = -1) {
	vis[node] = true;

	//printf("begining DFS: %d\n", node);
	for (int neighbor = 0; neighbor < (int) adj[node].size(); neighbor++) {
		if (!vis[adj[node][neighbor]]) {
			dfs(adj[node][neighbor], node);
		} else if (adj[node][neighbor] != pai){
			//printf("Loop on %d\n", adj[node][neighbor]);
			cycle = true;
		}
	}
	//printf("finished DFS: %d\n", node);
}

int main(){
	int v, e;
	int v1, v2;
	
	for(int i = 0; i < MAX; i++) {
		vis[i] = false;
	}
	
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

	printf("%s\n", cycle || comp > 1? "NO" : "YES");
	
	return 0;
}
