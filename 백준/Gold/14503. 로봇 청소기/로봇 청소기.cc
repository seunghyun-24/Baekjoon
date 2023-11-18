#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define lll __int128_t
#define ld long double
#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define all(x) (x).begin(), (x).end()
#define MOD (INF + 7)

using namespace std;
void init();

int mv[5] = {-1, 0, 1, 0, -1};
void dfs(int r, int c, int d, int sum, int n, int m, vector<vector<int>>& room, vector<vector<int>>& visited){
    for(int i = 0; i < 4; i++){
        int nd = (d + 3 - i) % 4; //90도 반시계 방향 회전
        int nr = r + mv[nd];
        int nc = c + mv[nd+1];

        if(nr < 0 || nc < 0 || nr >= n || nc >= m || room[nr][nc] == 1) continue;

        if(visited[nr][nc] == 0){
            visited[nr][nc] = 1;
            dfs(nr, nc, nd, sum+1, n, m, room, visited);
        }
    }

    int backd = (d + 2) % 4;
    int backr = r + mv[backd];
    int backc = c + mv[backd + 1];
    if(0 <= backr && 0 <= backc &&  backr <= n && backc <= m){
        if(room[backr][backc] == 0) dfs(backr, backc, d, sum, n, m, room, visited);

        else{
            cout << sum;
            exit(0);
        }
    }

}


int main() {
    init();

    int n, m; cin >> n >> m;
    int r, c, d; cin >> r >> c >> d;

    vector<vector<int>> room(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> room[i][j];
            visited[i][j] = 0;
        }
    }
    visited[r][c] = 1;
    dfs(r, c, d, 1, n, m, room, visited);

    return 0;
}

void init() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt+", stdin);
    freopen("output.txt", "wt+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}