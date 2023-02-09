#include <iostream>
#include <algorithm>
#include <map>

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

    ll N, k = 0;
    pair<ll, int> q = {0, 0};
    map<ll, int> m;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> k;
        m[k]++;
    }

    for(auto a: m) if (a.second > q.second) {q.first = a.first; q.second = a.second;}

    cout << q.first;
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