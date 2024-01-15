#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int board[1002][1002];
int dist[1002][1002];
int mv[5] = { 0, 1, 0, -1, 0 };

queue<pair<int, int>> q;

void init();

int main() {
    
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = -1;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				q.push({i, j});
				dist[i][j] = 0;
			}
		}
	}
	
	while (!q.empty()) {
	    
		auto cur = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			
			int nx = cur.first + mv[i];
			int ny = cur.second + mv[i+1];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			
			if (dist[nx][ny] != -1) continue;
			if (board[nx][ny] == 0) continue;
			
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({nx, ny});
		}
	}

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}

void init() {
    ios::sync_with_stdio(0);
	cin.tie(0);
}