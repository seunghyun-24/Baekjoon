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

int main(){
    
    init();
    
    ll K;
    cin >> K;

    int mobiusValue[100001];
    mobiusValue[1] = 1;
    
    for(ll i = 1; i < 100001; i++){
        for(ll j = 2*i; j < 100001; j+=i){
            mobiusValue[j] -= mobiusValue[i];
        }
    }

    ll st = 0;
    ll ed = 10000000000;

    while(st+1 < ed){
        ll mid = (st+ed)/2;
        ll chk = 0;

        for(ll i = 1; i*i <= mid; i++) {
            chk += (mobiusValue[i] * (mid / (i * i)));
        }

        if(chk < K) st = mid;
        else ed = mid;
    }

    cout << ed << '\n';
    
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