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

template<typename T> class FIELD {
private:
    vector<vector<T>> field;
public:
    T getPositoin(pii pos) {
        return this->field[pos.first][pos.second];
    }

    T getPositoin(int x, int y) {
        return this->field[x][y];
    }

    void setPositoin(pii pos, T val) {
        this->field[pos.first][pos.second] = val;
    }

    void setPositoin(int x, int y, T val) {
        this->field[x][y] = val;
    }

    pii size() {
        return {this->field.size(), this->field[0].size()};
    }

    void resize(int row, int column) {
        this->field.resize(row, vector<T>(column));
    }

    void assign(int row, int column, T val) {
        this->field.assign(row, vector<T>(column, val));
    }
};

struct UNIT {
    int x, y, weight;

    bool operator()(struct UNIT a, struct UNIT b) {
        return a.weight > b.weight;
    }
};

pii operator+(pii a, pii b) {
    return {a.first + b.first, a.second + b.second};
}

bool isIn(pii pos, int row, int column) {
    return (pos.first >= 0 && pos.second >= 0 && pos.first < row and pos.second < column);
}

void dijkstraSpreading(FIELD<int>& mountain, FIELD<int>& DP, FIELD<bool>& visited, int maxDiff) {
    priority_queue<UNIT, vector<UNIT>, UNIT> pq;
    int moving[] = {0, 1, 0, -1, 0};
    int i, row, column, cost;
    pii current, next;

    tie(row, column) = mountain.size();

    pq.push({0, 0, 0});
    while(not pq.empty()) {
        current = {pq.top().x, pq.top().y};
        cost = pq.top().weight;
        pq.pop();

        if(cost >= DP.getPositoin(current)) continue;

        DP.setPositoin(current, cost);
        visited.setPositoin(current, true);

        for(i = 0; i < 4; i++) {
            next = current + make_pair(moving[i], moving[i + 1]);
            if(not isIn(next, row, column)) continue;

            cost = mountain.getPositoin(next) - mountain.getPositoin(current);
            if(abs(cost) > maxDiff) continue;

            if(cost > 0) cost *= cost;
            else cost = 1;

            pq.push({next.first, next.second, DP.getPositoin(current) + cost});
        }
    }
}

int dijkstraReturn(FIELD<int>& mountain, pii startPos, int maxDiff) {
    priority_queue<UNIT, vector<UNIT>, UNIT> pq;
    FIELD<int> DP;
    int moving[] = {0, 1, 0, -1, 0};
    int i, row, column, cost;
    pii current, next;

    tie(row, column) = mountain.size();
    DP.assign(row, column, INF);

    pq.push({startPos.first, startPos.second, 0});
    while(not pq.empty()) {
        current = {pq.top().x, pq.top().y};
        cost = pq.top().weight;
        pq.pop();

        if(cost >= DP.getPositoin(current)) continue;
        DP.setPositoin(current, cost);

        for(i = 0; i < 4; i++) {
            next = current + make_pair(moving[i], moving[i + 1]);

            if(not isIn(next, row, column)) continue;

            cost = mountain.getPositoin(next) - mountain.getPositoin(current);
            if(abs(cost) > maxDiff) continue;

            if(cost > 0) cost *= cost;
            else cost = 1;

            pq.push({next.first, next.second, DP.getPositoin(current) + cost});
        }
    }

    return DP.getPositoin({0, 0});
}

int main() {
    init();

    int row, column, maxDiff, moveTime, i, j, temp, answer = 0;
    FIELD<int> mountain, DP;
    FIELD<bool> visited;
    string inputStr;

    cin >> row >> column >> maxDiff >> moveTime;
    mountain.resize(row, column);
    DP.assign(row, column, INF);
    visited.assign(row, column, false);

    for(i = 0; i < row; i++) {
        cin >> inputStr;
        for(j = 0; j < column; j++) {
            temp = (isupper(inputStr[j]) ? inputStr[j] - 'A' : inputStr[j] - 'a' + 26);
            mountain.setPositoin(i, j, temp);
        }
    }

    dijkstraSpreading(mountain, DP, visited, maxDiff);

    for(i = 0; i < row; i++) {
        for(j = 0; j < column; j++) {
            if(DP.getPositoin(i, j) < moveTime) {
                temp = dijkstraReturn(mountain, {i, j}, maxDiff);
                temp += DP.getPositoin(i, j);
                if(temp > moveTime) continue;
                answer = max(answer, mountain.getPositoin(i, j));
            }
        }
    }

    cout << answer;

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