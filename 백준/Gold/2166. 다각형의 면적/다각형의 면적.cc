#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

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

int n;
vector<pii> v;
double ans;

ll outer_product(pair<ll, ll> x, pair<ll, ll> y){
    return x.first * y.second - x.second * y.first;
}

int main() {
    init();
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }


    for (int i = 1; i < n - 1; ++i) {
        ans += (outer_product({v[i].first - v[0].first, v[i].second - v[0].second},
                                       {v[i + 1].first - v[0].first, v[i + 1].second - v[0].second}) / 2.0);
    }

    printf("%.1lf", abs(ans));
    //cout << abs(ans);
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