#include <iostream>
#include <algorithm>
#include <stack>

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

    stack<char> s;
    string tmp;
    int ans = 0;

    cin >> tmp;
    for(int i = 0; i < tmp.length(); i++){
        if(tmp[i] == '(') s.push(tmp[i]);
        else if (tmp[i]== ')' && tmp[i-1]=='('){
            s.pop();
            ans+=s.size();
        }
        else {
            ans++; s.pop();
        }
    }

    cout << ans;
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