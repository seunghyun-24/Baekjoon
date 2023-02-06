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

queue<pii> q;
vector<vector<int>> map;
pii src, dst;
pii mov[8] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
               {1, 2}, {2, 1}, {2, -1}, {1, -2} };
void init();

void search(int size){
    map[src.first][src.second] = 1;
    q.push(src);
    while(!q.empty()){
        pii a = q.front();
        q.pop();
        for(int i = 0; i<8; i++){
            int f, s;
            f = a.first + mov[i].first;
            s = a.second + mov[i].second;
            if(f >=0 && s>=0 && f < size && s < size){
                if(!map[f][s]){
                    map[f][s] = map[a.first][a.second] + 1;
                    q.push(pii(f, s));
                }
            }
        }

    }
}

int main() {
    init();

    int testCase, size;
    cin >> testCase;

    for(int i = 0; i<testCase; i++) {
        cin >> size;
        map.assign(size, vector<int>(size));
        cin >> src.first >> src.second >> dst.first >> dst.second;
        search(size);
        cout << map[dst.first][dst.second] - 1 << '\n';
    }
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