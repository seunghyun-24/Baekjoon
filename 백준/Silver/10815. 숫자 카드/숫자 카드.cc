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

void ff(const int k, const vector<ll>& a){
    int left, right, mid;
    left = 0;
    right = a.size();
    while(left+1 < right){
        mid = (left + right) >> 1;
        if(a[mid] == k){
            cout << "1" << ' ';
            return;
        }
        else if(a[mid] > k) right = mid;
        else left = mid;
    }
    if(a[left] == k) cout << "1" << ' ';
    else cout << "0" << ' ';
    return;
}

int main() {
    init();

    int N, M, k = 0;
    vector<ll> v1;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> k;
        v1.push_back(k);
    }
    cin >> M;
    sort(v1.begin(), v1.end());

    for(int i = 0; i<M; i++){
        cin >> k;
        ff(k, v1);
    }

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