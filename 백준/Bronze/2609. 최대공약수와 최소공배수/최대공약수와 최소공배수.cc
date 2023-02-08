#include <iostream>
#include <algorithm>
#include <vector>
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

int arr1[10001] = {0, };
int arr2[10001] = {0, };
int maxi[10001] = {0, };
int mini[10001] = {0, };

int gcd (int a, int b){
    int c;
    while(b!=0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main(void) {
    init();

    int a, b, x, y;
    cin >> a >> b;

    x = gcd(a,b);
    y = a*b / x;

    cout << x << "\n" << y;


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