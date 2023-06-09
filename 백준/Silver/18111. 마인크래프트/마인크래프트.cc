#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

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

int main() {
    init();

    int n, m, b;
    int map[500][500];
    int leastTime = 0x7f7f7f7f;
    int mostHeight;

    cin >> n >> m >> b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    for (int h = 0; h <= 256; h++) {
        int build = 0;
        int remove = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int height = map[i][j] - h;
                if (height > 0) remove += height;
                else if (height < 0) build -= height;
            }
        }

        if (remove + b >= build) {
            int time = remove * 2 + build;
            if (leastTime >= time) {
                leastTime = time;
                mostHeight = h;
            }
        }
    }
    cout << leastTime << ' ' << mostHeight <<'\n';
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