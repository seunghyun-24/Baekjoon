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

int N, E;
int a, b, c, n1, n2;
vector<vector<pii>> graph(802); // (도달하는 곳, 거리)
int dist[803];

struct cmp {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};

void search(int pos){

    for (int i = 0; i <= N; i++) dist[i] = INF;
    priority_queue<pii, vector<pii>, cmp> pq;

    pq.push({0, pos}); //(움직인 거리, 현재 위치)
    dist[pos] = 0; // dist에 움직인 거리 update할 예정

    while(!pq.empty()){
        auto [curDist, curPos] = pq.top();
        pq.pop();

        if(dist[curPos] < curDist) continue;

        for(auto next : graph[curPos]){
            auto [nextNode, nextDist] = next;

            if(dist[nextNode] > curDist + nextDist){
                dist[nextNode] = curDist + nextDist;
                pq.push({dist[nextNode], nextNode});

            }
        }
    }
}

int main() {
    init();

    cin >> N >> E;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    cin >> n1 >> n2;

    search(1);
    int ston1 = dist[n1];
    int ston2 = dist[n2];

    search(n1);
    int n1ton2 = dist[n2];
    int n1tod = dist[N];

    search(n2);
    int n2tod = dist[N];

    int result;
    result = min(INF, ston1 + n1ton2 + n2tod);
    result = min(result, ston2 + n1ton2 + n1tod);

    if(result >= INF || n1ton2 == INF) cout << -1;
    else cout << result;

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