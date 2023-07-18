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

int N, M, K, S, D;
vector<pii> adj[1001];
int dist[1001][1001];
vector<pair<ll, int>> tryDist;

void Dist();

void dijkstra() {

    priority_queue<pair<int, pii>> pq;
    pq.push({0, {S, 0}});
    dist[1][1] = 0;

    while (!pq.empty()) {
        pair<int, pii> cur = pq.top();
        pq.pop();

        int pathNum = -cur.first;
        int curN = cur.second.first;
        int curP = cur.second.second;

        if (curP == N) continue;

        if (dist[curN][curP] >= pathNum) {
            for (int i = 0; i < adj[curN].size(); i++) {
                int nextNode = adj[curN][i].first;
                int newDist = pathNum + adj[curN][i].second;

                if (dist[nextNode][curP + 1] > newDist) {
                    dist[nextNode][curP + 1] = newDist;
                    pq.push({-newDist, {nextNode, curP + 1 } });
                }
            }
        }
    }
}

int main() {
    init();

    cin >> N >> M >> K;
    cin >> S >> D;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dist[i][j] = INF;
        }
    }

    int a, b, w;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> w;
        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
    }

    dijkstra();

    int minPath = N, shortPath = INF;

    for(int i = 1; i <= N; i++){
        if (dist[D][i] == INF) continue;
        if (dist[D][i] < shortPath) {
            shortPath = dist[D][i];
            minPath = i;
        }
    }
    cout << shortPath << '\n';

    for(int i = 1; i <= minPath; i++){
        if (dist[D][i] == INF) continue;
        tryDist.push_back({dist[D][i], i});
    }

    ll result = INFLL;
    for(int i = 0; i < K; i++){
        int p;
        cin >> p;

        for (int j = 0; j < tryDist.size(); j++) {
            tryDist[j].first += (p * tryDist[j].second);
            result = min(result, tryDist[j].first);
        }

        cout << result << '\n';
        result = INFLL;

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