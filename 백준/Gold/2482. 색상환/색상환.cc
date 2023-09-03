#include <bits/stdc++.h>
#include <iostream>
#define ll long long int
#define ull unsigned long long int
#define lll __int128_t
#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>

using namespace std;
void init();

int mod = 1'000'000'003;
int dp[1001][1001];

int main(){
    init();
    
    int N, K, ans = 0;
    
    cin >> N >> K;
    for (int i = 0; i <= N; i++){
        dp[i][1] = i;
        dp[i][0] = 1;
    }

    for (int i = 2; i <= N; i++){
        for (int j = 2; j <= K; j++){
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
        }
    }

    ans = (dp[N - 1][K] + dp[N - 3][K - 1]) % mod;
    cout << ans << "\n";

    return 0;
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