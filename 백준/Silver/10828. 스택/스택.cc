#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

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

    int N, a;
    string s;
    vector<int> v;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> s;
        if(s == "push") {
            cin >> a;
            v.push_back(a);
        }
        else if(s == "top") {
            if(v.empty()) cout << "-1" << "\n";
            else cout << v.back() << "\n";
        }
        else if(s == "size") cout << v.size() << "\n";
        else if(s == "pop"){
            if (v.empty()) cout << "-1" << "\n";
            else {
                cout << v.back() << "\n";
                v.pop_back();
            }
        }
        else if(s == "empty"){
            if(v.empty()) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
    }

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