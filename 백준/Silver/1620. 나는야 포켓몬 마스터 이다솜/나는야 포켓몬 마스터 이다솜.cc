#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

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

bool isDigit(const string& str){

    try{
        int digit = stoi(str);
        return true;
    }
    catch(exception &err){
        return false;
    }
}

int main() {
    init();
    int m, n;
    string name, finding;
    map<int,string> doGam;
    map<string, int> gamDo;

    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        cin >> name;
        doGam.insert({i, name});
        gamDo.insert({name, i});
    }

    for(int i = 0; i < n; i++){
        cin >> finding;

        if(isDigit(finding)) {
            int key = stoi(finding);
            cout << doGam[key] << '\n';
        }
        else {
            cout << gamDo[finding] << '\n';
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