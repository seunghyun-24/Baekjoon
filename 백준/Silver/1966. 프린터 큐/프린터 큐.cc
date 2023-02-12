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

int main() {
    init();

    int c, N, M, tmp, check = 0; cin >> c;
    while(c--){
        cin >> N >> M;
        queue<pii> p;
        priority_queue<int> pq;
        for(int i = 0; i < N; i++){
            cin >> tmp;
            p.push({i, tmp});
            pq.push(tmp);
        }
        int k = 1;
        while(!p.empty()){
            if(p.front().second == pq.top()){
                if(M == p.front().first){
                    cout << k << '\n';
                }
                p.pop(); pq.pop(); k++;
            }
            else{
                pii b = p.front();
                p.pop();
                p.push(b);
            }
        }
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