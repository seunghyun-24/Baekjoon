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

vector<int> task;
int cache[5][5][100000];

int move(int from, int to){
    if(from == to) return 1;

    switch(from){
        case 0: return 2;
        case 1: return to == 3 ? 4 : 3;
        case 2: return to == 4 ? 4 : 3;
        case 3: return to == 1 ? 4 : 3;
        case 4: return to == 2 ? 4 : 3;
    }
}

int solve(int l, int r, int n){
    if(n == task.size()) return 0;
    else if(cache[l][r][n]) return cache[l][r][n];
    else return cache[l][r][n] = min(move(l,task[n])+solve(task[n],r,n+1),
                  move(r,task[n])+solve(l,task[n],n+1));
}

int main() {
    init();

    int k = 0;
    cin >> k;

    while(k!=0){
        task.push_back(k);
        cin >> k;
    }

    cout << solve(0,0,0);

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