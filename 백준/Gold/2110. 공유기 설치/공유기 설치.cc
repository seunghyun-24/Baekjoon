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

bool isPossible(vector<ll>& houses, ll upper, ll wifi) {
    auto before = houses.begin();
    ll w = 1;

    for(auto k = houses.begin(); k!= houses.end(); k++){
        if(*k- *before >= upper){
            before = k;
            w++;
        }
    }
    return (w >= wifi);
}

int main() {
    init();

    ll n, wifi, left, right, mid = 0;
    vector<ll> houses;

    cin >> n >> wifi;
    houses.resize(n);
    for(auto& a : houses) cin >> a;

    sort(houses.begin(), houses.end());
    left = 0, right = houses.back() - houses.front() + 1;

    while(left + 1 < right) {
        mid = (left + right) >> 1;
        if(isPossible(houses, mid, wifi)) left = mid;
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