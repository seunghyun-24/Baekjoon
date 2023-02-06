#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long int
#define ull unsigned long long int
#define lll __int128_t
#define ld long double
#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define MOD (INF + 7)

using namespace std;

void init();
int mov[5] = {0, 1, 0, -1, 0};
struct info {int r, c, dist; };

void search(int size){

}

int main() {
    init();

    int t;
    int col, row; cin >> col >> row;
    vector<vector<int>> box;
    vector<vector<bool>> visited;
    box.assign(row, vector<int>(col));
    visited.assign(row, vector<bool>(col));

    queue<info> q;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cin >> box[i][j];
            if(box[i][j]==1) q.push( {i, j, 0});
        }
    }

    int max = 0;
    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        int dist = q.front().dist;
        if(dist>max) max = dist;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + mov[i];
            int nc = c + mov[i+1];

            if(nr < 0 || nc < 0 || nr >= row || nc >= col) continue;
            else if(visited[nr][nc]==true || box[nr][nc] != 0) continue;
            visited[nr][nc] = true;
            box[nr][nc] = 1;
            if(dist>=max) max = dist+1;
            q.push({nr, nc, dist+1});
        }
    }


    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if(box[i][j]==0) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << max;
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