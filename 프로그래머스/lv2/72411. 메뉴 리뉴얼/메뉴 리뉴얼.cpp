#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto &order: orders) sort(order.begin(), order.end());
    
    for(auto c: course) {
        map<string, int> m;
        for(auto order: orders) {
            if(order.length() > c) {
                vector<bool> comb(order.length()-c, false);
                for(int i=0; i<c; ++i) comb.push_back(true);
                
                do {
                    string temp = "";
                    for(int i=0; i<order.length(); ++i) {
                        if(comb[i]) temp += order[i];
                    }
                    m[temp]++;
                } while(next_permutation(comb.begin(), comb.end()));
            }
            else if(order.length() == c) m[order]++;
        }
        
        int max_val = max_element(m.begin(), m.end(), [] (const pair<string, int> &a, const pair<string, int> &b) { return a.second < b.second; })->second;
        
        if(max_val < 2) continue;
        
        for(auto k : m) {
            if(k.second == max_val) {
                answer.push_back(k.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}