#include <iostream>
#include <algorithm>

using namespace std;
void init();

int house[1001][3];

int main() {
    init();

    int n;
    cin >> n;

    int cost[3];
    house[0][0] = house[0][1] = house[0][2] = 0;

    for(int i = 1; i<=n; i++){
        cin >> cost[0] >> cost[1] >> cost[2];
        house[i][0] = min(house[i-1][1], house[i-1][2]) + cost[0];
        house[i][1] = min(house[i-1][0], house[i-1][2]) + cost[1];
        house[i][2] = min(house[i-1][0], house[i-1][1]) + cost[2];
    }

    cout << min(min(house[n][0], house[n][1]), house[n][2]);

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


