#include <vector>
#include <string>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for(int i = 1; i<s.length()/2+1; i++){
        int cscore = 1;
        int r_string = 0;
        string current_str = s.substr(0, i);
        int chk;
        for(int j = i; j<=s.length(); j+=i){
            if(current_str == s.substr(j, i)) cscore++;
            else{
                r_string += i;
                if(cscore != 1){
                    r_string += (log10(cscore))+1;
                }
                cscore = 1;
                current_str = s.substr(j, i);
                chk = j;
            }
        }

        if(s.length()%i != 0){
            r_string += s.length() - (s.length()/i)*i;
        }

        answer = r_string > answer ? answer : r_string;
    }
    return answer;
}