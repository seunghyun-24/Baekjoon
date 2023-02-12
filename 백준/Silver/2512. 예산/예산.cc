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

bool isPossible(vector<ll>& buckets, ll upper, ll total) {
    ll current = 0;
    for(auto& a : buckets) current += min(upper, a);

    return (current <= total);
}

int main() {
    init();

    ll countryNum, left, right, mid, totalBucket, bsum = 0;
    vector<ll> buckets;

    cin >> countryNum;
    buckets.resize(countryNum);
    for(auto& a : buckets) cin >> a;
    cin >> totalBucket;

    for(auto& a : buckets) bsum += a;
    if(bsum <= totalBucket) {
        cout << *max_element(buckets.begin(), buckets.end());
        return 0;
    }
    left = 0, right = INF;
    while(left + 1 < right) {
        mid = (left + right) >> 1;
        if(isPossible(buckets, mid, totalBucket)) left = mid;
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