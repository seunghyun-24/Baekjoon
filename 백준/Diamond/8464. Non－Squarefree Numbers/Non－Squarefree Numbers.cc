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

    vector<ll> mobiusValue(1000001,1);
    
    for(ll i = 2; i*i < 1000001; i++){
        if(mobiusValue[i]==1){
            for(ll j = i; j < 1000001; j+=i)
                mobiusValue[j] *= -i;
            for(ll j = i*i; j < 1000001; j+=i*i)
                mobiusValue[j] = 0;
        }
    }

    for(ll i = 2; i < 1000001; i++){
        if (mobiusValue[i] == i) mobiusValue[i] = 1;
        else if (mobiusValue[i] == -i) mobiusValue[i] = -1;
        else if (mobiusValue[i] < 0) mobiusValue[i] = 1;
        else if (mobiusValue[i] > 0) mobiusValue[i] = -1;
    }

    ll st = 0;
    ll ed = 200000000000;

    while(st+1 < ed){
        ll mid = (st+ed)/2;
        ll chk = 0;

        for(ll i = 1; i*i <= mid; i++) {
            chk += (mobiusValue[i] * mid / (i * i));
        }

        if(mid - chk < K) st = mid;
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