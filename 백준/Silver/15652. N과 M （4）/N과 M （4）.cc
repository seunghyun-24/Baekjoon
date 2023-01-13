#include <iostream>

using namespace std;
void init();
int n, m;

int arr[9] = {0,};
bool visited[9] = {0,};

void dfs(int num, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = num; i <= n; i++) {
        visited[i] = true;
        arr[cnt] = i;
        dfs(i,cnt+1);
        visited[i] = false;
    }
}

int main() {
    init();
    cin >> n >> m;
    dfs(1,0);
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


