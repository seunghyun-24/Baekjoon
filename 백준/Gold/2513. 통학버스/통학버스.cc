#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
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

int n, k, s;

int calc(vector<pii>& ret_v){

    int len_sum =0, left_sit =k;
    int apt_idx =0, farthest_len =0;

    while(apt_idx < ret_v.size()){
        if(left_sit > 0)
            farthest_len = max(farthest_len, ret_v[apt_idx].first);

        if(left_sit > ret_v[apt_idx].second){
            left_sit -= ret_v[apt_idx].second;
            ret_v[apt_idx].second=0;
            ++apt_idx;
        }
        else if(left_sit < ret_v[apt_idx].second){
            ret_v[apt_idx].second -= left_sit;
            left_sit=0;
        }
        else{
            ret_v[apt_idx].second=0;
            left_sit=0;
            ++apt_idx;
        }

        if(left_sit == 0 || apt_idx >= ret_v.size()){
            len_sum += 2*farthest_len;
            farthest_len= 0;
            left_sit = k;
        }
    }
    return len_sum;
}

int main() {

    init();

    vector<pii> path, left_v, right_v;

    int pos, num;

    cin >> n >> k >> s;

    for(int i=0; i < n; i++){
        cin >> pos >> num;
        path.push_back(make_pair(pos, num));
    }

    for(auto k = path.begin(); k < path.end(); k++){
        if(k->first < s)
            left_v.push_back(make_pair(abs(s - k->first), k->second));
        else
            right_v.push_back(make_pair(abs(s - k->first), k->second));
    }

    sort(left_v.begin(), left_v.end(), greater());
    sort(right_v.begin(), right_v.end(), greater());

    cout << (calc(left_v) + calc(right_v)) << '\n';

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