#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

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

int n, r, c;
int ans;

void Z(int y, int x, int size){

    if (y == r && x == c){
        cout << ans << '\n';
        return;
    }

    if (r < y + size && r >= y && c < x + size && c >= x) {
        Z(y, x, size / 2);
        Z(y, x + size / 2, size / 2);
        Z(y + size / 2, x, size / 2);
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else ans += size * size;

}

int main() {
    init();
    cin >> n >> r >> c;
    Z(0, 0, (1 << n));

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