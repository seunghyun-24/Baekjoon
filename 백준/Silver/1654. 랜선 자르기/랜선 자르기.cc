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

bool isPossible(vector<ll>& len, ll upper, ll count, ll num) {
    for(auto &a : len) count += a / upper;

    return count >= num;
}

int main() {
    init();

    ll k, n, left, right, mid;
    vector<ll> lens;

    cin >> k >> n;
    lens.resize(k);
    for(auto& a : lens) cin >> a;

    sort(lens.begin(), lens.end());
    left = 0, right = lens.back() + 1;

    ll ans = 0;
    while(left + 1 < right) {
        mid = (left + right) >> 1;
        ll cnt = 0;
        if(isPossible(lens, mid, cnt, n)) left = mid;
        else right = mid;
    }

    cout << left;

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