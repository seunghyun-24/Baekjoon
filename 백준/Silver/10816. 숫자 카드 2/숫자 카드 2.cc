#include <iostream>
#include <algorithm>
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

int main() {
    init();

    int N, M = 0;
    ll k = 0;
    vector<ll> v1;
    cin >> N;
    for(int i =0; i<N; i++){
        cin >> k;
        v1.push_back(k);
    }
    sort(v1.begin(), v1.end());
    cin >> M;
    for(int i =0; i<M; i++){
        cin >> k;

        auto l = lower_bound(v1.begin(), v1.end(), k);
        auto u = upper_bound(v1.begin(), v1.end(), k);

        cout << (int)(u - l) << ' ';
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