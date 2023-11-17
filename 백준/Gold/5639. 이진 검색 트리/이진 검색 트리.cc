#include <bits/stdc++.h>
#include <string>

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

void postOrder(vector<int>& v, int st, int ed){
    if(st >= ed) return;
    if(st == ed-1){
        cout << v[st] << '\n';
        return;
    }
    int new_st = st+1;
    while(new_st < ed){
        if(v[st] < v[new_st]) break;
        new_st++;
    }
    postOrder(v, st+1, new_st);
    postOrder(v, new_st, ed);
    cout << v[st] << '\n';

}

int main(){
    init();
    vector<int> v; int a;
    while(cin >> a){
        v.push_back(a);
    }
    postOrder(v, 0, v.size());
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