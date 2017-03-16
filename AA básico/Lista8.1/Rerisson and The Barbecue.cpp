#include <bits/stdc++.h>

using namespace std;

#define MAX 1001
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define pb push_back

int n, g;
map<string, vs> adj;
map<string, int> dist;
unordered_set<string> invited;
vs invited_list;

void bfs(string vertice) {
	queue<string> q;

	q.push(vertice);
	dist[vertice] = 0;
 
	while (!q.empty()) {
		vertice = q.front();
		q.pop();
 
		for (int i = 0; i < (int) adj[vertice].size(); i++) {
			
			if (dist[adj[vertice][i]] > dist[vertice] + 1) {
				dist[adj[vertice][i]] = dist[vertice] + 1;
				q.push(adj[vertice][i]);
				if (dist[adj[vertice][i]] <= g && invited.find(adj[vertice][i]) == invited.end()) {
					invited_list.pb(adj[vertice][i]);
					//printf("ok\n");
				}
			}
		}
	}
}

int main () {
	string s, t;
	
	scanf("%d%d", &n, &g);
	
	for (int i = 0; i < n; i++) {
		cin.ignore();
		cin >> s >> t;
		adj[s].pb(t);
		adj[t].pb(s);
		dist[s] = MAX;
		dist[t] = MAX;
	}
	
	bfs("Rerisson");
	sort(invited_list.begin(), invited_list.end());
	
	printf("%d\n", invited_list.size());
	for (int i = 0; i < (int) invited_list.size(); i++) {
		printf("%s\n", invited_list[i].c_str());
	}
	
	return 0;
}
