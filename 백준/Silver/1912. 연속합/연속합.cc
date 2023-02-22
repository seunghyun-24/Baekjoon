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

int main(){
    init();
    int n, a = 0;
    vector<int> num;
    vector<int> sum;

    cin >> n;
    sum.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        num.push_back(a);
    }

    int max = num[0];
    sum[0] = num[0];

    for(int i=1; i<n; i++){
        sum[i] = (sum[i-1]+num[i] >= num[i]) ? sum[i-1]+num[i] : num[i];
        max = sum[i] > max ? sum[i] : max;
    }

    cout << max;
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