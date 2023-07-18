#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define lll __int128_t
#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>

using namespace std;
void init();

bool isIn(pii now, int row, int col){
    return (now.first >= 0 and now.second >= 0 and now.first < row and now.second < col);
}

int n;
string tempStr;
vector<vector<int>> room(51, vector<int>(51, 0));
vector<vector<int>> crashNum(51, vector<int>(51, INF));
int mv[5] = {0, 1, 0, -1, 0};

void search(){
    queue<pii> q;
    q.push({0,0});
    crashNum[0][0] = 0;

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int nx = x + mv[i];
            int ny = y + mv[i+1];

            if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                if (room[nx][ny] == 1){
                    if (crashNum[nx][ny] > crashNum[x][y]){
                        crashNum[nx][ny] = crashNum[x][y];
                        q.push({nx, ny});
                    }
                }
                else{
                    if (crashNum[nx][ny] > crashNum[x][y] + 1){
                        crashNum[nx][ny] = crashNum[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

    }

}

int main() {
    init();

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tempStr;
        for(int j = 0; j < n; j++) room[i][j] = (tempStr[j] == '1' ? 1 : 0);
    }

    search();
    cout << crashNum[n - 1][n - 1];
}

void init() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}