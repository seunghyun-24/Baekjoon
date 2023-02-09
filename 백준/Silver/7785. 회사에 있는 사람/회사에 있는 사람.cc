#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

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

    int P; cin >> P;
    set<string> c;

    string name;
    string log;

    for(int i = 0; i < P; i++){
        cin >> name >> log;
        if(log == "enter") c.insert(name);
        else c.erase(name);
    }

    for(auto k = c.rbegin(); k!=c.rend(); k++){
        cout << *k << "\n";
    };

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