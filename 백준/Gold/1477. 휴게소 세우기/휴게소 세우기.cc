#include <bits/stdc++.h>

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

int binary_search(vector<int> store_position, int M, int L){
    int left = 1, right = L-1;

    while (left <= right){
        int mid = (left+right)/2;
        int count = 0;
        for (int i = 1; i < store_position.size(); ++i) {
            int section = store_position[i]-store_position[i-1];

            count += section/mid;
            if(section%mid == 0) count--;
        }

        if(count > M) left = mid+1;
        else right = mid-1;
    }

    return left;
}

int main() {
    init();

    int N, M, L;
    cin >> N >> M >> L;

    vector<int> store_position(N+2);

    store_position[0] = 0;
    for (int i = 1; i <= N; ++i) cin >> store_position[i];
    store_position[N+1] = L;

    sort(store_position.begin(), store_position.end());

    cout << binary_search(store_position, M, L);

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