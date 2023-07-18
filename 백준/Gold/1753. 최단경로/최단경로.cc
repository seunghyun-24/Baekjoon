#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define lll __int128_t
#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>

using namespace std;
void init();

struct cmp {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};

int main(){
    init();

    int V, E, K;
    vector<vector<pii>> adj(20001, vector<pii>());
    priority_queue<pii, vector<pii>, cmp> pq; // 노드, 총 거리
    vector<int> dist(20001, INF);

    cin >> V >> E;
    cin >> K;

    int u, v, w;
    for(int i=0; i<E; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v,w);
    }

    pq.emplace(K, 0);

    while(!pq.empty()){
        auto [node, totalCost] = pq.top();
        pq.pop();

        if(dist[node] != INF) continue;
        dist[node] = totalCost;

        for(auto [nextNode, nextCost] : adj[node]) {
            pq.emplace(nextNode, totalCost + nextCost);
        }
    }

    for(int i = 1; i <= V; i++){
        cout << ((dist[i] == INF) ? "INF" : to_string(dist[i]))<< "\n";
    }

    return 0;
}

void init() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}