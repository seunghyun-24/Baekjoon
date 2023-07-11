#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <string>

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



#define MAX_SIZE 100'001
int n, k;
bool visited[MAX_SIZE];

int bfs_pri(int N, int K){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,N});

    visited[N] = true;
    while (!pq.empty()) {
        int pos = pq.top().second;
        int time = pq.top().first;
        pq.pop();

        if(pos == K) return time;

        if (pos * 2 < MAX_SIZE && !visited[pos*2]) {
            pq.push({time, pos*2});
            visited[pos * 2] = true;
        }

        if (pos + 1 < MAX_SIZE && !visited[pos+1]) {
            pq.push({time+1, pos+1});
            visited[pos + 1] = true;
        }

        if (pos - 1 >= 0 && !visited[pos-1]) {
            pq.push({time+1, pos-1});
            visited[pos - 1] = true;
        }
    }
}

int main() {

    init();

    cin >> n >> k;
    cout << bfs_pri(n, k);

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