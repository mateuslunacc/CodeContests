

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int m, n, walls = 0;
	int rows[1001], columns[1001];
	char cells[1001][1001];
	int ans[2] = {-1, -1};
	bool found = false;
	
	cin >> m >> n;

	memset(rows, 0, sizeof(rows));
	memset(columns, 0, sizeof(columns));

	for (int i = 0; i < m; i++) {
		
		for (int j = 0; j < n; j++) {
			char cell;
			cin >> cell;
			if (cell == '*') {
				walls++;
				rows[i]++;
				columns[j]++;
			}
			cells[i][j] = cell;

		}
	}

	for (int i = 0; i < m && !found; i++) {
		
		for (int j = 0; j < n && !found; j++) {
			int mod = cells[i][j] == '*'? -1 : 0;
			if ((rows[i] + columns[j] + mod) == walls) {
				ans[0] = i;
				ans[1] = j;
				//cout <<"i: " <<i<<" j: "<<j<<endl;
				found = true;
			} 
		}
	}

	if (ans[0] == -1) {
		cout << "NO\n";
	} else {
		cout << "YES\n" << ++ans[0] << " " << ++ans[1] << endl;
	}

	
	return 0;
}
