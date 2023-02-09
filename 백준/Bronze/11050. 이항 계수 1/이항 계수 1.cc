#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

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

    int N, K;
    cin >> N >> K;

    int ans = 1;
    for(int i = 1; i <= K; i++) {
        ans *= N;
        N--;
    }
    for(int i = K; i > 0; i--){
        ans = ans/i;
    }

    cout << ans;

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