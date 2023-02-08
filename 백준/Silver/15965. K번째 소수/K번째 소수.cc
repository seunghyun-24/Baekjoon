#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

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

int main() {
    init();
    int k, n; cin >> k;
    n = k * 30;
    bool isPrime[n];
    memset(isPrime, true, sizeof(isPrime));
    vector<int> prime;

    for(int i = 2; i<=n; i++){
        if(isPrime[i]){
            prime.push_back(i);
        }
        for(int j = 2*i; j<=n; j+=i){
            isPrime[j] = false;
        }
    }
    cout << prime[k-1];
}

bool isPrime(long num){
    if(num==0 || num == 1) return false;
    for(int i = 2; i*i <= num; i++){
        if(num%i == 0) return false;
    }
    return true;
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