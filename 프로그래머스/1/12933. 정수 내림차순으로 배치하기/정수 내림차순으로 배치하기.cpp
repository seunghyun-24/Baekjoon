#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string str = to_string(n);
    sort(str.begin(), str.end());
    
    long long answer = 0;
    int k = 1;
    for(int i = 0; i < str.size(); i++){
        answer += (str[i]-'0') * k;
        k *= 10;
    }
    return answer;
}