#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define lll __int128_t
#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>

using namespace std;

void init();

int main() {
    init();

    int testCase, k = 0;
    ll gal[2501] = {0, };
    ll a = INF + 7;

    gal[0] = gal[1] = 1;

    for(int i = 2; i<=2500; i++){
        for(int j = 0; j<i; j++){
            gal[i] += gal[j] * gal[i-j-1];
            gal[i] = (((gal[i] % a) + a) % a);
        }
    }

    cin >> testCase;
    for(int i = 0; i<testCase; i++){
        cin >> k;
        cout << ((k&1) ? 0 : gal[k >> 1]) << '\n';
    }

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