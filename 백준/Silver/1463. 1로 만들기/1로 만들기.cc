#include <iostream>
#include <queue>
#include <algorithm>

#define pii pair<int, int>

using namespace std;
void init();

int main() {
    init();

    pii current;
    queue<pii> q;

    int x;
    vector<int> num;

    cin >> x;
    q.push({x,0});

    num.resize(x+1);
    while(not q.empty()){

        current = q.front();
        q.pop();

        if(current.first == 1){
            cout << current.second;
            break;
        }
        if(current.first%3==0 and not num[current.first/3]) {
            q.push({current.first / 3, current.second + 1});
            num[current.first/3] = current.second+1;
        }
        if(current.first%2==0 and not num[current.first/2]) {
            q.push({current.first/2, current.second+1});
            num[current.first/2] = current.second+1;
        }
        if(current.first > 0 and not num[current.first-1]) {
            q.push({current.first-1, current.second+1});
            num[current.first-1] = current.second+1;
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


