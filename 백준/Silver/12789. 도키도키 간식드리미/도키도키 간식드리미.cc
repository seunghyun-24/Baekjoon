#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main() {

    stack<int> w;
    queue<int> q;
    vector<int> v;
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }

    int now = 1;

    while (!q.empty()) {
        if (q.front() == now) {
            v.push_back(now);
            now++;
            q.pop();
        } 
        else if (!w.empty() && w.top() == now) {
            w.pop();
            v.push_back(now);
            now++;
        } 
        else {
            w.push(q.front());
            q.pop();
        }
    }

    while (!w.empty()) {
        v.push_back(w.top());
        w.pop();
    }

    bool possible = true;

    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] > v[i + 1]) {
            possible = false;
            break;
        }
    }
    
    if (possible) cout << "Nice";
    else cout << "Sad";


}
