#include <bits/stdc++.h>
#include <string>

#define ll long long int
#define ull unsigned long long int
#define lll __int128_t
#define ld long double
#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define all(x) (x).begin(), (x).end()
#define MOD (INF + 7)

using namespace std;
void init();


int main() {
    init();
    int num; cin >> num;
    vector<int> v(num, 0);
    v[0] = 1;
    v[1] = 3;
    for(int i = 2; i < num; i++){
        v[i] = (v[i-1] + 2 * v[i-2])%10007;
    }
    cout << v[num-1];
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