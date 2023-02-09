#include <iostream>
#include <algorithm>
#include <set>
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

    int n, m, ans = 0;
    cin >> n >> m;
    set<string> s;
    string a;
    for(int i=0; i<n; i++) {
        cin >> a;
        s.insert(a);
    }
    for(int i=0; i<m; i++) {
        cin >> a;
        if(s.find(a) != s.end()) ans++;
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