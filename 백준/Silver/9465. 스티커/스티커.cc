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

int Max(int a, int b) {
    return a > b ? a : b;
}

int main() {

    init();
    int t, n, i, j;
    cin >> t;

    for(int k = 0; k < t; k++){
        cin >> n;
        int d[2][100001], a[2][100001];

        for (i = 0; i < 2; i++){
            for (j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }

        d[0][0] = d[1][0] = 0;
        d[0][1] = a[0][1];
        d[1][1] = a[1][1];

        for (i = 2; i <= n; i++){
            d[0][i] = Max(d[1][i - 1], d[1][i - 2]) + a[0][i];
            d[1][i] = Max(d[0][i - 1], d[0][i - 2]) + a[1][i];
        }

        cout << Max(d[0][n], d[1][n]) << "\n";
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