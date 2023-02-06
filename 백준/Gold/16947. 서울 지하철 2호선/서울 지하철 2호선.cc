#include <bits/stdc++.h>

using namespace std;

void init(void);

bool isVisited[3001];
bool isCycle[3001];
vector<int> graph[3001];
bool isFound;

void DFSFindCycle(int startStation, int currentStation, int cnt) {
    if(startStation == currentStation && cnt > 1) {
        isCycle[currentStation] = true;
        isFound = true;
        return;
    }

    isVisited[currentStation] = true;

    for(auto i : graph[currentStation]) {
        if (!isVisited[i]) DFSFindCycle(startStation, i, cnt + 1);
        else if (startStation == i && cnt > 1) DFSFindCycle(startStation, i, cnt);

        if (isFound) return;
    }

    return;
}

int BFSFindDistance(int startStation) {
    queue<pair<int, int>> q;
    int currentStation, currentCost;

    q.push({startStation, 0});
    isVisited[startStation] = true;

    while(!q.empty()) {
        currentStation = q.front().first;
        currentCost = q.front().second;
        isVisited[currentStation] = true;
        q.pop();

        for(auto i : graph[currentStation]) {
            if(isCycle[i]) return currentCost + 1;


            if(!isVisited[i]) {
                q.push({i, currentCost + 1});
                isVisited[i] = true;
            }
        }
    }
}

int main(void) {
    init();

    int stationNum, i, stationA, stationB;

    cin >> stationNum;

    for(i = 0; i < stationNum; i++) {
        cin >> stationA >> stationB;
        graph[stationA].push_back(stationB);
        graph[stationB].push_back(stationA);
    }

    for(i = 1; i <= stationNum; i++) {
        memset(isVisited + 1, false, stationNum);
        isFound = false;
        DFSFindCycle(i, i, 0);
    }

    for(i = 1; i <= stationNum; i++) {
        if(!isCycle[i - 1])memset(isVisited + 1, false, stationNum);
        if(isCycle[i]) cout << 0 << " ";
        else cout << BFSFindDistance(i) << " ";
    }

    return 0;
}

void init(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rb", stdin);
    freopen("output.txt", "wb", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}