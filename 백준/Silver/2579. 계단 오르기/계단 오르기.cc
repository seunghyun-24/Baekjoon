#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

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

int n,stair[301];
int dp[301];

int Max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    init();
    int n;
    vector<int> stair, dp;

    cin >> n;
    stair.resize(n);
    dp.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> stair[i];
    }

    dp[0] = stair[0];
    dp[1] = Max(stair[0]+stair[1],stair[1]);
    dp[2] = Max(stair[0]+stair[2],stair[1]+stair[2]);

    for (int i = 3; i < n; i++) {
        dp[i] = Max(dp[i-2]+stair[i], stair[i-1]+stair[i]+dp[i-3]);
    }

    cout << dp[n - 1] << '\n';

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