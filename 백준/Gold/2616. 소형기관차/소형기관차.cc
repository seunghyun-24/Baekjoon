#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define lll __int128_t
#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>

using namespace std;

void init();

int main() {
    init();

    int trainNum =0, possibleNum=0;
    int train[50001] ={0, }, sum[50001] = {0, };
    int smallTrain[4][50001];

    cin >> trainNum;
    for(int i =1; i<=trainNum; i++){
        cin >> train[i];
        sum[i] = sum[i-1] + train[i];
    }
    cin >> possibleNum;

    for(int i = 1; i<=3; i++){
        for(int j = i*possibleNum; j<=trainNum; j++){
            smallTrain[i][j] = max(smallTrain[i][j-1], smallTrain[i-1][j-possibleNum]+(sum[j]-sum[j-possibleNum]));
        }
    }

    cout << smallTrain[3][trainNum];

    return 0;
}

void init() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}