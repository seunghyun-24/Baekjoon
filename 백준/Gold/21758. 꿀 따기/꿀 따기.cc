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

#define MAX 100001

int Honey[MAX];
int Sum[MAX];
int ans = 0;

int main() {
    init();

    int n =0;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> Honey[i];
        Sum[i] = Sum[i-1]+Honey[i];
    }

    //벌-꿀통-벌
    for (int i = 2; i < n; i++) {
        int honey = (Sum[i] - Sum[1]) + (Sum[n - 1] - Sum[i - 1]);
        ans = max(ans, honey);
    }

    //꿀통 젤 우측에!
    for (int i = 2; i < n; i++) {
        int bee = (Sum[n] - Sum[1] - Honey[i]) + (Sum[n] - Sum[i]);
        ans = max(ans, bee);
    }

    //꿀통 젤 좌측에! 
    for (int i = 2; i < n; i++) {
        int bee = (Sum[n - 1] - Honey[i]) + Sum[i - 1];
        ans = max(ans, bee);
    }
    
    cout << ans;

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