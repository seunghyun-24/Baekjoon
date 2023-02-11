#include <iostream>
#include <algorithm>
#include <queue>
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

    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int tmp;
    for(int i = 0; i<n*n; i++){
        cin >> tmp;
        pq.push(tmp);
        if(pq.size() > n) pq.pop();
    }
    cout << pq.top();


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