#include <string>
#include <vector>

using namespace std;

#define ll long long

int solution(int n) {
    int answer = 0;
    vector<ll> dp(n);
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2; i < n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%1'000'000'007;
        
    }
    return dp[n-1];
}